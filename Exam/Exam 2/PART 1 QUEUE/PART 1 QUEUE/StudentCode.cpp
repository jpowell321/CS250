/*
Edit this file
*/

#include "StudentCode.hpp"

/*
Using StudentCode.cpp for reference,
implement the Queue's POP function.
This queue is a linked list type of structure;
you will have to directly modify the private
member variables of the Queue class in the
.hpp file.
*/
bool Queue::Pop()
{
	
	if (m_ptrLast == nullptr)
	{
			// do nothing
		return false;
	}

	if (m_ptrLast == m_ptrFirst)
	{
		delete m_ptrLast;
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
		m_itemCount--;
	}
	else
	{
			
		// Queue's pop first entry
		Node* ptrCurrent = m_ptrFirst;

		//point to first + 1
		ptrCurrent = ptrCurrent->ptrNext;
		
		//Move head to first + 1
		m_ptrFirst = ptrCurrent;
		
		//update head previous as null
		m_ptrFirst->ptrPrev = nullptr;
		
		//decrement count, method does not ask to return data 
		m_itemCount--;
			
	}

	return true;	

}
