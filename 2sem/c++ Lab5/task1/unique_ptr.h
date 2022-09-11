#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H
#include<iostream>

template <class T>
class Unique_Ptr
{
private:
    T *ptr;
public:
    Unique_Ptr()
    {
        ptr = nullptr;
    }
    Unique_Ptr(T *ptr)
    {
        this->ptr = ptr;
    }
    Unique_Ptr(Unique_Ptr&& other)
    {
        ptr = other.release();
    }
    ~Unique_Ptr()
    {
        delete ptr;
    }

    T& operator*() const
    {
        return *ptr;
    }
    T* operator->() const
    {
        return ptr;
    }

    T* get() const
    {
        return ptr;
    }
    void reset(T *new_value_of_ptr)
    {
        delete ptr;
        ptr = new_value_of_ptr;
    }

    void reset()
    {
        delete ptr;
        ptr = nullptr;
    }

    T* release()
    {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }
    void swap(Unique_Ptr *other)
    {
        Unique_Ptr* temp = ptr;
        ptr = other->ptr;
        other->ptr = temp;
        delete temp;
    }

    Unique_Ptr(Unique_Ptr const& other) = delete;
    Unique_Ptr& operator=(Unique_Ptr const& other) = delete;
    Unique_Ptr& operator=(Unique_Ptr&& other) noexcept
    {
        reset(other.release());
            return *this;
    }
    explicit operator bool()
    {
        return this->get() != nullptr;
    }

    template <typename QType, typename... Args>
    friend Unique_Ptr<QType> make_unique_ptr(Args&&... args);
};

template <typename Type, typename... Args>
Unique_Ptr<Type> make_unique_ptr(Args&&... args)
{
    return Unique_Ptr<Type>(new Type(std::forward<Args>(args)...));
}

#endif // UNIQUE_PTR_H
