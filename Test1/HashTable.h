#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <memory.h>
#include <assert.h>

static const float DEFAULT_LOAD_FACTOR = 0.75f;
template<typename T>
class HashTable
{

static const int DEFAULT_INITIAL_CAPACITY = 16;
static const int MAXIMAL_CAPACITY = 1 << 30;


public:
struct Node
{
public:
    Node(T _value, int _hash)
    {
        next = 0;
        value = _value;
        hash  = _hash;
    }
    int hash;
    T value;
    Node* next;
};

typedef int (*HASH_FUNCTION)(T);
public:
//    HashTable(HASH_FUNCTION _hash);
    HashTable(HASH_FUNCTION _hash)
    {
        mLoadFactor = DEFAULT_LOAD_FACTOR;
        table = new Node*[DEFAULT_INITIAL_CAPACITY];
        memset(table, 0, DEFAULT_INITIAL_CAPACITY * sizeof(Node*));
        mTreshold = (int)(mLoadFactor * DEFAULT_INITIAL_CAPACITY);
        mCapacity = DEFAULT_INITIAL_CAPACITY;
        mSize = 0;
        hashFunc = _hash;
        //set table to zero - pointers;

    }
    HashTable(int initialCapacity, float loadFactor, HASH_FUNCTION _hash)
    {

        assert(initialCapacity <0);

        if(initialCapacity > MAXIMAL_CAPACITY)
        {
            initialCapacity = MAXIMAL_CAPACITY;
        }

        mCapacity = 1;
        while (mCapacity < initialCapacity)
        {
            mCapacity = mCapacity << 1;
        }
        mLoadFactor = loadFactor;
        mTreshold = int(mLoadFactor * mCapacity);
        table = new Node*[mCapacity];
        memset(table, 0, sizeof(Node*)* mCapacity);
        mSize = 0;
        hashFunc = _hash;

    }

    ~HashTable()
    {
        for (int i = 0; i < mCapacity; i++)
        {
            Node* bucket = table[i];
            while (bucket)
            {
                Node* next = bucket->next;
                delete bucket;
                bucket = next;
            }
        }

        delete[] table;
    }
    void insert(T value)
    {
        int hash =  hashFunc(value);
        int i = indexFor(hash, mCapacity);
        Node* bucket = table[i];

        while (bucket)
        {
            if (bucket->hash == i &&
                    bucket->value == value)
            {
                return;
            }
            bucket = bucket->next;
        }

        Node*  newNode = new Node(value, hash);
        newNode->next = table[i];
        table[i] = newNode;

        if (mSize++ >= mTreshold)
        {
            resize(2 * mCapacity);
        }
    }

//    void remove (T value)
//    {
//        int hash = hashFunc;
//        int i = indexFor(hash, mCapacity);
//        Node* bucket = table[i];
//        while (bucket)
//        {

//        }
//    }
    bool contains(T value)
    {
        int hash = hashFunc(value);
        int i = indexFor(hash, mCapacity);
        Node* bucket = table[i];

        while (bucket)
        {
            if (value == bucket->value)
            {
                return true;
            }
            bucket = bucket->next;
        }

        return false;
    }

private:

    Node** table;
    float mLoadFactor;
    int mTreshold; // capacity * loadFactor;
    int mCapacity;
    int mSize;
    HASH_FUNCTION hashFunc;
    int indexFor(int h, int length)
    {
        return h & (length - 1);
    }

    void resize (int newCapacity)
    {
        Node** oldTable = table;
        int oldCapacity = mCapacity;
        if (oldCapacity == MAXIMAL_CAPACITY)
        {
            oldCapacity == MAXIMAL_CAPACITY;
            return;
        }

        //Transfer
        Node** newTable = new Node*[newCapacity];
        for (int i = 0; i < mCapacity; i++)
        {
            Node* bucket = table[i];
            if (bucket)
            {
                table[i] = 0;
            }
            do{
                Node* next = bucket->next;
                int i = indexFor(next->hash, newCapacity);
                bucket->next = newTable[i];
                newTable[i]= bucket;
                bucket = next;
            } while (bucket);
        }
        //
        delete[] table;
        table = newTable;
        memset(newTable, 0, sizeof(Node*) * newCapacity);
        mTreshold = int (newCapacity * mLoadFactor);


    }

};
#endif // HASHTABLE_H
