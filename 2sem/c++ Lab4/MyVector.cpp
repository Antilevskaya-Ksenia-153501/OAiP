#include <iostream>
#include <string>

template <class T> class MyVector
{
public:
	MyVector()
	{
		size = 0;
		capacity = 0;
		arr = nullptr;
	}

	MyVector(size_t temp_size)
	{
		size = temp_size;
		if (temp_size == 1)
			capacity = temp_size;
		else 
		{
			while (temp_size % 2 != 0)
				temp_size++;
			capacity = temp_size;
		}
		arr = temp_size ? new T[temp_size] : nullptr;
		if (arr)
		{
			for (int i = 0; i < size; i++)
			{
				arr[i] = T();
			}
		}
	}
	
	MyVector(size_t temp_size, const T& value) 
	{
		size = temp_size;
		if (temp_size == 1)
			capacity = temp_size;
		else
		{
			while (temp_size % 2 != 0)
				temp_size++;
			capacity = temp_size;
		}
		arr = temp_size ? new T[temp_size] : nullptr;
		if (arr)
		{
			for (int i = 0; i < size; i++)
			{
				arr[i] = T(value);
			}
		}
	}

	MyVector(const T* value, size_t temp_size)
	{
		size = temp_size;
		if (temp_size == 1)
			capacity = temp_size;
		else
		{
			while (temp_size % 2 != 0)
				temp_size++;
			capacity = temp_size;
		}
		arr = temp_size ? new T[temp_size] : nullptr;
		if (arr)
		{
			for (int i = 0; i < size; i++)
			{
				arr[i] = value[i];
			}
		}
	}

	MyVector(const MyVector& other)
	{
		size = other.size;
		capacity = other.capacity;
		arr = new T[other.size];
		for (int i = 0; i < other.size; i++)
			arr[i] = other.arr[i];
	}

	~MyVector()
	{
		if (size != 0)
		{
			size = 0;
			capacity = 0;

			if (!arr)
			{
				delete[] arr;
			}
			arr = nullptr;
		}
	}

	MyVector& operator= (const MyVector& other)
	{
		if (this == &other)
			return *this;
		this->~MyVector();
		arr = new T[other.size];
		for (int i = 0; i < other.size; i++)
			arr[i] = other.arr[i];
		this->size = other.size;
		this->capacity = other.capacity;
		return *this;
	}

	bool Empty() const
	{
		return (this->size == 0);
	}

	size_t Capacity() 
	{
		return this->capacity;
	}

	size_t Size()
	{
		return this->size;
	}

	size_t Max_Size() const 
	{
		return std::numeric_limits<size_t>::max();
	}

	T& operator[](int index)
	{
		return this->arr[index];
	}

	T& at(int index)
	{
		if (index < 0 || size <= index) 
			std::cout << "Out_of_range exception: position = " << index << std::endl;
		return this->arr[index];
	}

	T& Front() const
	{
		return this->arr[0];
	}

	T& Back()
	{
		return this->arr[size - 1];
	}

	T* Data()
	{
		return this->arr;
	}
	
	void Reserve(size_t n)
	{
		if (n <= capacity) return;
		T* temp = new T[n];
		for (int i = 0; i < size; ++i)
			temp[i] = arr[i];
		delete[] arr;
		arr = temp;
		capacity = n;
	}

	void Resize(size_t n, const T& value = T())
	{
		if (n > capacity)
			Reserve(n);
		for (int i = size; i < n; i++)
		{
			arr[i] = value;
		}
		size = n;
	}

	void Push_Back(const T& value)
	{
		if (capacity == 0)
		{
			capacity = 1;
			arr = new T[capacity];
		}
		if (capacity == size)
			Reserve(2 * size);
		arr[size] = value;
		++size;
	}

	void Pop_Back() 
	{
		--size;
		(arr + size)->~T();
	}

	void Clear()
	{
		for (int i = 0; i < size; i ++)
			(arr + i)->~T();
		size = 0;
	}

	void Swap(MyVector& other)
	{
		size_t temp_size = this->size;
		size_t temp_capacity = this->capacity;
		T* temp_arr = this->arr;

		this->size = other.size;
		this->capacity = other.capacity;
		this->arr = other.arr;

		other.size = temp_size;
		other.capacity = temp_capacity;
		other.arr = temp_arr;
	}

	class MyIterator;
	class const_MyIterator;
	class MyReverseIterator;
	class const_MyReverseIterator;

	template <class ... Args>
	void Emplace_Back(Args&& ... args)
	{
		if (capacity == size) 
		{
			capacity += 2;
			T* temp_arr = new T[capacity];
			memcpy(temp_arr, arr, size * sizeof(T));
			delete[] arr;
			arr = temp_arr;
		}
		arr[size] = std::move(T(std::forward<Args>(args) ...));
		++size;
	}
	
	template <class ... Args>
	MyIterator Emplace(const_MyIterator it, Args && ... args)
	{
		const_MyIterator find = Cbegin();
		int index = 0;
		for (int i = 0; i < size; i++)
		{
			if (it == find)
				break;
			index++;
			find++;
		}
		if (size == capacity)
		{
			capacity += 2;
			T* temp_arr = new T[capacity];
			memcpy(temp_arr, arr, size * sizeof(T));
			delete[] arr;
			arr = temp_arr;
		}
		MyIterator temp = &arr[index];
		memmove(temp.get() + 1, temp.get(), (size - index) * sizeof(T));
		(*temp) = std::move(T( std::forward<Args>(args) ... ));
		++size;
		return temp;
	}

	MyIterator Erase(const_MyIterator it) 
	{
		MyIterator temp = &arr[it.get() - arr];
		(*temp).~T();
		memmove(temp.get(), temp.get() + 1, (size - (it.get() - arr)) * sizeof(T));
		--size;
		return temp;
	}

	MyIterator Erase(const_MyIterator first, const_MyIterator last) 
	{
		const_MyIterator first_temp = first;
		MyIterator temp = &arr[first.get() - arr];
		if (first == last) return temp;
		for (; first != last; ++first)
			(*first).~T();
		memmove(temp.get(), last.get(), (size - (last.get() - arr)) * sizeof(T));
		size -= last.get() - first_temp.get();
		return temp;
	}

	void Assign(size_t count, const T& value)
	{
		size_t i;
		if (count > capacity)
		{
			capacity += count;
			T* temp_arr = new T[capacity];
			memcpy(temp_arr, arr, size * sizeof(T));
			delete[] arr;
			arr = temp_arr;
		}
		for (i = 0; i < count; ++i)
			arr[i] = value;
		size = count;
	}

	void Assign(const_MyIterator first, const_MyIterator last) 
	{
		size_t i, count = last.get() - first.get();
		if (count > capacity) 
		{
			capacity += count;
			T* temp_arr = new T[capacity];
			memcpy(temp_arr, arr, size * sizeof(T));
			delete[] arr;
			arr = temp_arr;
		}
		for (i = 0; i < count; ++i, ++first)
			arr[i] = *first;
		size = count;
	}

	MyIterator Insert(MyIterator it, const T& value)
	{
		MyIterator temp = &arr[it.get() - arr];
		if (size == capacity) 
		{
			capacity += 2;
			T* temp_arr = new T[capacity];
			memcpy(temp_arr, arr, size * sizeof(T));
			delete[] arr;
			arr = temp_arr;
		}
		memmove(temp.get() + 1, temp.get(), (size - (it.get() - arr)) * sizeof(T));
		(*temp) = value;
		++size;
		return temp;
	}
	
	MyIterator Insert(MyIterator it, size_t n, const T& value)
	{
		MyIterator find = Begin();
		int index = 0;
		for (int i = 0; i < size; i++)
		{
			if (it == find)
				break;
			index++;
			find++;
		}
		if (size + n > capacity) 
		{
			capacity += n + size;
			T* temp_arr = new T[capacity];
			memcpy(temp_arr, arr, size * sizeof(T));
			delete[] arr;
			arr = temp_arr;
		}
		MyIterator temp = &arr[index];
		if (!n) return temp;
		memmove(temp.get() + n, temp.get(), (size - index) * sizeof(T));
		size += n;
		for (MyIterator it = temp; n--; ++it)
			(*it) = value;
		return temp;
	}

	MyIterator Insert(MyIterator it, MyIterator first, MyIterator last)
	{
		MyIterator find = Begin();
		int index = 0;
		for (int i = 0; i < size; i++)
		{
			if (it == find)
				break;
			index++;
			find++;
		}
		size_t n = last.get() - first.get();
		if (size + n > capacity) 
		{
			capacity += n + size;
			T* temp_arr = new T[capacity];
			memcpy(temp_arr, arr, size * sizeof(T));
			delete[] arr;
			arr = temp_arr;
		}
		MyIterator temp = &arr[index];
		if (!n) return temp;
		memmove(temp.get() + n, temp.get(), (size - index) * sizeof(T));
		for (MyIterator it = temp; first != last; ++it, ++first)
			(*it) = *first;
		size += n;
		return temp;
	}

	MyIterator Begin()
	{
		return MyIterator(&arr[0]);
	}

	MyIterator End() 
	{
		return MyIterator(&arr[size]);
	}

	const_MyIterator Cbegin()
	{
		return const_MyIterator(&arr[0]);
	}

	const_MyIterator Cend()
	{
		return const_MyIterator(&arr[size]);
	}

	MyReverseIterator Rbegin()
	{
		return MyReverseIterator(&arr[size - 1]);
	}

	MyReverseIterator Rend()
	{
		return MyReverseIterator(&arr[0 - 1]);
	}

	const_MyReverseIterator Crbegin()
	{
		return const_MyReverseIterator(&arr[size - 1]);
	}

	const_MyReverseIterator Crend()
	{
		return const_MyReverseIterator(&arr[0 - 1]);
	}

private:
	T* arr;
	size_t size;
	size_t capacity;
};


