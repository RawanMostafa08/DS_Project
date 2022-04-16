#pragma once
#include"PriorityNode.h"
/*
This is a program that implements the queue abstract data type using a linked list.
The queue is implemented as a chain of linked nodes that has two pointers,
a frontPtr pointer for the front of the queue and a backPtr pointer for the back of the queue.
*/

/*

The Node: item of type T and a "next" pointer
-------------
| item| next | --->
-------------
General Queue case:

frontPtr																backPtr
\											   						/
\											  					   /
------------- 	  ------------- 	  ------------- 	  -------------
| item| next |--->| item| next |--->  | item| next |--->  | item| next |---> NULL
------------- 	  ------------- 	  ------------- 	  -------------

Empty Case:

frontptr	 backptr
\	 /
\	/
---- NULL ------


Single Node Case:
frontPtr	 backPtr
\		/
\	   /
-----------
|item| next| -->NULL
-----------

*/

//#ifndef PRIORITY_QUEUE_
//#define PRIORITY_QUEUE_


#include "PriorityQueueADT.h"
#include <vector>
using namespace std;


template <typename T>
class PriorityQueue :public PriorityQueueADT<T>
{
private:

	PriorityNode<T>* backPtr;
	PriorityNode<T>* frontPtr;

public:
	PriorityQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry, float x);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	//void DeleteDuplicates(PriorityQueue<T>& LQ);
	~PriorityQueue();

	//copy constructor
	PriorityQueue(const PriorityQueue<T>& LQ);
};
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: Queue()
The constructor of the Queue class.

*/

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool PriorityQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool PriorityQueue<T>::enqueue(const T& newEntry, float t)
{
	PriorityNode<T>* prev = frontPtr;
	PriorityNode<T>* ptr = frontPtr->getNext();
	PriorityNode<T>* newNodePtr = new PriorityNode<T>(newEntry, t);
	// Insert the new node
	if (isEmpty())	//special case if this is the first node to insert
	{
		frontPtr = newNodePtr;
		return true;	// The queue is empty
	}
	else
	{
		if ((newNodePtr->GetPriority() <= frontPtr->GetPriority()))
		{
			newNodePtr->setNext(frontPtr);
			frontPtr = newNodePtr;
			return true;
		}
		while (ptr->getNext())
		{
			if (newNodePtr->GetPriority() <= ptr->GetPriority())
			{
				newNodePtr->setNext(ptr);
				prev->setNext(newNodePtr);
				return true;
			}
			else
			{
				ptr = ptr->getNext();
				prev = prev->getNext();
			}
		}
		backPtr->setNext(newNodePtr); // The queue was not empty
		backPtr = newNodePtr; // New node is the last node now
		return true;
	}
} // end enqueue


  /////////////////////////////////////////////////////////////////////////////////////////////////////////

  /*Function: dequeue
  Removes the front of this queue. That is, removes the item that was added
  earliest.

  Input: None.
  Output: True if the operation is successful; otherwise false.
  */

template <typename T>
bool PriorityQueue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	PriorityNode<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
		backPtr = nullptr;

	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;

	return true;

}
/////////////////////////////////////////////////////////////////////////////////////////
/*
Function: peek
copies the front of this queue to the passed param. The operation does not modify the queue.

Input: None.
Output: The front of the queue.
*/
template <typename T>
bool PriorityQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}
///////////////////////////////////////////////////////////////////////////////////
/*
Function: destructor
removes all nodes from the queue by dequeuing them
*/
template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
	T temp;

	//Free (Dequeue) all nodes in the queue
	while (dequeue(temp));
}
/////////////////////////////////////////////////////////////////////////////////////////
/*
Function: Copy constructor
To avoid shallow copy,
copy constructor is provided

Input: LinkedQueue<T>: The Queue to be copied
Output: none
*/

template <typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& LQ)
{
	PriorityNode<T>* NodePtr = LQ.frontPtr;
	if (!NodePtr) //LQ is empty
	{
		frontPtr = backPtr = nullptr;
		return;
	}

	//insert the first node
	PriorityNode<T>* ptr = new PriorityNode<T>(NodePtr->getItem());
	frontPtr = backPtr = ptr;
	NodePtr = NodePtr->getNext();

	//insert remaining nodes
	while (NodePtr)
	{
		PriorityNode<T>* ptr = new PriorityNode<T>(NodePtr->getItem());
		backPtr->setNext(ptr);
		backPtr = ptr;
		NodePtr = NodePtr->getNext();
	}
}
//#endif



