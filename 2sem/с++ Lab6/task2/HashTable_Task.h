#ifndef HASHTABLE_TASK_H
#define HASHTABLE_TASK_H
#include"HashTable.h"
template <typename Type, typename TypeKey>
class HashTable_Task: public HashTable<Type, TypeKey>
{
public:
    HashTable_Task(): HashTable<Type, TypeKey>(){}
    void Task()
    {
        for (int i = 0; i < 10; ++i)
        {
            HashStack<Type, TypeKey>* currentStack = HashTable<Type, TypeKey>::table[i];
            HashStack<Type, TypeKey>* temp = new HashStack<Type, TypeKey>;
            while (!currentStack->Empty())
            {
                if (currentStack->Peek_Key() < 0)
                {
                    currentStack->Pop();
                }
                else
                {
                    temp->Push(currentStack->Peek_Data(), currentStack->Peek_Key());
                    currentStack->Pop();
                    HashTable<Type, TypeKey>::table[i] = temp;
                }
            }
        }
    }


};
#endif // HASHTABLE_TASK_H
