#ifndef WEAK_PTR_H
#define WEAK_PTR_H
#include "shared_ptr.h"

template <typename Type>
class Shared_Ptr;

template <typename Type>
class Weak_Ptr
{
private:
    ControlBlock *control_block_ptr = new ControlBlock(0, 0);
    Type *ptr = nullptr;

public:
    Weak_Ptr()
    {
    }
    Weak_Ptr(Shared_Ptr<Type> other)
    {
        control_block_ptr = other.control_block_ptr;
        ptr = other.ptr;
        *(control_block_ptr->weak_count) += 1;
    }
    Weak_Ptr(const Weak_Ptr<Type> &other)
    {
        control_block_ptr = other.control_block_ptr;
        ptr = other.ptr;
        *(control_block_ptr->weak_count) += 1;
    }

    bool expired() const
    {
        return *(control_block_ptr->shared_count) == 0;
    }
    Shared_Ptr<Type> lock() const
    {
        if (expired())
        {
            return Shared_Ptr<Type>();
        }
        else return Shared_Ptr<Type>(*this);
    }

    Type* get()
    {
        return ptr;
    }
    void swap(Weak_Ptr *other)
    {
        Weak_Ptr* temp = ptr;
        ptr = other->ptr;
        other->ptr = temp;
        delete temp;
    }

    Weak_Ptr operator=(const Weak_Ptr &other)
    {
        control_block_ptr = other.control_block_ptr;
        ptr = other.ptr;
        *(control_block_ptr->weak_count) += 1;
        return *this;
    }

    ~Weak_Ptr()
    {
        if (!control_block_ptr)
            return;
        *(control_block_ptr->weak_count) -= 1;
        if (*(control_block_ptr->weak_count) == 0 && *(control_block_ptr->shared_count) == 0)
        {
            delete control_block_ptr;
        }
    }

    friend class Shared_Ptr<Type>;
};

#endif // WEAK_PTR_H
