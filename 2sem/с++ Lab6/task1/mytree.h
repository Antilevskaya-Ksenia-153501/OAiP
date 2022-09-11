#ifndef MYTREE_H
#define MYTREE_H
#include<QString>

template <typename Type, typename TypeKey>
struct MyTreeNode
{
    Type data;
    public:TypeKey key;
    MyTreeNode* right;
    MyTreeNode* left;
    int balance;
    MyTreeNode()
    {
        this->data = Type();
        this->key = TypeKey();
        right = nullptr;
        left = nullptr;
        balance = 0;
    }
};
template <typename Type, typename TypeKey>
class MyTree
{
protected:
    MyTreeNode<Type, TypeKey>* root;
    QString ResultInDirectOrder;
    QString ResultInReverseOrder;
    QString ResultInAscendingOrder;
    void PrintInDirectOrderInside(const MyTreeNode<Type, TypeKey>* root)
    {
        if (root != nullptr)
        {
            ResultInDirectOrder += QString::number(root->key) + " ";
            if(root->left)
                PrintInDirectOrderInside(root->left);
            if(root->right)
                PrintInDirectOrderInside(root->right);
        }
    }
    void PrintInReverseOrderInside(const MyTreeNode<Type, TypeKey>* root)
    {
        if (root != nullptr)
        {
            if(root->left)
                PrintInReverseOrderInside(root->left);
            if(root->right)
                PrintInReverseOrderInside(root->right);
           ResultInReverseOrder += QString::number(root->key) + " ";
        }
    }
    void PrintInAscendingOrderInside(const MyTreeNode<Type, TypeKey>* root)
    {
        if (root != nullptr)
        {
            if(root->left)
                PrintInAscendingOrderInside(root->left);
            ResultInAscendingOrder += QString::number(root->key) + " ";
            if(root->right)
                PrintInAscendingOrderInside(root->right);
        }
    }
    int Height(MyTreeNode<Type, TypeKey>* root)
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
    void SetBalance(MyTreeNode<Type, TypeKey>*(&root))
    {
        if (root != nullptr)
            root->balance = Height(root->right) - Height(root->left);
    }
    void TurnRight(MyTreeNode<Type, TypeKey>*(&root))
    {
        MyTreeNode<Type, TypeKey> *LeftNode, *LeftNodeRightNode;
        LeftNode = root->left;
        LeftNodeRightNode = LeftNode->right;

        LeftNode->right = root;
        root->left = LeftNodeRightNode;
        root = LeftNode;
        SetBalance(root->right);
        SetBalance(root);
    }
    void TurnLeft(MyTreeNode<Type, TypeKey>*(&root))
    {
        MyTreeNode<Type, TypeKey> *RightNode, *RightNodeLeftNode;
        RightNode = root->right;
        RightNodeLeftNode = RightNode->left;

        RightNode->left = root;
        root->right = RightNodeLeftNode;
        root = RightNode;
        SetBalance(root->left);
        SetBalance(root);
    }
    void AddTreeNodeInside(MyTreeNode<Type, TypeKey>*(&root), Type data, TypeKey key)
    {
        if (root == nullptr)
        {
            root = new MyTreeNode<Type, TypeKey>();
            root->data = data;
            root->key = key;
        }
        else
        {
            if (key > root->key)
            {
                AddTreeNodeInside(root->right, data, key);
                if (Height(root->right) - Height(root->left) > 1)
                {
                    if(Height(root->right->right) < Height(root->right->left))
                        TurnRight(root->right);
                    TurnLeft(root);
                }
            }
            else if (key < root->key)
            {
                AddTreeNodeInside(root->left, data, key);
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
    MyTreeNode<Type, TypeKey>* SearchNode(MyTreeNode<Type, TypeKey>* root, TypeKey findKey)
    {
        if (root->key == findKey)
            return root;
        if (root->key > findKey)
        {
            if (root->left)
                return SearchNode(root->left, findKey);
            else
                return nullptr;
        }
        else
            return root->right ? SearchNode(root->right, findKey) : nullptr;
    }
    void RemoveInside(MyTreeNode<Type, TypeKey>*(&root), TypeKey deleteKey)
    {
        if(root == NULL)
            return;
        if(deleteKey < root->key)
             RemoveInside(root->left, deleteKey);
        else if(deleteKey > root->key)
            RemoveInside(root->right, deleteKey);
        else
        {
            MyTreeNode<Type, TypeKey>* r = root->right;
            if(root->right == nullptr)
            {
                MyTreeNode<Type, TypeKey>* l = root->left;
                delete(root);
                root = l;
            }
            else if(root->left == nullptr)
            {
                delete(root);
                root = r;
            }
            else
            {
                while(r->left != nullptr)
                    r = r->left;
                root->key = r->key;
                RemoveInside(root->right, r->key);
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
    void ClearInside(MyTreeNode<Type, TypeKey>*(&root))
    {
        if (root != nullptr)
        {
            ClearInside(root->left);
            ClearInside(root->right);
            delete root;
            root = nullptr;
        }
    }
    void TaskInside(MyTreeNode<Type, TypeKey>* (&root), TypeKey findKey)
    {
        if (root->key == findKey)
        {
            ClearInside(root);
            return;
        }
        if (root->key > findKey)
        {
            if (root->left)
               TaskInside(root->left, findKey);
            else
                return;
        }
        else
        if (root->right)
           TaskInside(root->right, findKey);
        else
            return;
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
    void AddTreeNode(Type data, TypeKey key)
    {
        AddTreeNodeInside(root, data, key);
    }
    Type Search(TypeKey key)
    {
        MyTreeNode<Type, TypeKey>* temp = SearchNode(root, key);
        if (temp != nullptr)
            return temp->data;
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
    MyTreeNode<Type, TypeKey>* GetRoot()
    {
        if (root)
            return root;
        else
            return 0;
    }
};

#endif // MYTREE_H
