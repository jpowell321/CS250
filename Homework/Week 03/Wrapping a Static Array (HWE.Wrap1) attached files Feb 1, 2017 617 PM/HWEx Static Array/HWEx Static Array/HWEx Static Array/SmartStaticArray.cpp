#include "SmartStaticArray.hpp"

SmartStaticArray::SmartStaticArray()
{
	m_itemCount = 0;
}

bool SmartStaticArray::Push( const string& newItem )
{
	if (m_itemCount >= MAX_SIZE) 
	{
		return false; // temp
	}
	m_data[m_itemCount] = newItem;
	m_itemCount++;
	return true;
}


bool SmartStaticArray::Insert( int index, const string& newItem )
{
	//validate the index : It shouldn't be negative, or MAX_SIZE or greater. 
	//Return false if there is an invalid index given, without changing the array.
	if (index < 0)
	{
		return false;
	}
	if (index >= MAX_SIZE)
	{
		return false;
	}
	if (m_itemCount == 0 && index == 0)
	{
		m_data[index] = newItem;
		m_itemCount++;
		return true; // temp
	}
	
	for (int i = m_itemCount - 1; i >= index; i--)
	{
		m_data[i + 2] = m_data[i+1];
		m_data[i + 1] = m_data[i];
		m_data[i] = m_data[i - 1];
		m_data[i-1] = newItem;
		m_itemCount++;
	}

	return true; // temp
}


bool SmartStaticArray::Extend( const SmartStaticArray& other )
{
	return false; // temp
}


bool SmartStaticArray::Pop()
{
	return false; // temp
}


bool SmartStaticArray::Remove( int index )
{
	return false; // temp
}


string SmartStaticArray::Get( int index ) const
{
	if (index > MAX_SIZE)
	{
		return "OUT OF BOUNDS";
	}
	if (index < 0)
	{
		return "OUT OF BOUNDS";
	}
	
	return m_data[index]; // temp
}


int SmartStaticArray::Size() const
{
	return m_itemCount;
	
}


bool SmartStaticArray::IsFull() const
{
	return false; // temp
}

bool SmartStaticArray::IsEmpty() const
{
	return false; // temp
}


string SmartStaticArray::operator[]( int index )
{
	return "temp"; // temp
}


SmartStaticArray& SmartStaticArray::operator=( const SmartStaticArray& other )
{
    SmartStaticArray blorp; // temp
    return blorp; // temp
}

bool SmartStaticArray::operator==( const SmartStaticArray& other )
{
	return false; // temp
}
