#ifndef SORTEDLIST_HPP
#define SORTEDLIST_HPP

#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node
{
	Node()
	{
		ptrNext = nullptr;
		ptrPrev = nullptr;
	}

	Node<T>* ptrNext;
	Node<T>* ptrPrev;

	T data;
};

template <typename T>
class SortedList
{
public:
	SortedList() 
	{
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
		m_itemCount = 0;
	}

	~SortedList()
	{
		
	}

	void Sortedpush(const T& newItem)
	{
		Node<T> * newNode = new Node<T>;
		newNode->data = newItem;

		if (m_ptrFirst == nullptr)
		{
			//Empty List
			m_ptrFirst = newNode;
			m_ptrLast = newNode;
		}
		else
		{
			//Not Empty
			//List
			//A->B->C->nullptr
			newNode->ptrPrev = m_ptrLast;	//New nodes previous is the old last
			m_ptrLast->ptrNext = newNode;	//Old last next is the new node
			m_ptrLast = newNode;			// The new last is the new node
		}
		m_itemCount++;
		
		Sort();
	}

	void Sort()
	{
		//Sort list lowest to highest
		if (m_itemCount > 1)
		{
			int counter = 0;
			Node<T>* ptrcurrent = m_ptrFirst;
			int nodehold;

			while (counter < (m_itemCount-1))
			{
				
				if (ptrcurrent->data >(ptrcurrent->ptrNext)->data)
				{
					nodehold = ptrcurrent->data;
					ptrcurrent->data = (ptrcurrent->ptrNext)->data;
					(ptrcurrent->ptrNext)->data = nodehold;
				}
				ptrcurrent = ptrcurrent->ptrNext;
				counter++;
			}
		}
	}


	T GetAt(int index) const
	{

		if (index < 0 || index >= m_itemCount)
		{
			return T(); //Return new "T" item
		}

		int counter = 0;
		Node<T>* ptrcurrent = m_ptrFirst;

		while (counter < index)
		{
			ptrcurrent = ptrcurrent->ptrNext;
			counter++;

		}

		return ptrcurrent->data;
	}

	int Size() const // done
	{
		return m_itemCount;
	}

	void Display()
	{
		Node<T>* ptrCurrent = m_ptrFirst;
		if (ptrCurrent == nullptr)
		{
			cout << "No Data" << endl;
		}
		while (ptrCurrent != nullptr)
		{
			cout << ptrCurrent->data;

			if (ptrCurrent == m_ptrFirst)
			{
				cout << "\t FIRST";
			}
			if (ptrCurrent == m_ptrLast)
			{
				cout << "\t LAST";
			}

			cout << endl;

			ptrCurrent = ptrCurrent->ptrNext;
		}
		
	}
private:
	Node<T>* m_ptrFirst;
	Node<T>* m_ptrLast;
	int m_itemCount;


};

#endif
