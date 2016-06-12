#include <iostream>
#include <TestSorts.h>
#include <LinkedList.h>
#include <CircularList.h>
#include <HashTable.h>


int hashStr(std::string str)
{
    int hash = 5381;


    for(int i = 0; i < str.size(); i++)
    {
        hash = ((hash << 5) + hash) + (int)str[i]; /* hash * 33 + c */
    }
    return hash;
}

int main(int argc, char *argv[])
{

    TestSorts testSorts = TestSorts();

    testSorts.testMergeSort();
    testSorts.testQuickSort();
    std::cout << "Linked List"<< std::endl;
    LinkedList<float> a;
    a.insert(7.f);
    a.insert(5.f);
    a.insert(3.f);
    a.insert(1.f);
    a.insert(0.f);
    std::cout << a.size() <<std::endl;
    a.printList();

    std::cout << std::endl;
    Node<float>* node = a.head();
    node = node->next->next;
    a.removeNode(node);
    a.printList();

    CircularList<std::string> circulatList;

    circulatList.insert("A");
    circulatList.insert("B");
    circulatList.insert("C");
    circulatList.insert("D");
//    CircularList<std::string>::Node* node = circulatList.mHead->next->next;

    CircularList<std::string>::Node* nodeToAppend = circulatList.mHead->next->next;
    circulatList.insert("E", nodeToAppend);

    std::cout << circulatList.getCycle()<<std::endl;

    HashTable<std::string>* table = new HashTable<std::string>(hashStr);

    table->insert("A");
    table->insert("B");
    table->insert("C");
    table->insert("D");
    table->insert("E");
    table->insert("F");
    std::cout << "contains test"<< table->contains("C")<<std::endl;
    std::cout << "Contains test" << table->contains("ABC")<<std::endl;


    delete table;

    return 0;
}
