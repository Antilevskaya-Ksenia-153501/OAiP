#include<iostream>
#include<fstream>
#include<string>

class MyString 
{
public:
	MyString()
	{
		str = nullptr;
		size = 0;
	}

	MyString(const char* str) 
	{
		size = strlen(str);
		this->str = new char[size + 1];
		for (int i = 0; i < size; i++) 
		{
			this->str[i] = str[i];
		}
		this->str[size] = '\0';
	}

	MyString(const MyString& other)
	{
		size = strlen(other.str);
		this->str = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[size] = '\0';
	}

	MyString(MyString&& other) noexcept
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		other.size = 0;
	}

	~MyString()
	{
		delete[] this->str;
	}

	MyString& operator= (const MyString& other) 
	{
		if (this->str != nullptr) 
		{
			delete[] str;
		}
		size = strlen(other.str);
		this->str = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[size] = '\0';
		return *this;
	}

	MyString operator+ (const MyString& other)
	{
		MyString tempString;
		int thisSize = strlen(this->str);
		int otherSize = strlen(other.str);
		tempString.size = thisSize + otherSize;
		tempString.str = new char[thisSize + otherSize + 1];
		int i = 0;
		for (; i < thisSize; i++)
		{
			tempString.str[i] = this->str[i];
		}
		for (int j = 0; j < otherSize; j++, i++) 
		{
			tempString.str[i] = other.str[j];
		}
		tempString.str[thisSize + otherSize] = '\0';
		return tempString;
	}

	MyString operator+ (const char* other)
	{
		MyString tempString;
		int thisSize = strlen(this->str);
		int otherSize = strlen(other);
		tempString.size = thisSize + otherSize;
		tempString.str = new char[thisSize + otherSize + 1];
		int i = 0;
		for (; i < thisSize; i++)
		{
			tempString.str[i] = this->str[i];
		}
		for (int j = 0; j < otherSize; j++, i++)
		{
			tempString.str[i] = other[j];
		}
		tempString.str[thisSize + otherSize] = '\0';
		return tempString;
	}
	
	bool operator== (const MyString& other) 
	{
		if (this->size != other.size) 
		{
			return false;
		}
		for (int i = 0; i < size; i++) 
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator!= (const MyString& other)
	{
		return !(this->operator==(other));
	}

	bool operator< (const MyString& other)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (this->str[i] < other.str[i])
			{
				return true;
			}
			else if (this->str[i] == other.str[i])
			{
				continue;
			}
			else 
			{
				return false;
			}
		}
		return false;
	}

	bool operator<= (const MyString& other)
	{
		bool flag = false;
		for (unsigned i = 0; i < size; i++)
		{
			if (this->str[i] < other.str[i])
			{
				return true;
			}
			else if (this->str[i] == other.str[i])
			{
				flag = true;
			}
			else
			{
				return false;
			}
		}
		return flag;
	}

	bool operator> (const MyString& other)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (this->str[i] > other.str[i])
			{
				return true;
			}
			else if (this->str[i] == other.str[i])
			{
				continue;
			}
			else
			{
				return false;
			}
		}
		return false;
	}

	bool operator>= (const MyString& other)
	{
		bool flag = false;
		for (unsigned i = 0; i < size; i++)
		{
			if (this->str[i] > other.str[i])
			{
				return true;
			}
			else if (this->str[i] == other.str[i])
			{
				flag = true;
			}
			else
			{
				return false;
			}
		}
		return flag;
	}

	char& operator[] (int index)
	{
		return this->str[index];
	}

	char& at(int index)
	{
		if (index > this->size)
			std::cout << "Out_of_range exception: position = " << index << std::endl;
		return this->str[index];
	}

	bool Empty() const
	{
		if (str == NULL && size == 0) 
			return true;
		else return false;
	}

	char* getText()
	{
		return this->str;
	}
	size_t Size()
	{
		return this->size;
	}

	size_t Length() const
	{
		return this->size;
	}

	MyString& Erase(const size_t& position, const size_t& n)
	{
		unsigned int i, j;
		MyString temp(this->str);
		this->size = this->size - n;
		delete[] this->str;
		this->str = new char[size + 1];
		for (i = 0; i < position; i++)
			this->str[i] = temp.str[i];
		for (i = position, j = position + n; j < temp.Size(); i++, j++)
			this->str[i] = temp.str[j];
		this->str[size] = '\0';
		return *this;
	}
	
	size_t Copy(char* temp, const size_t& len, const size_t& pos) const
	{
		size_t i, j;
		for (j = pos, i = 0; i < len; i++, j++)
			temp[i] = this->str[j];
		return i;
	}

	void Swap(MyString& other)
	{
		MyString temp;
		temp = *this;
		*this = other;
		other = temp;
	}

	MyString& Assign(const MyString& other)
	{
		return *this = other;
	}

	MyString& Assign(const char* other)
	{
		return *this = other;
	}

	MyString& Assign(const char* other, const size_t& n)
	{
		unsigned int i;
		this->size = n;
		this->str = new char[n + 1];
		for (i = 0; i < size; i++)
			this->str[i] = other[i];
		this->str[size] = '\0';
		return *this;
	}

	MyString& Assign(const size_t& n, const char symbol)
	{
		unsigned i;
		this->size = n;
		this->str = new char[n + 1];
		for (i = 0; i < n; i++)
			this->str[i] = symbol;
		this->str[n] = '\0';
		return *this;
	}

	MyString& Assign(const MyString& other, const size_t& pos, const size_t& len)
	{
		unsigned i, j;
		if (this->str != nullptr)
			delete[] this->str;
		this->str = new char[len + 1];
		this->size = len;
		for (i = pos, j = 0; i < (pos + len); i++, j++)
			this->str[j] = other.str[i];
		this->str[len] = '\0';
		return *this;
	}

	MyString& Append(const MyString& other)
	{
		*this = *this + other;
		return *this;
	}
	
	MyString& Append(const char* other)
	{
		*this = *this + other;
		return *this;
	}
	
	MyString& Append(const MyString& other, const size_t& pos, const size_t& len)
	{
		MyString temp;
		temp.Assign(other, pos, len);
		*this = *this + temp;
		return *this;
	}

	MyString& Append(const char* other, const size_t& n)
	{
		MyString temp;
		temp.Assign(other, n);
		*this = *this + temp;
		return *this;
	}

	MyString& Append(const size_t& n, const char symbol)
	{
		MyString temp;
		temp.Assign(n, symbol);
		*this = *this + temp;
		return *this;
	}
	
	MyString& Insert(const size_t& pos, const MyString& other)
	{
		MyString temp(this->str);
		unsigned i, j;
		this->size = this->size + other.size;
		delete[] this->str;
		this->str = new char[this->size + 1];
		for (i = 0; i < pos; i++)
			this->str[i] = temp.str[i];
		for (i = pos, j = 0; j < other.size; i++, j++)
			this->str[i] = other.str[j];
		for (i = other.size + pos, j = pos; i < this->size; i++, j++)
			this->str[i] = temp.str[j];
		this->str[size] = '\0';
		return *this;
	}

	MyString& Insert(const size_t& pos, const char* other)
	{
		MyString str(other);
		MyString temp(this->str);
		*this = temp.Insert(pos, str);
		return *this;
	}

	MyString& Replace(const size_t& pos, const size_t& len, const MyString& other)
	{
		MyString temp(this->str);
		unsigned i;
		temp.Erase(pos, len);
		temp.Insert(pos, other);
		this->size = temp.size;
		delete[] this->str;
		str = new char[this->size + 1];
		for (i = 0; i < this->size; i++)
			this->str[i] = temp.str[i];
		this->str[i] = '\0';
		return *this;
	}

	MyString& Replace(const size_t& pos, const size_t& len, const char* other)
	{
		unsigned i;
		MyString temp(this->str);
		MyString temp_other(other);
		temp.Replace(pos, len, temp_other);
		this->size = temp.size;
		delete[] this->str;
		this->str = new char[this->size + 1];
		for (i = 0; i < this->size; i++)
			this->str[i] = temp.str[i];
		this->str[i] = '\0';
		return *this;
	}

	void Clear()
	{
		if (this->size > 0)
			delete[] this->str;
		this->size = 0;
		this->str = NULL;
	}

	void ExpandMemory(const size_t& n)
	{
		unsigned exp = n + size;
		char* temp = new char[exp + 1];
		memset(temp, 0, exp + 1);
		temp[exp] = '\0';
		for (unsigned i = 0; i < size; i++)
			temp[i] = str[i];
		Clear();
		size = exp;
		str = new char[size + 1];
		memset(str, 0, size + 1);
		str[size] = '\0';
		for (unsigned i = 0; temp[i] != '\0'; i++)
			str[i] = temp[i];
		delete[] temp;
		temp = NULL;
	}

	void push_back(const char& symbol)
	{
		unsigned i = this->size;
		ExpandMemory(1);
		str[i] = symbol;
	}
	friend std::ostream& operator<< (std::ostream& os, const MyString& other);
	friend std::istream& operator>> (std::istream& is, MyString& other);

