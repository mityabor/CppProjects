#ifndef SORT_H
#define SORT_H

template<typename T>
void genSwap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
int pivot(T* a, int p, int r)
{
    T x = a[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; j++)
    {
        if(a[j]  <= x)
        {
            i++;
            genSwap(a[i], a[j]);

        }
    }

    genSwap(a[i + 1], a[r]);
    return i + 1;
}

template<typename T>
void quickSort(T* a, int p ,int r)
{
    if(p < r)
    {
        int q = pivot(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
    }
}


template<typename  T>
void quickSort(T* a, int n)
{
    quickSort(a, 0 , n - 1);
}


template<typename T>
void merge(T* a, T* b, int s1, int e1,  int e2)
{
    int cnt1 = s1;
    int cnt2 = e1+1;
    for(int i = s1; i <= e2; i++)
    {
        if ((a[cnt1] <= a[cnt2] && cnt1 <= e1) ||(cnt2 > e2))
        {
            b[i] = a[cnt1++];
        }
        else
        {
            b[i] = a[cnt2++];
        }
    }

    for (int i = s1; i <= e2; i++)
    {
        a[i] = b[i];
    }

}

template<typename T>
void mergeSort(T* a, T* b,int start1, int end1, int end2)
{
    if (end2 <= start1)
    {
        return;
    }
    mergeSort(a, b, start1, (start1+end1)/2 ,end1);
    mergeSort(a, b, end1 + 1, (end1+1+end2)/2 ,end2);
    merge(a, b, start1, end1, end2);
}


template<typename T>
void mergeSort(T* a, int size)
{
    T* b = new T[size];
    mergeSort(a, b, 0, size / 2, size - 1);
    delete[] b;
}


#endif // SORT_H
