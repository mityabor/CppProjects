#include "TestSorts.h"
#include "iostream"


void TestSorts::testQuickSort()
{
    std::cout << "QuickSort" << std::endl;
    float a[5] =  {5.f, 1.f, 3.f, 7.f, -1.f};
    float b[1] = {0.f};
    float c[10] = {11.f, 10.f, 8.f, 7.f, 6.f, 5.f, 4.f, 3.f, 2.f, -100.f};\
    int d[5] = {5, 4, 3, 2 ,1};
    quickSort(a, 5);
    quickSort(b, 1);
    quickSort(c, 10);
    quickSort(d, 5);
    std::cout << "A = " << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout<< a[i] << std::endl;
    }
    std::cout << "B = " << std::endl;
    for (int i = 0; i < 1; i++)
    {
        std::cout << b[i] << std::endl;
    }

    std::cout << "C = " << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << c[i] << std::endl;
    }

    std::cout << "D = " << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << d[i] << std::endl;
    }
}

void TestSorts::testMergeSort()
{   std::cout << "Merge Sort" << std::endl;
    float a[5] =  {5.f, 1.f, 3.f, 7.f, -1.f};
    float b[1] = {0.f};
    float c[10] = {11.f, 10.f, 8.f, 7.f, 6.f, 5.f, 4.f, 3.f, 2.f, -100.f};\
    int d[5] = {5, 4, 3, 2 ,1};
    mergeSort(a, 5);
    mergeSort(b, 0);
    mergeSort(c, 10);
    mergeSort(d, 5);
    std::cout << "A = " << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout<< a[i] << std::endl;
    }
    std::cout << "B = " << std::endl;
    for (int i = 0; i < 1; i++)
    {
        std::cout << b[i] << std::endl;
    }

    std::cout << "C = " << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << c[i] << std::endl;
    }

    std::cout << "D = " << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << d[i] << std::endl;
    }
}
