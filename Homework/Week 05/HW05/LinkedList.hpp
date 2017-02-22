#ifndef _LINKED_LIST_HPP
#define _LINKED_LIST_HPP

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
class LinkedList
{
    public:
    LinkedList() // done
    {
        m_ptrFirst = nullptr;
        m_ptrLast = nullptr;
        m_itemCount = 0;
    }

    ~LinkedList() // done
    {
        Free();
    }

    void Push( const T& newItem )
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
    }

    bool Insert( int index, const T& newItem )
    {
		if (index < 0 || index > m_itemCount)
		{
			return false;
		}

		if (index == m_itemCount)
		{
			Push(newItem);
			return true;
		}

		int counter = 0;
		Node<T>* ptrcurrent = m_ptrFirst;

		while (counter < index)
		{
			ptrcurrent = ptrcurrent->ptrNext;
			counter++;
		}

		Node<T> * newNode = new Node<T>;
		newNode->data = newItem;
		newNode->ptrNext = ptrcurrent;
		newNode->ptrPrev = ptrcurrent->ptrPrev;
		(ptrcurrent->ptrPrev)->ptrNext = newNode;
		ptrcurrent->ptrPrev = newNode;
		m_itemCount++;

		return true;
    }

    void Extend( const LinkedList& other )
    {

		int counter = 0;
		while (counter < other.Size())
		{
			Push(other.Get(counter));
			counter++;
		}
    }

    bool Pop()
    {
		if (IsEmpty())
		{
			return false; // temp
		}
		//First         last
		//A     ->B     ->C->nullptr
		if (Size() > 1)
		{
			Node<T>* ptrhold = m_ptrLast->ptrPrev;
			delete m_ptrLast;
			m_ptrLast = ptrhold;
			m_itemCount--;
			return true;
		}
		else
		{
			//only A in the list
			delete m_ptrFirst;
			m_ptrFirst = nullptr;
			m_ptrLast = nullptr;
			m_itemCount--;
			return true;
		}
    }

    bool Remove( int index )
    {

		if (index < 0 || index >= m_itemCount)
		{
			return false;
		}

		if (index == Size()|| m_itemCount==1)
		{
			return(Pop());
		}

		if (index > 0)
		{
			int counter = 0;
			Node<T>* ptrcurrent = m_ptrFirst;

			while (counter < index)
			{
				ptrcurrent = ptrcurrent->ptrNext;
				counter++;
			}

			//Node<T> * newNode = new Node<T>;
			//newNode->data = newItem;
			//newNode->ptrNext = ptrcurrent;
			//newNode->ptrPrev = ptrcurrent->ptrPrev;

			(ptrcurrent->ptrPrev)->ptrNext = ptrcurrent->ptrNext;
			(ptrcurrent->ptrNext)->ptrPrev = ptrcurrent->ptrPrev;

			delete ptrcurrent;
			m_itemCount--;
			return true;
		}
		else
		{
			//only A in the list
			delete m_ptrFirst;
			m_ptrFirst = nullptr;
			m_ptrLast = nullptr;
			m_itemCount--;
			return true;
		}

    }

    T Get( int index ) const
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

    bool IsEmpty() const // done
    {
        //return (m_ptrFirst == nullptr);
        return(m_itemCount==0);
    }

    T operator[]( int index ) // done
    {
        return Get( index );
    }

    LinkedList& operator=( const LinkedList& other )
    {

        if (other.IsEmpty())
		{
			return (*this); // temp
		}

		int counter = 0;


		while (counter < m_itemCount)
		{
			Free();
			counter++;
		}

		counter =0;

        while (counter < other.m_itemCount)
		{
			Push(other.Get(counter));
			counter++;

		}
        return (*this); // temp
    }

    bool operator==( const LinkedList& other )
    {
		if (Size() != other.Size())
		{
			return false; // temp
		}

		int counter = 0;
		Node<T>* ptrcurrent = m_ptrFirst;

		while (counter < Size())
		{

			if (ptrcurrent->data != other.Get(counter))
			{
				return false;
			}

			ptrcurrent = ptrcurrent->ptrNext;
			counter++;
		}
		return true;
    }

    bool operator!=( const LinkedList& other )
    {
        return !( (*this) == other );
    }

    private:
    void Free() // done
    {
        while ( !IsEmpty() )
        {
            Pop();
        }
    }

    Node<T>* m_ptrFirst;
    Node<T>* m_ptrLast;
    int m_itemCount;
};

#endif
