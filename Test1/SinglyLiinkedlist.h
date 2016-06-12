#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

template<typename T>
struct Node
{
public:
    Node (T _value)
    {
        value = _value;
    }
    Node* next;
    T value;
};




#endif // SINGLYLINKEDLIST_H