private:
	char* str;
	int size;
	
};
std:: ostream& operator<< (std::ostream& os, const MyString& other)
{
	os << other.str;
	return os;
}

std::istream& getline(std::istream& is, MyString& other, const char& stop)
{
	other.Clear();
	char symbol = getchar();
	while (symbol != stop) {
		other.push_back(symbol);
		symbol = getchar();
	}
	return is;
}

std::istream& operator>> (std::istream& is, MyString& other)
{
	getline(is, other, '\n');
	return is;
}


int main()
{
	//MyString res("Hello");
	//MyString res1("By");
	//MyString temp = res + res1;
	//char dest[30];
	//Strncpy(dest, "Techie ", 10);

	//char src[] = "Delight – Implement strncat";

	//Strncat(dest, src, 7);

	//std:: cout <<dest;
	//char a[] = "bc4";
	//char b[] = "bc5";
	//std:: cout << Strncmp(a, b, 3);

	 
	//return 0;
	//char str[6] = "Hello";
	//Memset(str, 't', 2);
	//for (int i = 0; i < sizeof(str); i++)
	//std:: cout << str[i];
	//MyString str = "Bu";
	//MyString str1 = "Hello world";
	//str.Insert(1, "Gugu");
	//std::cout << str;
	//std::cout << str.Size();
	//std::cout << std::endl;
	//std::cout << str1;
	//std::cout << str1.Size();
	//return 0;
	/*MyString base = "this is a test string.";
	MyString str2 = "n example";
	// replace signatures used in the same order as described above:

	// Using positions:                 0123456789*123456789*12345
	MyString str = base;           // "this is a test string."
	str.Replace(9, 5, "huhuhoooo");
	std::cout << str;// "this is an example string." (1)*/
	MyString base;
	std::cin >> base;
	std::cout << base;
	


	return 0;
}


