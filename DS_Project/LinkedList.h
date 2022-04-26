#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"

template <typename T>
class LinkedList
{
private:
	Node<T>* Head;	//Pointer to the head of the list
	int Count;
	//You can add tail pointer too (depending on your problem)
public:


	LinkedList()
	{
		Head = nullptr;
		Count = 0;
	}
	int GetCount()
	{
		return Count;
	}
	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll();
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	void PrintList()	const
	{
		////cout << "\nprinting list contents:\n\n";
		//Node<T>* p = Head;
		//if(Count!=0)
		//{
		//	while (p->getNext())
		//	{
		//		cout << (*p).getItem() << ",";
		//		p = p->getNext();
		//	}
		//	cout << (*p).getItem();
		//}
		//
		//cout << "NULL\n";
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	*
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertBeg(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		R->setNext(Head);
		Head = R;

		Count++;
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
		Count = 0;
	}



	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions


	//[1]InsertEnd 
	//inserts a new node at end if the list
	void InsertEnd(const T& data)
	{
		if (Head == nullptr)
			InsertBeg(data);
		else
		{
			Node<T>* ptr = Head;
			while (ptr->getNext())
			{
				ptr = ptr->getNext();
			}
			Node<T>* newNode = new Node<T>(data);
			ptr->setNext(newNode);
			newNode->setNext(nullptr);
			Count++;
		}
	}

	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	bool Find(T &P)
	{
		if (Count==0)
			return false;
		if (Count == 1)
		{
			if (*(Head->getItem()) == *P)
			{
				P = Head->getItem();
				return true;
			}
			else
				return false;
		}
		if (Count > 1)
		{
			Node<T>* N = Head;
			while (N)
			{
				if (*(N->getItem()) == *P)
				{
					P = N->getItem();
					return true;
				}
				else
					N = N->getNext();
			}
			return false;
		}
	}

	//[3]CountOccurance
	//returns how many times a certain value appeared in the list
	int CountOccurance(const T& value)
	{
		int count = 0;
		Node<T>* ptr = Head;
		while (ptr)
		{
			if (ptr->getItem() == value)
			{
				count++;
			}
			ptr = ptr->getNext();
		}
		return count;
	}

	//[4] DeleteFirst
	//Deletes the first node in the list
	void DeleteFirst(T& temp)
	{	
		if (Count == 0)
		{
			return;
		}
		if (Count == 1)
		{
			temp = Head->getItem();
			delete Head;
			Head = nullptr;
			Count--;
			return;
		}
		if(Count>1)
		{
			Node<T>* delptr = Head;
			temp = Head->getItem();
			Head = Head->getNext();
			delete delptr;
			Count--;
			return;
		}
	}


	//[5] DeleteLast
	//Deletes the last node in the list
	void DeleteLast()
	{
		if (Head)
		{
			if (!Head->getNext())
				Head == nullptr;
			else
			{
				Node<T>* prev = Head;
				Node<T>* delptr = Head->getNext();
				while (delptr->getNext())
				{
					prev = prev->getNext();
					delptr = delptr->getNext();
				}
				prev->setNext(nullptr);
				delete delptr;
			}

		}
		Count -- ;
	}

	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNode(T& value)
	{
		if (Count == 0)
			return false;
		if (Count == 1)
		{
			if (*(Head->getItem()) == *value)
			{
				delete Head;
				Head = nullptr;
				Count = 0;
				return true;
			}
			else
				return false;
		}
		if (Count > 1)
		{
			if (*(Head->getItem()) == *value)
			{
				Node<T>* delptr = Head;
				Head = Head->getNext();
				delete delptr;
				Count--;
				return true;
			}
			else
			{
				Node<T>* prev = Head;
				Node<T>* delptr = Head->getNext();
				while (delptr)
				{
					if (*(delptr->getItem()) == *value)
					{
						prev->setNext(delptr->getNext());
						delete delptr;
						Count--;
						return true;
					}
					prev = delptr;
					delptr = delptr->getNext();

				}
				return false;
			}
		}
		
	}

	//[7] DeleteNodes
	//deletes ALL node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	//bool DeleteNodes(const T& value)
	//{
	//	Node<T>* delptr;
	//	while (Head && Head->getItem() == value)
	//	{
	//		delptr = Head;
	//		Head = Head->getNext();
	//		delete delptr;
	//	}
	//	//if (!Head) return true;
	//	Node<T>* temp = Head;
	//	if (temp)
	//	{
	//		while (temp->getNext())
	//		{
	//			if (temp->getNext()->getItem() == value)
	//			{
	//				delptr = temp->getNext();
	//				temp->setNext(temp->getNext()->getNext());
	//				delete delptr;
	//			}
	//			else
	//				temp = temp->getNext();
	//		}
	//		return(Find(value));
	//	}
	//	Count -= CountOccurance(value);
	//}

	//[8]Merge
	//Merges the current list to another list L by making the last Node in the current list 
	//point to the first Node in list L
	//void Merge(const LinkedList& L)
	//{
	//	Node<T>* ptr = Head;
	//	if (!Head || !L.Head) return;
	//	if (ptr && ptr->getNext())
	//	{
	//		while (ptr->getNext())
	//		{
	//			ptr = ptr->getNext();
	//		}
	//		ptr->setNext(L.Head);
	//	}
	//	//Count += L.Count;
	//}

	//[9] Reverse
	//Reverses the linked list (without allocating any new Nodes)
	//void Reverse()
	//{
	//	Node<T>* prev = nullptr;
	//	Node<T>* curr = Head;
	//	Node<T>* nextt = nullptr;
	//	while (curr)
	//	{
	//		nextt = curr->getNext();
	//		curr->setNext(prev);
	//		prev = curr;
	//		curr = nextt;
	//	}
	//	Head = prev;
	//}
	//void PrintKth(int k)
	//{
	//	Node<T>* ptr = Head;
	//	int count = 1;
	//	while (ptr)
	//	{
	//		if (count == k)
	//		{
	//			cout << "The Kth item is " << ptr->getItem() << endl;
	//			return;
	//		}
	//		count++;
	//		ptr = ptr->getNext();
	//	}
	//	cout << "Beyond Linked list length" << endl; return;
	//}
	//bool InsertSorted(const T& value)
	//{
	//	Node<T>* ptr = Head;
	//	while (ptr->getNext())
	//	{
	//		if (value > ptr->getItem() && value < ptr->getNext()->getItem())
	//		{
	//			Node<T>* newNode = new Node<T>(value);
	//			newNode->setNext(ptr->getNext());
	//			ptr->setNext(newNode);
	//			return true;
	//		}
	//		ptr = ptr->getNext();
	//	}
	//	return false;

	//}
	//Node<T>* RemoveMin()
	//{
	//	Node<T>* delptr = nullptr;
	//	Node<T>* ptr = Head;
	//	T min = Head->getItem();
	//	while (ptr->getNext())
	//	{
	//		if (ptr->getNext()->getItem() < min)
	//		{
	//			min = ptr->getNext()->getItem();
	//		}
	//		ptr = ptr->getNext();
	//	}
	//	if (Head->getItem() == min)
	//	{
	//		delptr = Head;
	//		Head = Head->getNext();
	//		return delptr;
	//	}

	//	Node<T>* ptr2 = Head;
	//	while (ptr2)
	//	{
	//		if (ptr2->getNext()->getItem() == min)
	//		{
	//			delptr = ptr2->getNext();
	//			ptr2->setNext(delptr->getNext());
	//			return delptr;
	//		}
	//		ptr2 = ptr2->getNext();
	//	}
	//}
	//LinkedList* CloneList(const LinkedList& L)
	//{
	//	Node<T>* ptr = L.Head;
	//	LinkedList<int>* L2 = new LinkedList<int>;
	//	while (ptr)
	//	{
	//		//Node<T>* NewNode = new Node<T>(ptr->getItem());
	//		L2->InsertEnd(ptr->getItem());
	//		ptr = ptr->getNext();
	//	}
	//	return L2;
	//}
	//LinkedList* Signsplit(LinkedList*& posL)
	//{
	//	Node<T>* ptrL = Head;
	//	posL = new LinkedList<int>;
	//	LinkedList<int>* negL = new LinkedList<int>;
	//	while (ptrL)
	//	{
	//		if (ptrL->getItem() < 0)
	//		{
	//			negL->InsertEnd(ptrL->getItem());
	//		}
	//		else
	//		{
	//			posL->InsertEnd(ptrL->getItem());
	//		}
	//		ptrL = ptrL->getNext();
	//	}
	//	return negL;
	//}
	//void MergeSorted(LinkedList* M1, LinkedList* M2)
	//{
	//	///*	LinkedList<int>* Total = new LinkedList<int>;
	//	//	Node<T>* Tptr = Total->Head;*/
	//	Node<T>* ptr1 = M1->Head;
	//	Node<T>* ptr2 = M2->Head;
	//	Node<T>* Tptr = Head;
	//	/*while (ptr1->getNext())
	//	{
	//		ptr1 = ptr1->getNext();
	//	}
	//	while (ptr1)
	//	{
	//		Total->InsertEnd(ptr1->getItem());
	//		ptr1 = ptr1->getNext();
	//	}
	//	M1->DeleteAll();
	//	while (ptr2)
	//	{
	//		Total->InsertSorted(ptr2->getItem());
	//		ptr2 = ptr2->getNext();
	//	}
	//	M2->DeleteAll();
	//	return Total;*/
	//	while (ptr1 && ptr2)
	//	{
	//		if (ptr1->getItem() < ptr2->getItem())
	//		{
	//			InsertEnd(ptr1->getItem());
	//			ptr1 = ptr1->getNext();
	//		}
	//		else
	//			if (ptr1->getItem() > ptr2->getItem())
	//			{
	//				InsertEnd(ptr2->getItem());
	//				ptr2 = ptr2->getNext();
	//			}
	//			else
	//			{
	//				InsertEnd(ptr1->getItem());
	//				InsertEnd(ptr2->getItem());
	//				ptr1 = ptr1->getNext();
	//				ptr2 = ptr2->getNext();
	//			}
	//		///*	Tptr = Tptr->getNext();*/
	//	}
	//	if (!ptr1)
	//	{
	//		while (ptr2)
	//		{
	//			InsertEnd(ptr2->getItem());
	//			ptr2 = ptr2->getNext();
	//		}
	//	}
	//	else if (!ptr2)
	//	{
	//		while (ptr1)
	//		{
	//			InsertEnd(ptr1->getItem());
	//			ptr1 = ptr1->getNext();
	//		}
	//	}
	//	M1->DeleteAll(); M2->DeleteAll();

	//}
};

#endif	

