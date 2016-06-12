#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>


template<typename T>
struct Node
{
    T value;
public:
    Node(T _value)
    {
        value = _value;
        prev  = 0;
        next = 0;
    }
    Node* next;
    Node* prev;
};
template<typename T>
class LinkedList
{
public:
    LinkedList()
    {
        mHead = 0;
        mTail = 0;
        mSize = 0;
    }

    void insert(const T& value)
    {
        if (mSize == 0) {
            mHead = new Node<T>(value);

        }
        else if (mSize == 1) {
            mTail = new Node<T>(value);
            mTail->prev = mHead;
            mHead->next = mTail;
        }
        else {
            Node<T>* prev = mTail;
            Node<T>* newTail = new Node<T>(value);
            newTail->prev = prev;
            prev->next = newTail;
            mTail = newTail;
        }
        mSize++;

    }

    void removeNode(Node<T>* c)
    {
        if (!c && !c->prev && !c->next)
        {
            return;
        }

        Node<T>* prev = c->prev;
        Node<T>* next = c->next;
        prev->next = next;
        c->prev = 0;
        c->next = 0;

        delete c;
        mSize--;
    }

    int size()
    {
        return mSize;
    }

    void printList()
    {
        std::cout << "[";
        if(mSize > 0)
        {
            Node<T>* currentNode = mHead;
            std::cout << "iterating" <<std::endl;
            std::cout << currentNode->value;
            while(currentNode->next)
            {
                currentNode =  currentNode->next;
                std::cout << ", " << currentNode->value;
            }
        }
        std::cout << "]"<<std::endl;
    }

    Node<T>* head()
    {
        return mHead;
    }

private:
    Node<T>* mHead;
    Node<T>* mTail;
    int mSize;
};

#endif // LINKEDLIST_H
