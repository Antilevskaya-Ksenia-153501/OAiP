#ifndef SHARED_PTR_H
#define SHARED_PTR_H
#include "unique_ptr.h"

template <class Type>
class Weak_Ptr;

struct ControlBlock
{
    int *shared_count = nullptr;
    int *weak_count = nullptr;
    ControlBlock(int temp_shared_count, int temp_weak_count)
    {
        shared_count = new int(temp_shared_count);
        weak_count = new int(temp_weak_count);
    }
};

template <typename Type>
class Shared_Ptr
{
private:
    Type *ptr = nullptr;
    ControlBlock *control_block_ptr = new ControlBlock(0, 0);

public:
    Shared_Ptr()
    {
    }
    Shared_Ptr(Type *ptr)
    {
        this->ptr = ptr;
        control_block_ptr = new ControlBlock(1, 0);
    }
    Shared_Ptr(const Shared_Ptr &other)
    {
        this->~Shared_Ptr();
        control_block_ptr = other.control_block_ptr;
        ptr = other.ptr;
        *(control_block_ptr->shared_count) += 1;
    }
    Shared_Ptr(Weak_Ptr<Type> weak_ptr)
    {
        control_block_ptr = weak_ptr.control_block_ptr;
        ptr = weak_ptr.ptr;
        *(control_block_ptr->shared_count) += 1;
    }
    Shared_Ptr(Shared_Ptr&& other)
    {
        control_block_ptr = other.control_block_ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
        other.control_block_ptr = nullptr;
    }
    Shared_Ptr(Unique_Ptr<Type>&& other)
    {
        *this = other.release();
    }

    Shared_Ptr operator=(const Shared_Ptr &other)
    {
        control_block_ptr = other.control_block_ptr;
        ptr = other.ptr;
        *(control_block_ptr->shared_count) += 1;
        return *this;
    }
    Shared_Ptr operator=(Shared_Ptr&& other)
    {
        this->~Shared_Ptr();
        control_block_ptr = other.control_block_ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
        other.control_block_ptr = nullptr;
        return *this;
    }

    Type& operator*() const
    {
        return *ptr;
    }
    Type* operator->() const
    {
        return ptr;
    }
    explicit operator bool()
    {
        return this->get() != nullptr;
    }
    Type* get()
    {
        return ptr;
    }
    int get_count() const
    {
        return *(control_block_ptr->shared_count);
    }
    void reset(Type *other)
    {
        this->~Shared_Ptr();
        *this = Shared_Ptr<Type>(other);
    }

    ~Shared_Ptr()
    {
        if (control_block_ptr == nullptr)
            return;

        (*(control_block_ptr->shared_count))--;
        if (*(control_block_ptr->shared_count) == 0 && *(control_block_ptr->weak_count) == 0)
        {
            delete control_block_ptr->shared_count;
            delete control_block_ptr->weak_count;
            delete control_block_ptr;
            delete ptr;
        }
        else if (*(control_block_ptr->shared_count) == 0)
        {
            delete ptr;
        }

        ptr = nullptr;
        control_block_ptr = nullptr;
    }

    friend class Weak_Ptr<Type>;

    template <typename QType, typename... Args>
    friend Shared_Ptr<QType> make_shared_ptr(Args&&... args);

};

template <typename Type, typename... Args>
Shared_Ptr<Type> make_shared_ptr(Args&&... args)
{
    return Shared_Ptr<Type>(new Type(std::forward<Args>(args)...));
}
#endif // SHARED_PTR_H
