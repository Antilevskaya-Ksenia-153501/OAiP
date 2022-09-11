#ifndef MYTREE_H
#define MYTREE_H
#include<list>
#include <utility>
#include<QString>

template <typename TypeKey, typename Type>
struct MyTreeNode
{
    std::pair<TypeKey, Type> data;
    MyTreeNode* right;
    MyTreeNode* left;
    MyTreeNode* parent;
    int balance;
    MyTreeNode()
    {
        data.first = TypeKey();
        data.second = Type();
        right = nullptr;
        left = nullptr;
        balance = 0;
    }
    MyTreeNode(TypeKey key, Type value)
    {
        data.first = key;
        data.second = value;
        right = nullptr;
        left = nullptr;
        balance = 0;
    }
};
template <typename TypeKey, typename Type>
class MyTree
{
protected:
    MyTreeNode<TypeKey,Type>* root;
    QString ResultInDirectOrder;
    QString ResultInReverseOrder;
    QString ResultInAscendingOrder;
    void PrintInDirectOrderInside(const MyTreeNode<TypeKey, Type>* root)
    {
        if (root != nullptr)
        {
            ResultInDirectOrder += QString::number(root->data.first) + " ";
            if(root->left)
                PrintInDirectOrderInside(root->left);
            if(root->right)
                PrintInDirectOrderInside(root->right);
        }
    }
    void PrintInReverseOrderInside(const MyTreeNode<TypeKey, Type>* root)
    {
        if (root != nullptr)
        {
            if(root->left)
                PrintInReverseOrderInside(root->left);
            if(root->right)
                PrintInReverseOrderInside(root->right);
           ResultInReverseOrder += QString::number(root->data.first) + " ";
        }
    }
    void PrintInAscendingOrderInside(const MyTreeNode<TypeKey, Type>* root)
    {
        if (root != nullptr)
        {
            if(root->left)
                PrintInAscendingOrderInside(root->left);
            ResultInAscendingOrder += QString::number(root->data.first) + " ";
            if(root->right)
                PrintInAscendingOrderInside(root->right);
        }
    }
    int Height(MyTreeNode<TypeKey, Type>* root)
    {
        if (root == nullptr)
            return 0;
        int rightHeight = root->right ? Height(root->right) : 0;
        int leftHeight = root->left ? Height(root->left) : 0;
        if (rightHeight >= leftHeight)
            return rightHeight + 1;
        else
            return leftHeight + 1;
    }
    void SetBalance(MyTreeNode<TypeKey, Type>*(&root))
    {
        if (root != nullptr)
            root->balance = Height(root->right) - Height(root->left);
    }
    void TurnRight(MyTreeNode<TypeKey, Type>*(&root))
    {
        MyTreeNode<TypeKey, Type> *LeftNode, *LeftNodeRightNode;
        LeftNode = root->left;
        LeftNodeRightNode = LeftNode->right;

        if (LeftNode->right != nullptr)
            LeftNode->right->parent = root;

        LeftNode->right = root;
        root->left = LeftNodeRightNode;

        LeftNode->parent = root->parent;
        root->parent = LeftNode;

        if (LeftNode->parent != nullptr && root->data.first < LeftNode->parent->data.first)
            LeftNode->parent->left = LeftNode;
        else if (LeftNode->parent != nullptr)
            LeftNode->parent->right = LeftNode;

        root = LeftNode;
        SetBalance(root->right);
        SetBalance(root);
    }
    void TurnLeft(MyTreeNode<TypeKey, Type>*(&root))
    {
        MyTreeNode<TypeKey, Type> *RightNode, *RightNodeLeftNode;
        RightNode = root->right;
        RightNodeLeftNode = RightNode->left;

        if(RightNode->left != nullptr)
            RightNode->left->parent = root;

        RightNode->left = root;
        root->right = RightNodeLeftNode;

        RightNode->parent = root->parent;
        root->parent = RightNode;

        if (RightNode->parent != nullptr && root->data.first < RightNode->parent->data.first)
            RightNode->parent->left = RightNode;
        else if (RightNode->parent != nullptr)
            RightNode->parent->right = RightNode;

        root = RightNode;
        SetBalance(root->left);
        SetBalance(root);
    }
    void AddTreeNodeInside(MyTreeNode<TypeKey, Type>*(&root), TypeKey key, Type value, MyTreeNode<TypeKey, Type>* parent = nullptr)
    {
        if (root == nullptr)
        {
            root = new MyTreeNode<TypeKey, Type>();
            root->data.first = key;
            root->data.second = value;
            root->parent = parent;
        }
        else
        {
            if (key > root->data.first)
            {
                AddTreeNodeInside(root->right, key, value, root);
                if (Height(root->right) - Height(root->left) > 1)
                {
                    if(Height(root->right->right) < Height(root->right->left))
                        TurnRight(root->right);
                    TurnLeft(root);
                }
            }
            else if (key < root->data.first)
            {
                AddTreeNodeInside(root->left, key, value, root);
                if(Height(root->left) - Height(root->right) > 1)
                {
                    if (Height(root->left->left) < Height(root->left->right))
                        TurnLeft(root->left);
                    TurnRight(root);
                }
            }
            SetBalance(root);
        }
    }
    MyTreeNode<TypeKey, Type>* SearchNode(MyTreeNode<TypeKey, Type>* root, TypeKey findKey)
    {
        if (root == nullptr)
            return nullptr;
        if (root->data.first == findKey)
            return root;
        if (root->data.first > findKey)
        {
            if (root->left)
                return SearchNode(root->left, findKey);
            else
                return nullptr;
        }
        else
            return root->right ? SearchNode(root->right, findKey) : nullptr;
    }
    void RemoveInside(MyTreeNode<TypeKey, Type>*(&root), TypeKey deleteKey)
    {
        if(root == NULL)
            return;
        if(deleteKey < root->data.first)
            RemoveInside(root->left, deleteKey);
        else if(deleteKey > root->data.first)
            RemoveInside(root->right, deleteKey);
        else
        {
            if((root->left != nullptr) && (root->right == nullptr))
            {
                MyTreeNode<TypeKey, Type>* temp = root->left;
                if (root->parent != nullptr)
                {
                    if (root->parent->data.first <= root->data.first)
                    {
                        root->left->parent = root->parent;
                        root->parent->right = root->left;
                    }
                    else
                    {
                        root->left->parent = root->parent;
                        root->parent->left = root->left;
                    }
                    Height(root->parent);
                }
                //root->left->parent = root->parent;
                root = temp;
                //delete temp;
            }
            else if((root->left == nullptr) && (root->right != nullptr))
            {
                MyTreeNode<TypeKey, Type>* temp = root->right;
                if (root->parent != nullptr)
                {
                    if (root->parent->data.first <= root->data.first)
                    {
                        root->right->parent = root->parent;
                        root->parent->right = root->right;
                    }
                    else
                    {
                        root->right->parent = root->parent;
                        root->parent->left = root->right;
                    }
                    Height(root->parent);
                }
                //root->right->parent = root->parent;
                root = temp;
                //delete temp;
            }
            else if ((root->left == nullptr) && (root->right == nullptr))
            {
                /*if (root->parent->data.first < root->data.first)
                    root->parent->right = nullptr;
                else
                    root->parent->left = nullptr;*/
               MyTreeNode<TypeKey, Type>* temp = root;
               root = nullptr;
               delete temp;
            }
            else
            {
                MyTreeNode<TypeKey, Type>* r = root->right;
                while(r->left != nullptr)
                    r = r->left;
                root->data.first = r->data.first;
                root->data.second = r->data.second;
                RemoveInside(root->right, r->data.first);
            }
        }
        if(root == nullptr)
            return;
        if (Height(root->right) - Height(root->left) > 1)
        {
            if(Height(root->right->right) < Height(root->right->left))
                TurnRight(root->right);
            TurnLeft(root);
        }
        if(Height(root->left) - Height(root->right) > 1)
        {
            if (Height(root->left->left) < Height(root->left->right))
                TurnLeft(root->left);
            TurnRight(root);
        }
        SetBalance(root);
    }
    void ClearInside(MyTreeNode<TypeKey, Type>*(&root))
    {
        if (root != nullptr)
        {
            ClearInside(root->left);
            ClearInside(root->right);
            delete root;
            root = nullptr;
        }
    }
public:
    MyTree()
    {
        root = nullptr;
    }
    ~MyTree()
    {
        ClearInside(root);
    }
    void AddTreeNode(TypeKey key, Type value)
    {
        AddTreeNodeInside(root, key, value, nullptr);
    }
    TypeKey Search(TypeKey key)
    {
        MyTreeNode<TypeKey, Type>* temp = SearchNode(root, key);
        if (temp != nullptr)
            return temp->data.first;
        else return 0;
    }
    QString PrintInDirectOrder()
    {
        PrintInDirectOrderInside(root);
        QString result = ResultInDirectOrder;
        ResultInDirectOrder.clear();
        return result;
    }
    QString PrintInReverseOrder()
    {
        PrintInReverseOrderInside(root);
        QString result = ResultInReverseOrder;
        ResultInReverseOrder.clear();
        return result;
    }
    QString PrintInAscendingOrder()
    {
        PrintInAscendingOrderInside(root);
        QString result = ResultInAscendingOrder;
        ResultInAscendingOrder.clear();
        return result;
    }
    QString Clear()
    {
        ClearInside(root);
        if(!root)
            return "The tree is cleared";
        else
            return "Ops, something goes wrong";
    }
    void Remove(TypeKey key)
    {
        RemoveInside(root, key);
    }
    MyTreeNode<TypeKey, Type>* GetRoot()
    {
        if (root)
            return root;
        else
            return 0;
    }
     MyTreeNode<TypeKey, Type>* GetSearch(TypeKey key)
    {
        MyTreeNode<TypeKey, Type>* temp = SearchNode(root, key);
        if (temp != nullptr)
            return temp;
        else return 0;
    }
};
#endif // MYTREE_H
