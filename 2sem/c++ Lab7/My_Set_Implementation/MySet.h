#ifndef MYSET_H
#define MYSET_H
#include <mytree.h>

template <typename TypeKey, typename Type>
class MySet
{
public:
    class MySetIterator;
    class MySetIterator_List;
    ~MySet()
    {
        map.~MyTree();
    }
    MySetIterator Begin()
    {
       MyTreeNode<TypeKey, Type>* ptr = map.GetRoot();
       if (ptr != nullptr)
       {
           while (ptr->left != nullptr)
               ptr = ptr->left;
       }
       return MySetIterator(ptr);
    }
    MySetIterator End()
    {
        if (map.GetRoot() == nullptr)
            return 0;
        return  MySetIterator(map.GetRoot()->parent);
    }
    MySetIterator_List Begin_List()
    {
       MySetIterator_List ptr(map.GetRoot());
       return ptr;
    }
    MySetIterator_List End_List()
    {
        return MySetIterator_List(map.GetRoot()->parent);
    }
    std::pair<MySetIterator, bool> Insert(std::pair<TypeKey, Type> val)
    {
        MyTreeNode<TypeKey, Type>* temp(map.GetSearch(val.first));
        MyTreeNode<TypeKey, Type>* res_temp = new MyTreeNode<TypeKey, Type>(val.first, val.second);
        MySetIterator res(res_temp);
        std::pair<MySetIterator, bool> result(res, true);
        if(temp && temp->data.first == val.first)
        {
            result.second = false;
            return result;
        }
        else
        {
            map.AddTreeNode(val.first, val.second);
            return result;
        }
        delete res_temp;
    }
    std::pair<std::pair<TypeKey, Type>, bool> Emplace(TypeKey key, Type value)
    {
        std::pair<TypeKey, Type> temp(key, value);
        return Insert(temp);
    }
    std::pair<TypeKey, Type> Find(TypeKey findKey)
    {
        MyTreeNode<TypeKey, Type>* temp(map.GetSearch(findKey));
        if (temp)
            return temp->data;
        else
        {
            std::pair<TypeKey, Type> notFound(0, 0);
            return notFound;
        }
    }
    void Erase(const TypeKey& DeleteKey)
    {
        map.Remove(DeleteKey);
    }
private:
    MyTree<TypeKey, Type> map;
};

template<typename TypeKey, typename Type> class MySet<TypeKey, Type>:: MySetIterator
{
public:
    MySetIterator() = default;
    ~MySetIterator() = default;
    MySetIterator(MyTreeNode<TypeKey, Type>* temp)
    {
        current = temp;
    }
    MySetIterator(const MySetIterator& ptr)
    {
        current = ptr.current;
    }
    MySetIterator& operator=(const MySetIterator& ptr)
    {
        current = ptr.current;
        return *this;
    }
    bool operator==(const MySetIterator& ptr)
    {
        return current == ptr.current;
    }
    bool operator !=(const MySetIterator& ptr)
    {
        return current != ptr.current;
    }
    MySetIterator& operator++()
    {
        if (current->right)
        {
            current = current->right;
            while (current->left)
                current = current->left;
        }
        else
        {
            MyTreeNode<TypeKey, Type>* before;
            do
            {
                before = current;
                current = current->parent;
            } while (current && before == current->right);
        }
        return *this;
    }
    MySetIterator operator++(int)
    {
        MySetIterator temp(*this);
        ++(*this);
        return temp;
    }
    MySetIterator& operator--()
    {
        if (current->left)
        {
            current = current->left;
            while (current->right)
                current = current->right;
        }
        else
        {
            MyTreeNode<TypeKey, Type>* before;
            do
            {
                before = current;
                current = current->parent;
            } while (current && before == current->left);
        }
        return *this;
    }
    MySetIterator operator--(int)
    {
        MySetIterator temp(*this);
        --(*this);
        return temp;
    }
    TypeKey& operator*() const
    {
        return current->data.first;
    }
    std::pair<TypeKey, Type>* operator->() const
    {
        return &(current->data);
    }
    MyTreeNode<TypeKey, Type>* Get() const
    {
        return current;
    }
private:
    MyTreeNode<TypeKey, Type>* current;
};

template<typename TypeKey, typename Type> class MySet<TypeKey, Type>:: MySetIterator_List
{
public:
    MySetIterator_List() = default;
    MySetIterator_List(MyTreeNode<TypeKey, Type>* temp)
    {
        StoreNodes(temp);
    }
    MySetIterator_List(const MySetIterator_List& ptr)
    {
        MyTreeList = ptr.MyTreeList;
    }
    MySetIterator_List& operator++()
    {
        MyTreeList.pop_front();
        return *this;
    }
    const MySetIterator_List operator++(int)
    {
        MySetIterator_List temp(*this);
        MyTreeList.pop_front();
        return temp;
    }
    MySetIterator_List& operator--()
    {
        MyTreeList.pop_back();
        return *this;
    }

    const MySetIterator_List operator--(int)
    {
        MySetIterator_List temp(*this);
        MyTreeList.pop_back();
        return temp;
    }
    bool operator==(const MySetIterator_List& ptr)
    {
        return MyTreeList.front() == ptr.MyTreeList.front();
    }
    bool operator !=(const MySetIterator_List& ptr)
    {
        return MyTreeList.front() != ptr.MyTreeList.front();
    }
    TypeKey& operator*() const
    {
        MyTreeNode<TypeKey, Type>* curr = MyTreeList.front();
        return curr->data.first;
    }
    std::pair<TypeKey, Type>* operator->() const
    {
        MyTreeNode<TypeKey, Type>* curr = MyTreeList.front();
        return &(curr->data);
    }
private:
    std::list<MyTreeNode<TypeKey, Type>*> MyTreeList;
    void StoreNodes(MyTreeNode<TypeKey, Type>* root)
    {
        if (root != nullptr)
        {
            StoreNodes(root->left);
            MyTreeList.push_back(root);
            StoreNodes(root->right);
        }
    }
};
#endif // MYMAP_H

