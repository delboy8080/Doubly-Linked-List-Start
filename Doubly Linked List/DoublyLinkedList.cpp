#include <iostream>
#include "DList.h"

using namespace std;

void question1();
void question2();
void question3();
int main()
{
    question3();
    return 0;
}

template <class T>
void print(DList<T>& list)
{
    DListIterator<T> iter = list.getIterator();
    while (iter.isValid())
    {
        cout << *iter ;
        iter++;
        if (iter.isValid())
            cout << ", ";
    }
    cout << endl;
}
template <class T>
void printInReverse(DList<T>& list)
{
    DListIterator<T> iter = list.getIterator();
    iter.end();
    while (iter.isValid())
    {
        cout << *iter;
        iter--;
        if (iter.isValid())
            cout << ", ";
    }
    cout << endl;
}
void question1()
{
    DList<int> nums;
    for (int i = 1; i <= 10; i++)
    {
        nums.append(i);
    }
    print(nums);
    printInReverse(nums);
}

template <class T>
void removeDuplicates(DList<T>& items)
{
    DListIterator<T> outter = items.getIterator();
    while (outter.isValid())
    {
        DListIterator<T> inner(outter);
        inner++;
        while (inner.isValid())
        {
            if (*inner == *outter)
            {
                inner = items.remove(inner);
            }
            else
            {
                inner++;
            }
        }
        outter++;
    }
}
void question2()
{
    srand(time(NULL));
    DList<char> nums;
    for (int i = 0; i < 10;i++)
    {
        nums.append(65 + rand() % 5);
    }
    print(nums);
    removeDuplicates(nums);
    print(nums);
}

template <class T>
void merge(DList<T>& A, DList<T>& B, DList<T>& merged)
{
    DListIterator<T> aIt = A.getIterator();
    DListIterator<T> bIt = B.getIterator();
    while (aIt.isValid() || bIt.isValid())
    {
        if (aIt.isValid() && bIt.isValid() && *aIt < *bIt)
        {
            merged.append(*aIt);
            aIt++;
        }
        else if (aIt.isValid() && bIt.isValid() && *aIt >= *bIt)
        {
            merged.append(*bIt);
            bIt++;
        }
        else if (aIt.isValid())
        {
            merged.append(*aIt);
            aIt++;
        }
        else
        {
            merged.append(*bIt);
            bIt++;
        }
    }
}

void question3()
{
    DList<int> a, b, merged;
    for (int i = 1; i < 10;i+=2)
    {
        a.append(i);
        b.append(i + 1);
    }
    b.append(11);
    merge(a, b, merged);
    print(a);
    print(b);
    print(merged);
}