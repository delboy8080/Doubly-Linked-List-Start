#pragma once

template <class T>
class DListNode
{
public:
	T data;
	DListNode<T> *next;
	DListNode<T> *previous;

	DListNode(T item);
	DListNode(DListNode<T> &item);
	void insertBefore(T item);
	void insertAfter(T item);

	~DListNode()
	{
		//next = nullptr;
		//previous = nullptr;
	}
};


template <class T>
DListNode<T>::DListNode(DListNode<T> &node)
{
	this->data = new DListNode(node->data);
}
template <class T>
DListNode<T>::DListNode(T item)
{
	data = item;
	next = previous = nullptr;
}

template <class T>
void DListNode<T>::insertAfter(T item)
{
	DListNode<T>* temp = new DListNode(item);
	temp->next = this->next;
	temp->previous = this;
	this->next = temp;
	if (temp->next != nullptr)
	{
		temp->next->previous = temp;
	}
}

template <class T>
void DListNode<T>::insertBefore(T item)
{
	DListNode<T>* temp = new DListNode(item);
	temp->next = this;
	temp->previous = this->previous;
	this->previous = temp;
	if (temp->previous != nullptr)
	{
		temp->previous->next = temp;
	}
}
