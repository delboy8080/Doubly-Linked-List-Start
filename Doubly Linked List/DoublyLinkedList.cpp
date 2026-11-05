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
        it++;
        if (it.isValid())
        {
            cout << ", ";
        }
    }
    cout << endl;
}

void question1();
void question2();
void question3();
void question4();

int main()
{
    question4();
    return 0;
}
template <class T>
void printReverse(DList<T> items)
{
    DListIterator<T> it = items.getIterator();
    it.end();
    while (it.isValid())
    {
        cout << *it;
        it--;
        if (it.isValid())
        {
            cout << ", ";
        }
    }
    cout << endl;
}
void question1()
{
    DList<int> nums;
    for (int i = 0; i < 10;i++)
    {
        nums.append(i + 1);
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
    for (int i = 0; i < 10;i++)
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
        else if (bIt.isValid() == false)
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
    DList<int> A, B, M;
    for (int i = 1; i < 5; i ++)
    {
        A.append(i);
        B.append(i * 2);
    }
    A.append(11);
    A.append(12);
    A.append(13);

    merge(A, B, M);
    print(A);
    print(B);
    print(M);
}

template <class T>
bool isPalindrome(DList<T>& lst)
{
    DListIterator<T>st, en;
    st = lst.getIterator();
    en = lst.getIterator();
    en.end();
    while (st.isValid() && en.isValid())
    {
        if (*st != *en)
            return false;
        st++;
        en--;
    }
    return true;
}

void question4()
{
    string words[] = { "navan", "derek", "naan" };
    for (int i = 0; i < 3;i++)
    {
        DList<char> items;
        for (int x = 0; x < words[i].size();x++)
        {
            items.append(words[i][x]);
        }

        print(items);
        cout << (isPalindrome(items) ? "Yes" : "No") << endl;
    }
}