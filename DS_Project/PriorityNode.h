#pragma once

////#ifndef _NODE
////#define _NODE
template < typename T>
class PriorityNode
{
private:
	T item; // A data item
	PriorityNode<T>* next; // Pointer to next node
	float Priority;
public:
	PriorityNode();
	PriorityNode(const T& r_Item, float);
	PriorityNode(const T& r_Item, PriorityNode<T>* nextNodePtr);
	void setItem(const T& r_Item);
	void setNext(PriorityNode<T>* nextNodePtr);
	void setPriority(float);
	float GetPriority();
	T getItem() const;
	PriorityNode<T>* getNext() const;
}; // end Node

template < typename T>
PriorityNode<T>::PriorityNode()
{
	next = nullptr;
}

template < typename T>
PriorityNode<T>::PriorityNode(const T& r_Item, float t)
{
	item = r_Item;
	next = nullptr;
	Priority = t;
}

template < typename T>
PriorityNode<T>::PriorityNode(const T& r_Item, PriorityNode<T>* nextNodePtr)
{
	item = r_Item;
	next = nextNodePtr;
}
template < typename T>
void PriorityNode<T>::setItem(const T& r_Item)
{
	item = r_Item;
}

template < typename T>
void PriorityNode<T>::setNext(PriorityNode<T>* nextNodePtr)
{
	next = nextNodePtr;
}

template < typename T>
T PriorityNode<T>::getItem() const
{
	return item;
}

template < typename T>
PriorityNode<T>* PriorityNode<T>::getNext() const
{
	return next;
}
template < typename T>
void PriorityNode<T>::setPriority(float t)
{
	if (t > 0)
		Priority = t;
}
template < typename T>
float PriorityNode<T>::GetPriority()
{
	return Priority;
}
//#endif


