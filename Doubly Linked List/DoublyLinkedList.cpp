#include <iostream>
#include "DList.h"

using namespace std;

template <class T>
void print(DList<T>& list)
{
    DListIterator<T> it = list.getIterator();
    while (it.isValid())
    {
        cout << *it;
        
        if (!it.isEnd())
        {
            cout << ", ";
        }
        it++;
    }
    cout << endl;
}


void question1();
void question2();
void question3();
int main()
{
    question3();
    return 0;
}
template <class T>
void printReverse(DList<T>& nums)
{
    DListIterator<T> it = nums.getIterator();
    it.end();
    while (it.isValid())
    {
        cout << *it;
        if (!it.isStart())
        {
            cout << ", ";
        }
        it--;
    }
}
void question1()
{
    DList<int> nums;
    for (int i = 1; i <= 10;i++)
    {
        nums.append(i);
    }
    print(nums);
    printReverse(nums);
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
    DList<char> items;
    for (int i = 0; i < 20;i++)
    {
        items.append(65 + rand() % 5);
    }
    print(items);
    removeDuplicates(items);
    print(items);
}
template <class T>
void merge(DList<T>& A, DList<T>& B, DList<T>& merged)
{
    DListIterator<T> aIt = A.getIterator();
    DListIterator<T> bIt = B.getIterator();
    while (aIt.isValid() || bIt.isValid())
    {
        if (aIt.isValid() && bIt.isValid())
        {
            if (*aIt < *bIt)
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
    DList<int> A,B, merged;
    for (int i = 1; i < 10; i += 2)
    {
        A.append(i);
        B.append(i + 1);
    }
    A.append(11);
    A.append(12);
    A.append(13);

    merge(A, B, merged);
    print(A);
    print(B);
    print(merged);

}