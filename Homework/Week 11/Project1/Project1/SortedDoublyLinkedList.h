#ifndef SORTEDDOUBLYLINKEDLIST_HPP
#define SORTEDDOUBLYLINKEDLIST_HPP

#include <stdexcept>
using namespace std;

template <typename T>
class Node
{
public:
	Node()
	{
		m_ptrNext = nullptr;
		m_ptrPrev = nullptr;
	}

	T m_data;

	Node<T>* m_ptrNext;
	Node<T>* m_ptrPrev;
};

template <typename T>
class DoublyLinkedList
{
public:
	DoublyLinkedList()
	{
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
		m_itemCount = 0;
	}

	virtual ~DoublyLinkedList()
	{
		while (m_ptrFirst != nullptr)
		{
			PopBack();
		}
	}

	/*
	Pure virtual functions:
	Interfaces for children, to be
	implemented by child classes.
	*/
	virtual void Push(T data) = 0;
	virtual void Pop() = 0;
	virtual T Take() = 0;

	/*
	Inherited public functions
	*/

	void Display()
	{
		Node<T>* ptrCurrent = m_ptrFirst;
		while (ptrCurrent != nullptr)
		{
			cout << ptrCurrent->m_data;

			if (ptrCurrent == m_ptrFirst)
			{
				cout << "\t FIRST";
			}
			if (ptrCurrent == m_ptrLast)
			{
				cout << "\t LAST";
			}

			cout << endl;

			ptrCurrent = ptrCurrent->m_ptrNext;
		}
	}

	int Size()
	{
		return m_itemCount;
	}

protected:
	int m_itemCount;
	Node<T>* m_ptrFirst;
	Node<T>* m_ptrLast;

	/*
	Behind-the-scenes inner-workings
	*/

	void SortedPush(T data)
	{
		Node<T>* newNode = new Node<T>();
		newNode->m_data = data;

		if (m_ptrFirst = nullptr)
		{
			// Empty list
			m_ptrFirst = newNode;
			m_ptrLast = newNode;
		}
		else
		{
			// Not empty, new node is the new first
			newNode->m_ptrNext = m_ptrFirst;
			m_ptrFirst->m_ptrPrev = newNode;

			// Update pointer
			m_ptrFirst = newNode;
		}

		m_itemCount++;
	}

	
	T& GetAt(int index)
	{
		if (index > m_itemCount || index < 0)
		{
			throw out_of_range("Invalid index!");
		}

		// Locate item
		Node<T>* ptrCurrent = m_ptrFirst;

		int counter = 0;
		while (counter != index)
		{
			ptrCurrent = ptrCurrent->m_ptrNext;
			counter++;
		}

		return ptrCurrent->m_data;
	}
};

template <typename T>
using List = DoublyLinkedList<T>;

#endif
