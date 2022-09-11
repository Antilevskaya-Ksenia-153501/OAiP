#ifndef MYTREE_TASK_H
#define MYTREE_TASK_H
#include"mytree.h"

template <typename Type, typename TypeKey>
class MyTree_Task: public MyTree<Type, TypeKey>
{
public:
    MyTree_Task():MyTree<Type, TypeKey>(){}
    void Task(TypeKey findKey)
    {
        MyTree<Type, TypeKey>::TaskInside(MyTree<Type, TypeKey>::root, findKey);
        if (MyTree<Type, TypeKey>::root == nullptr)
            return;
        if (MyTree<Type, TypeKey>::Height(MyTree<Type, TypeKey>::root->right) - MyTree<Type, TypeKey>::Height(MyTree<Type, TypeKey>::root->left) > 1)
        {
            if(MyTree<Type, TypeKey>::Height(MyTree<Type, TypeKey>::root->right->right) < MyTree<Type, TypeKey>::Height(MyTree<Type, TypeKey>::root->right->left))
                MyTree<Type, TypeKey>::TurnRight(MyTree<Type, TypeKey>::root->right);
            MyTree<Type, TypeKey>::TurnLeft(MyTree<Type, TypeKey>::root);
        }
        if(MyTree<Type, TypeKey>::Height(MyTree<Type, TypeKey>::root->left) - MyTree<Type, TypeKey>::Height(MyTree<Type, TypeKey>::root->right) > 1)
        {
            if (MyTree<Type, TypeKey>::Height(MyTree<Type, TypeKey>::root->left->left) < MyTree<Type, TypeKey>::Height(MyTree<Type, TypeKey>::root->left->right))
                MyTree<Type, TypeKey>::TurnLeft(MyTree<Type, TypeKey>::root->left);
            MyTree<Type, TypeKey>::TurnRight(MyTree<Type, TypeKey>::root);
        }
        MyTree<Type, TypeKey>::SetBalance(MyTree<Type, TypeKey>::root);
    }

};

#endif // MYTREE_TASK_H
