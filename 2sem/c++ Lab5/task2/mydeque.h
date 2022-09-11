#ifndef MYDEQUE_H
#define MYDEQUE_H

#include <algorithm>
#include <QDebug>
const size_t CHUNK_SIZE = 8;

template <typename Type>
class MyDeque
{
public:
    class MyDequeIterator
    {
    public:
        Type* current;
        Type* first;
        Type* last;
        Type** node;
        void set_node(Type** new_node)
        {
            node = new_node;
            first = *new_node;
            last = first + CHUNK_SIZE;
        }
    public:
        MyDequeIterator() = default;
        ~MyDequeIterator() = default;

        Type& operator*()const
        {
            return *current;
        }

        MyDequeIterator& operator++()
        {
            ++current;
            if (current == last)
            {
                set_node(node + 1);
                current = first;
            }
            return *this;
        }

        const MyDequeIterator operator++(int)
        {
            MyDequeIterator temp(*this);
            ++(*this);
            return temp;
        }

        MyDequeIterator& operator--()
        {
            --current;
            if (current == first)
            {
                set_node(node - 1);
                current = last;
            }
            return *this;
        }

        const MyDequeIterator operator--(int)
        {
            MyDequeIterator temp(*this);
            --(*this);
            return temp;
        }

        MyDequeIterator& operator+=(ptrdiff_t n)
        {
            ptrdiff_t offset = n + (current - first);
            if(offset >=0 && offset < ptrdiff_t(CHUNK_SIZE))
            {
                current += n;
            }
            else
            {
                ptrdiff_t node_offset;
                if (offset > 0)
                {
                    node_offset = offset / ptrdiff_t(CHUNK_SIZE);
                }
                else
                {
                    node_offset = -((-offset - 1) / ptrdiff_t(CHUNK_SIZE)) - 1 ;
                }
                set_node(node + node_offset);
                current = first + (offset - node_offset * CHUNK_SIZE);
            }
            return *this;
        }

        MyDequeIterator operator+(ptrdiff_t n)const
        {
            MyDequeIterator tmp = *this;
            return tmp += n;
        }

        MyDequeIterator& operator-=(ptrdiff_t n)
        {
            return *this += -n;
        }

        MyDequeIterator operator-(ptrdiff_t n)const
        {
            MyDequeIterator tmp = *this;
            return tmp -= n;
        }

        Type& operator[](ptrdiff_t n)const
        {
            return *(*this + n);
        }
    };
    MyDeque()
    {
        map = nullptr;
        MyDequeSize = 0;
        map_size= 0;
        CreateMapAndNodes(0);
    }
    ~MyDeque()
    {
        for (Type** node = start.node; node <= finish.node; ++node)
        {
            delete[] *node;
        }
        delete[] map;
    }

    size_t Size() const
    {
        return MyDequeSize;
    }

    bool Empty() const
    {
        return MyDequeSize == 0;
    }

    Type& operator[](size_t index)
    {
        return start[index];
    }

    MyDequeIterator Begin()
    {
        return start;
    }

    MyDequeIterator End()
    {
        return finish;
    }

    Type& Front()
    {
        return *start;
    }

    Type& Back()
    {
         MyDequeIterator tmp = finish;
        --tmp;
        return *tmp;
    }

    void Push_Back(const Type& value)
    {
        if (finish.current != finish.last - 1)
        {
            *finish.current = value;
            ++finish.current;
        }
        else
        {
            Push_Back_Add(value);
        }
        ++MyDequeSize;
    }

    void Push_Front(const Type& value)
    {
        if (start.current != start.first)
        {
            --start.current;
            *start.current = value;
        }
        else
        {
            Type temp = value;
            ReserveMapAtFront();
            *(start.node - 1) = new Type[CHUNK_SIZE];
            start.set_node(start.node - 1);
            *start.current = temp;
        }
        ++MyDequeSize;
    }

