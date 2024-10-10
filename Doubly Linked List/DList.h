template <class T> class DList;
template <class T> class DListIterator;
template <class T> class DListNode;
#pragma once
#include "DListNode.h"
#include "DListIterator.h"

template <class T>
class DList
{
public:
	DListNode<T> *head, *tail;
	int count;

	DList();
	DList(DList<T> &list);
	void append(T item);
	void prepend(T item);
	void removeHead();
	void removeTail();
	DListIterator<T> getIterator();
	void insert(DListIterator<T> &iter, T item);
	DListIterator<T> remove(DListIterator<T> &iter);
	int size();
	~DList();
};

template <class T>
DList<T>::DList(DList<T> &list)
{
	head = nullptr;
	tail = nullptr;
	DListNode<T> *current, *next, *previous;
	current = list.head;
	while (current != nullptr)
	{
		this->append(current->data);
		current = current->next;
	}
}
template <class T>
int DList<T>::size()
{
	return count;
}
template <class T>
DList<T>::DList()
{
	count = 0;
	head = tail = nullptr;
}
template <class T>
void DList<T>::append(T item)
{
	
}

template <class T>
void DList<T>::prepend(T item)
{
	
}

template <class T>
void DList<T>::removeHead()
{
	
}

template <class T>
void DList<T>::removeTail()
{
	
}
template <class T>
DListIterator<T> DList<T>::getIterator()
{
	return DListIterator<T>(this, head);
}
template <class T>
void DList<T>::insert(DListIterator<T> &iter, T item)
{
	
}

template <class T>
DListIterator<T> DList<T>::remove(DListIterator<T> &iter)
{
	
	return iter;
}

template <class T>
DList<T>::~DList()
{
	DListNode<T> *iter, *next=nullptr;
	iter = head;
	while(iter != nullptr )
	{
		next = iter->next;
		delete iter;
		iter = next;
		
	}
	head = nullptr;
	tail = nullptr;
}