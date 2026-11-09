#include <iostream>
#include "DList.h"

using namespace std;

void question1();
void question2();
void question3();
void question4();
void question5();
void question6();
int main()
{
    question6();
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
template <class T>
bool isPalindrome(DList<T>& lst)
{
    DListIterator<T> st = lst.getIterator();
    DListIterator<T> en = lst.getIterator();
    en.end();
   
    while(en.isValid()  && st.isValid() && *en == *st)
    {
        st++;
        en--;
    }
    return !en.isValid() && !st.isValid();
}
void question4()
{
    string arr[] = { "navan", "derid", "asdffdsa" };
    for (int i = 0; i < 3;i++)
    {
        DList<char> word;
        for (int x = 0; x < arr[i].size();x++)
        {
            word.append(arr[i][x]);
        }
        cout << arr[i] << ": " << (isPalindrome(word) ? "Yes" : "No") << endl;
    }
}
template <class T>
void display(T* arr, int size)
{
    for (int i = 0; i < size;i++)
    {
        if (i != 0)
            cout << ", ";
        cout << arr[i];
    }
    cout << endl;
}
template <class T>
void populate(DList<T>& lst, T* arr, int size)
{
    for (int i = 0; i < size;i++)
    {
        lst.prepend(arr[i]);
    }
}
void question5()
{
    const int size = 10;
    int arr[size];
    for (int i = 0; i < size;i++)
    {
        arr[i] = 1 + rand() % size;
    }
    display(arr, size);
    DList<int> nums;
    populate(nums, arr, size);
    print(nums);
}

template <class T>
struct MyNode
{
    T data;
    MyNode<T>* next;
    MyNode<T>* previous;
    MyNode()
    {
        next = previous = nullptr;
    }
    MyNode(T item)
    {
        data = item;
        next = previous = nullptr;
    }

};

template <class T>
void print(MyNode<T>* st)
{
    while (st != nullptr)
    {
        cout << st->data;
        if (st->next != nullptr)
            cout << "->";
        st = st->next;
    }
    cout << endl;
}
template <class T>
void swap(MyNode<T>* B)
{
    if (B->next != nullptr)
    {
        MyNode<T>* A = B->previous;
        MyNode<T>* C = B->next;
        MyNode<T>* D = C->next;
        if (A != nullptr)
            A->next = C;
        B->next = D;
        B->previous = C;
        C->next = B;
        C->previous = A;
        if (D != nullptr)
            D->previous = B;
    }
}
template <class T>
void swapAdjacent(MyNode<T>* st)
{
    while (st != nullptr)
    {
        swap(st);
        st = st->next;
    }
}
void question6()
{
    MyNode<int>* startNode = new MyNode<int>(1);
    MyNode<int>* st = startNode;
    int i = 2;
    while (i <= 11)
    {
        st->next = new MyNode<int>(i);
        st->next->previous = st;
        st = st->next;
        i++;
    }
    print(startNode);
    swapAdjacent(startNode);
    startNode = startNode->previous;
    print(startNode);
}