    void Pop_Back()
    {
        if (!Empty())
        {
            if (finish.current != finish.first)
            {
                --finish.current;
            }
            else
            {
                finish.set_node(finish.node - 1);
                finish.current = finish.last - 1;
            }
            --MyDequeSize;
        }
    }

    void Pop_Front()
    {
        if (!Empty())
        {
            if (start.current != start.last - 1)
            {
                ++start.current;
            }
            else
            {
                start.set_node(start.node + 1);
                start.current = start.first;
            }
            --MyDequeSize;
        }
    }

    void Clear()
    {
        for (Type** node = start.node; node <= finish.node; ++node)
        {
            delete[] *node;
        }
        delete[] map;
        MyDequeSize = 0;
        CreateMapAndNodes(0);
    }

    void Resize(size_t t, const Type& value = Type())
    {
        size_t curr_size = MyDequeSize;
        if (t > MyDequeSize)
        {
            for (size_t i = 0; i < t - curr_size; ++i)
            {
                Push_Back(value);
            }
        }
        else
        {
            for (size_t i = 0; i < curr_size - t; ++i)
            {
                Pop_Back();
            }
        }
    }
private:

    MyDequeIterator start;
    MyDequeIterator finish;
    Type** map = nullptr;
    size_t map_size = 0;
    size_t MyDequeSize = 0;

    void CreateMapAndNodes(size_t num_elements)
    {
        size_t num_nodes = num_elements / CHUNK_SIZE + 1;
        map_size = 8 > num_nodes + 2 ? 8:(num_nodes + 2);
        map = new Type*[map_size];
        Type** tmp_start = map + (map_size - num_nodes) / 2;
        Type** tmp_finish = tmp_start + num_nodes - 1;
        for (Type** cur = tmp_start; cur <= tmp_finish; cur++)
        {
            *cur = new Type[CHUNK_SIZE];
        }
        start.set_node(tmp_start);
        start.current = start.first;
        finish.set_node(tmp_finish);
        finish.current = finish.first + num_elements % CHUNK_SIZE;
    }

    void ReallocateMap(size_t nodes_to_add, bool add_at_front)
    {
        size_t old_num_nodes = finish.node - start.node + 1;
        size_t new_num_nodes = old_num_nodes + nodes_to_add;
        Type** new_tmp_start;
        if (map_size > 2 * new_num_nodes)
        {
            new_tmp_start = map + (map_size - new_num_nodes) / 2 + (add_at_front ? nodes_to_add : 0);
            if (new_tmp_start < start.node)
            {
                std::copy(start.node, finish.node + 1, new_tmp_start);
            }
            else
            {
                std::copy_backward(start.node, finish.node + 1, new_tmp_start + old_num_nodes);
            }
        }
        else
        {
            size_t new_map_size = map_size + std::max(map_size, nodes_to_add) + 2;
            Type** new_map = new Type*[new_map_size];
            new_tmp_start = new_map + (new_map_size - new_num_nodes) / 2 + (add_at_front ? nodes_to_add : 0);
            std::copy(start.node, finish.node + 1, new_tmp_start);
            delete[] map;
            map = new_map;
            map_size = new_map_size;
        }
           start.set_node(new_tmp_start);
           finish.set_node(new_tmp_start + old_num_nodes - 1);
    }

    void ReserveMapAtBack(size_t nodes_to_add = 1)
    {
        if (nodes_to_add > map_size - (finish.node - map) - 1)
        {
            ReallocateMap(nodes_to_add, false);
        }
    }

    void ReserveMapAtFront(size_t nodes_to_add = 1)
    {
        if (nodes_to_add > start.node - map)
        {
            ReallocateMap(nodes_to_add, true);
        }
    }

    void Push_Back_Add(const Type& temp)
    {
        Type temp_copy = temp;
        ReserveMapAtBack();
        *(finish.node + 1) = new Type[CHUNK_SIZE];
        *finish.current = temp_copy;
        finish.set_node(finish.node + 1);
        finish.current = finish.first;
    }
};
#endif // MYDEQUE_H