template<class T> class MyVector<T>:: MyIterator
{
public:
	MyIterator() = default;
	~MyIterator() = default;

	MyIterator(T* data)
	{
		ptr = data;
	}

	MyIterator(MyIterator const& other) 
	{
		ptr = other.ptr;
	}

	bool operator==(MyIterator const& other) const {
		return (*ptr == *other.ptr);
	}
	
	bool operator!=(MyIterator const& other) const 
	{
		return (*ptr != *other.ptr);
	}

	MyIterator& operator++() 
	{
		++ptr;
		return *this;
	}

	const MyIterator operator++(int) 
	{
		MyIterator temp(*this);
		++(*this);
		return temp;
	}

	MyIterator& operator--()
	{
		--ptr;
		return *this;
	}

	const MyIterator operator--(int) 
	{
		MyIterator temp(*this);
		--(*this);
		return temp;
	}

	MyIterator& operator+=(size_t x) 
	{
		ptr += x;
		return *this;
	}

	MyIterator& operator-=(size_t x) 
	{
		ptr -= x;
		return *this;
	}
	
	T& operator*() 
	{
		return *ptr;
	}

	T* operator->() 
	{
		return ptr;
	}

	T* get()
	{
		return ptr;
	}

protected:
	T* ptr = nullptr;
};

