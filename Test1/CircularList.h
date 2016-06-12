#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H



template<typename T>
class CircularList
{
public:
    struct Node
    {
        T value;
        Node* next;
        Node(T _value)
        {
            value = _value;
            next = 0;
        }
    };
public:
    CircularList()
    {
        mHead = 0;
    }
    void insert(T value, Node* next = 0)
    {
        if (!mHead)
        {
            mHead = new Node(value);
        }

        else
        {
            Node* currentNode = mHead;
            while (currentNode->next)
            {
                currentNode = currentNode->next;
            }
            currentNode->next = new Node(value);

            currentNode = currentNode->next;
            if(next)
            {
                currentNode->next = next;
            }
        }

    }

    T  getCycle()
    {
        Node* currentNodeSlow = mHead;
        Node* currentNodeFast = mHead;

        while (currentNodeSlow->next && currentNodeFast->next->next)
        {
            currentNodeFast  = currentNodeFast->next->next;
            currentNodeSlow = currentNodeSlow->next;

            if(currentNodeFast ==  currentNodeSlow)
            {
                return currentNodeFast->value;
            }
        }

    }

    Node* mHead;
private:

};

#endif // CIRCULARLIST_H
