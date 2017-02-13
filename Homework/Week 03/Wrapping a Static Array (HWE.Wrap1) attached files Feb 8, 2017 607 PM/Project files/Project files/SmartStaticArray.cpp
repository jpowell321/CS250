#include "SmartStaticArray.hpp"

#include "cuTEST/Menu.hpp"

SmartStaticArray::SmartStaticArray()
{
	m_itemCount = 0;
}

bool SmartStaticArray::Push( const string& newItem )
{
	if (m_itemCount < MAX_SIZE)
	{
		m_data[m_itemCount] = newItem;
		m_itemCount++;
		return true;
	}
	else
	{
		return false; // placeholder
	}
}


bool SmartStaticArray::Insert( int index, const string& newItem )
{
	if (index < 0)
	{
		return false; // placeholder
	}
	else if (index >= MAX_SIZE)
	{
		return false; // placeholder
	}
	else if(index > m_itemCount)
	{
		return false; // placeholder
	}
	else
	{
		for (int i = MAX_SIZE-1; i > index; i--)
		{
			m_data[i] = m_data[i - 1];
		}
		m_data[index] = newItem;
		m_itemCount++;
		return true;
	}
	
}


bool SmartStaticArray::Extend(const SmartStaticArray& other)
{
	if (other.Size() > (MAX_SIZE - m_itemCount))
	{
		return false; // placeholder
	}
	int j = 0;
	int t = m_itemCount;
	for (int i = m_itemCount; i < (t+other.Size()); i++)
	{
		m_data[i] = other.m_data[j];
		j++;
		m_itemCount++;
		
	}
	return true;
}

bool SmartStaticArray::Pop()
{
	if (m_itemCount <= 0) 
	{
		return false; // placeholder
	}
	else
	{
		m_itemCount--;
		return true;
	}
	
}


bool SmartStaticArray::Remove( int index )
{
	if (index < 0)
	{
		return false; // placeholder
	}
	else if (index >= MAX_SIZE)
	{
		return false; // placeholder
	}
	else if (index >= m_itemCount)
	{
		return false; // placeholder
	}
	else if (m_itemCount==0)
	{
		return false; // placeholder
	}
	else
	{
		for (int i = index; i < MAX_SIZE-1; i++)
		{
			m_data[i] = m_data[i+1];
		}
		m_itemCount--;
		return true;
	}
}


string SmartStaticArray::Get( int index ) const
{
	if (index < 0)
	{
		return "";
	}
	else if (index >= MAX_SIZE)
	{
		return "";
	}
	else
	{
		return m_data[index];
	}
}


int SmartStaticArray::Size() const
{
	return m_itemCount;
}


bool SmartStaticArray::IsFull() const
{
	if (m_itemCount == MAX_SIZE) {
		return true;
	}
	else
	{
		return false; // placeholder
	}
}

bool SmartStaticArray::IsEmpty() const
{
	if (m_itemCount == 0) {
		return true;
	}
	else
	{
		return false; // placeholder
	}
}


string SmartStaticArray::operator[]( int index )
{
	return "placeholder"; // placeholder
}


SmartStaticArray& SmartStaticArray::operator=( const SmartStaticArray& other )
{
	if (other.IsEmpty() == false)
	{
		for (int i = 0; i < MAX_SIZE; i++)
		{
			this->m_data[i] = other.m_data[i];
			m_itemCount++;
		}
	}
	
	return *this; // placeholder
	
	
}

bool SmartStaticArray::operator==( const SmartStaticArray& other )
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (m_data[i] != other.m_data[i]) 
		{
			return false;
		}
	}
	if (m_itemCount != other.m_itemCount)
	{
		return false;
	}
	return true; // placeholder
}


bool SmartStaticArray::operator!=( const SmartStaticArray& other )
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (m_data[i] != other.m_data[i])
		{
			return true;
		}
	}
	if (m_itemCount != other.m_itemCount)
	{
		return true;
	}
	return false; // placeholder
	
	//return !( *this == other );
}