template<class T> class MyVector<T>::const_MyIterator:public MyIterator
{
public:
	const_MyIterator() = default;
	~const_MyIterator() = default;

	const_MyIterator(T* data):MyIterator(data)
	{
	}

	const_MyIterator(const_MyIterator const& other):MyIterator(other)
	{
	}
	const T& operator*()
	{
		return *MyIterator::ptr;
	}
};

template<class T> class MyVector<T>::MyReverseIterator
{
public:
	MyReverseIterator() = default;
	~MyReverseIterator() = default;

	MyReverseIterator(T * data)
	{
		ptr = data;
	}

	MyReverseIterator(MyReverseIterator const& other)
	{
		ptr = other.ptr;
	}

	bool operator==(MyReverseIterator const& other) const {
		return (*ptr == *other.ptr);
	}

	bool operator!=(MyReverseIterator const& other) const
	{
		return (*ptr != *other.ptr);
	}

	MyReverseIterator& operator++()
	{
		--ptr;
		return *this;
	}

	const MyReverseIterator operator++(int)
	{
		MyReverseIterator temp(*this);
		--(*this);
		return temp;
	}

	MyReverseIterator& operator--()
	{
		++ptr;
		return *this;
	}

	const MyReverseIterator operator--(int)
	{
		MyReverseIterator temp(*this);
		++(*this);
		return temp;
	}

	MyReverseIterator& operator+=(size_t x)
	{
		ptr -= x;
		return *this;
	}

	MyReverseIterator& operator-=(size_t x)
	{
		ptr += x;
		return *this;
	}

	T& operator*()
	{
		return *ptr;
	}

	T* operator->()
	{
		return ptr;
	}

	T* get()
	{
		return ptr;
	}

protected:
	T* ptr = nullptr;
};

