#ifndef MYBITSET_H
#define MYBITSET_H
#include<cstdio>
#include<climits>
#include<string>
#include<stdexcept>
#include<QDebug>

template<size_t Size>
class MyBitSet{
private:
    static const size_t elementSize = 8 * sizeof(unsigned long long);
    static const size_t arrSize = (Size - 1)/elementSize + 1;
    unsigned long long array_of_bits[arrSize];
public:
    class Reference{
    private:
        friend MyBitSet<Size>;
        MyBitSet<Size>* BitMap;
        size_t pos;
    public:
        Reference()
        {
            BitMap = nullptr;
            pos = 0;
        }
        Reference(MyBitSet<Size>& temp_BitMap, size_t temp_pos)
        {
            BitMap = &temp_BitMap;
            pos = temp_pos;
        }
        Reference& operator=(bool value)
        {
            unsigned long long& currentElement = BitMap->array_of_bits[pos/BitMap->elementSize], temp = 1;
            if (value)
                currentElement |= (temp << (pos % BitMap->elementSize));
            else
                currentElement &= ~(temp << (pos % BitMap->elementSize));
            return *this;
        }
        operator bool()
        {
            BitMap->Test(pos);
        }
    };
    MyBitSet()
    {
        for (size_t i = 0; i < arrSize; i++)
        {
            array_of_bits[i] = 0;
        }
    }
    MyBitSet(const MyBitSet& other)
    {
        for (size_t i = 0; i < arrSize; i++)
            array_of_bits[i] = other.bits[i];
    }
    MyBitSet(unsigned long long num)
    {
        array_of_bits[0] = num;
    }
    bool All() const
    {
        bool check_empty = Size == 0;
        if(check_empty)
            return true;
        bool complited = ((Size % elementSize) == 0);
        for (size_t i = 0; i < arrSize - 1 + complited; i++)
        {
            if (array_of_bits[i] != ULLONG_MAX)
                return false;
        }
        unsigned long long temp = 1;
        return complited || array_of_bits[arrSize - 1] == ((temp << (Size % elementSize)) - 1);

    }
    bool Any() const
    {
        for (size_t i = 0; i < arrSize; i++)
        {
            if (array_of_bits[i] != 0)
                return true;
        }
        return false;
    }
    size_t Count() const
    {
        size_t number = 0;
        unsigned long long temp[arrSize];
        for (size_t i = 0; i < arrSize; i++)
            temp[i] = array_of_bits[i];
        for (size_t i = 0; i < arrSize; i++)
        {
            while (temp[i])
            {
                number++;
                temp[i] &= temp[i]-1;
            }
        }
        return number;
    }
    void Flip()
    {
        for (size_t i = 0; i < arrSize; i++)
            array_of_bits[i] = ~array_of_bits[i];
        unsigned long long temp = 1;
        array_of_bits[arrSize - 1] &= ((temp << (Size % elementSize)) - 1);
    }
    bool None() const
    {
        for (size_t i = 0; i < arrSize; i++)
        {
            if (array_of_bits[i] != 0)
                return false;
        }
        return true;
    }
    void Reset()
    {
        for (size_t i = 0; i < arrSize; i++)
            array_of_bits[i] = 0;
    }
    void Reset(size_t pos)
    {
        Reference(*this, pos) = 0;
    }
    void Set()
    {
        for(size_t i; i < arrSize; i++)
            array_of_bits[i] = ULLONG_MAX;
    }
    void Set(int pos)
    {
        Reference(*this, pos) = 1;
    }
    size_t GetSize() const
    {
        return Size;
    }
    bool Test(size_t pos)
    {
        unsigned long long temp = 1;
        return array_of_bits[pos / elementSize - (pos % 64 == 0 && pos)] & (temp << (pos % elementSize));
    }
    std::string to_string()
    {
        std::string out;
        for (int i = Size - 1; i >= 0; i--)
            out.push_back(Test(i) + '0');
        return out;
    }
    unsigned long to_ulong()
    {
        if (Size == 0)
            return 0;
        if (Size <= 32)
            return static_cast<unsigned long>(array_of_bits[0]);
        bool overflow = Size > 64;
        if (overflow)
        {
            for (size_t i = 1; i < arrSize; i++)
            {
                if (array_of_bits[i] != 0)
                    throw std::overflow_error("Bitset overflow");
            }
        }
        if (array_of_bits[0] > ULONG_MAX)
        {
            throw std::overflow_error("Bitset overflow");
        }
        return static_cast<unsigned long>(array_of_bits[0]);
    }
    unsigned long long to_ullong()
    {
        if (Size == 0)
            return 0;
        if (Size <= 64)
            return array_of_bits[0];
        bool overflow = Size > 64;
        if (overflow)
        {
            for (size_t i = 1; i < arrSize; i++)
            {
                if (array_of_bits[i] != 0)
                    throw std::overflow_error("Bitset overflow");
            }
        }
        return array_of_bits[0];
    }
    Reference operator[](size_t pos)
    {
        if (pos < Size)
            return Reference(*this, pos);
        throw std::out_of_range("Bitset index outside range");
    }
    MyBitSet& operator&=(const MyBitSet& other)
    {
        for (size_t i = 0; i < arrSize; i++)
            array_of_bits[i] &= other.array_of_bits[i];
        return *this;
    }
    MyBitSet& operator|=(const MyBitSet& other)
    {
        for (size_t i = 0; i < arrSize; i++)
            array_of_bits[i] |= other.array_of_bits[i];
        return *this;
    }
    MyBitSet& operator^=(const MyBitSet& other)
    {
        for (size_t i = 0; i < arrSize; i++)
            array_of_bits[i] ^= other.array_of_bits[i];
        return *this;
    }
    bool operator== (const MyBitSet& other) const
    {
        for (size_t i = 0; i < arrSize; i++)
        {
            if (array_of_bits[i] != other.array_of_bits[i])
                return false;
        }
        return true;
    }
    bool operator!= (const MyBitSet& other) const
    {
        int count = 0;
        for (size_t i = 0; i < arrSize; i++)
        {
            if (array_of_bits[i] == other.array_of_bits[i])
                count++;
        }
        if (count == arrSize)
            return false;
        return true;
    }
    MyBitSet operator<<(size_t pos) const
    {
        MyBitSet temp = *this;
        temp <<= pos;
        return temp;
    }
    MyBitSet operator>>(size_t pos) const
    {
        MyBitSet temp = *this;
        temp >>= pos;
        return temp;
    }
};

#endif // MYBITSET_H