template<class T> class MyVector<T>::const_MyReverseIterator :public MyReverseIterator
{
public:
	const_MyReverseIterator() = default;
	~const_MyReverseIterator() = default;

	const_MyReverseIterator(T* data) :MyReverseIterator(data)
	{
	}

	const_MyReverseIterator(const_MyIterator const& other) :MyReverseIterator(other)
	{
	}
	const T& operator*()
	{
		return *MyReverseIterator::ptr;
	}
};


/*int main()
{
	MyVector<int> myvector;
	myvector.Push_Back(100);
	myvector.Push_Back(200);
	myvector.Push_Back(300);

	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector.Size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	myvector.Clear();
	myvector.Push_Back(1101);
	myvector.Push_Back(2202);

	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector.Size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	std::cout << myvector.Capacity();
	return 0;
	MyVector<int> myvector;
	for (int i = 1; i <= 5; i++) myvector.Push_Back(i);



	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector.Size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	MyVector<int>::const_MyIterator it = myvector.Cbegin();
	it++;
	for (unsigned i = 0; i < myvector.Size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	MyVector<int> myvector;
	myvector.Push_Back(10);
	myvector.Push_Back(20);
	myvector.Push_Back(30);
	myvector.Push_Back(40);
	myvector.Push_Back(50);

	MyVector<int> myvector1;
	myvector1.Push_Back(100);
	myvector1.Push_Back(200);
	myvector1.Push_Back(300);

	myvector.Swap(myvector1);

	MyVector<int> myvector;
	myvector.Push_Back(10);
	myvector.Push_Back(20);
	myvector.Push_Back(30);
	myvector.Push_Back(40);
	myvector.Push_Back(50);
	for (auto it = myvector.Cbegin(); it != myvector.Cend(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';



	MyVector<int> myvector;
	myvector.Push_Back(40);
	myvector.Push_Back(50);
	myvector.Emplace_Back(100);
	myvector.Emplace_Back(200);

	std::cout << "myvector contains:";
	for (auto it = myvector.Cbegin(); it != myvector.Cend(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	MyVector<int> myvector(5);
	myvector.Push_Back(10);
	myvector.Push_Back(20);
	myvector.Push_Back(30);
	myvector.Push_Back(40);
	myvector.Push_Back(50);

	int i = 0;

	for (auto rit = myvector.Rbegin(); rit != myvector.Rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:";
	for (auto it = myvector.Begin(); it != myvector.End(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';


	return 0;
		MyVector<int> myvector;
		myvector.Push_Back(10);
		myvector.Push_Back(20);
		myvector.Push_Back(30);
		myvector.Emplace(myvector.Cbegin(), 100);
		auto it = myvector.Cbegin();
		myvector.Emplace(it, 200);
		myvector.Emplace(myvector.Cend(), 300);
		auto it1 = myvector.Cbegin();
		myvector.Emplace(it1, 300);
		std::cout << "myvector contains:";
		for (auto it = myvector.Begin(); it != myvector.End(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		auto it2 = myvector.Cbegin();
		auto it3 = myvector.Cbegin();
		it3 += 2;

		myvector.Erase(it2,it3);
		for (unsigned i = 0; i < myvector.Size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
		 MyVector<int> first;
		 first.Assign(7, 100);
		 std::cout << "myvector contains:";
		 for (auto it = first.Begin(); it != first.End(); ++it)
		 std::cout << ' ' << *it;
		 std::cout << '\n';
}

int main()
{
	MyVector<int> myvector(3, 100);


	auto it = myvector.Begin();
	 myvector.Insert(it, 200);
	 auto it1 = myvector.Cbegin();
     myvector.Insert(it1, 2, 300);

	// "it" no longer valid, get a new one:
	//it = myvector.Begin();
	//it += 2;

	//MyVector<int> anothervector(2, 400);
	//myvector.Insert(it, anothervector.Begin(), anothervector.End());



	std::cout << "myvector contains:";
	for (it = myvector.Begin(); it != myvector.End(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}*/