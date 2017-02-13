#include "SmartDynamicArray.hpp"

#include "cuTEST/Menu.hpp"

SmartDynamicArray::SmartDynamicArray()
{
    m_itemCount = 0;
    m_arraySize = 0;
    m_data = nullptr;
}

SmartDynamicArray::~SmartDynamicArray()
{
    Free();
}

bool SmartDynamicArray::Push( const string& newItem )
{
    if (IsFull())
	{
		m_data[m_itemCount] = newItem;
		m_itemCount++;
	}
	else
	{
        Resize();
        m_data[m_itemCount] = newItem;
		m_itemCount++;

	}
	return true;

}


bool SmartDynamicArray::Insert( int index, const string& newItem )
{
	if (index < 0)
	{
		return false; // placeholder
	}
	else if (index >= m_arraySize)
	{
		return false; // placeholder
	}
	else if(index > m_itemCount)
	{
		return false; // placeholder
	}
	else
	{
		for (int i = m_arraySize-1; i > index; i--)
		{
			m_data[i] = m_data[i - 1];
		}
		m_data[index] = newItem;
		m_itemCount++;
		return true;
	}
}


bool SmartDynamicArray::Extend( const SmartDynamicArray& other )
{
	if (other.Size() > (m_arraySize - m_itemCount))
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


bool SmartDynamicArray::Pop()
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


bool SmartDynamicArray::Remove( int index )
{
	if (index < 0)
	{
		return false; // placeholder
	}
	else if (index >= m_arraySize)
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
		for (int i = index; i < m_arraySize-1; i++)
		{
			m_data[i] = m_data[i+1];
		}
		m_itemCount--;
		return true;
	}
}


string SmartDynamicArray::Get( int index ) const
{
	if (index < 0)
	{
		return "";
	}
	else if (index >= m_arraySize)
	{
		return "";
	}
	else
	{
		return m_data[index];
	}
}


int SmartDynamicArray::Size() const
{
	return m_itemCount;
}

int SmartDynamicArray::GetMaxSize() const
{
    return -1; // temp
}

bool SmartDynamicArray::IsFull() const
{
	if (m_itemCount == m_arraySize) {
		return true;
	}
	else
	{
		return false; // placeholder
	}
}

bool SmartDynamicArray::IsEmpty() const
{
	if (m_itemCount == 0) {
		return true;
	}
	else
	{
		return false; // placeholder
	}
}

string SmartDynamicArray::operator[]( int index )
{
	return "placeholder"; // placeholder
}

SmartDynamicArray& SmartDynamicArray::operator=( const SmartDynamicArray& other )
{
    if (other.IsEmpty() == false)
	{
		for (int i = 0; i < m_arraySize; i++)
		{
			this->m_data[i] = other.m_data[i];
			m_itemCount++;
		}
	}

	return *this; // placeholder
}

bool SmartDynamicArray::operator==( const SmartDynamicArray& other )
{
	for (int i = 0; i < m_arraySize; i++)
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


bool SmartDynamicArray::operator!=( const SmartDynamicArray& other )
{
	for (int i = 0; i < m_arraySize; i++)
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
}

void SmartDynamicArray::Free()
{
}

void SmartDynamicArray::Resize()
{
    Resize(m_arraySize+10);
}


void SmartDynamicArray::Resize( int newSize )
{
    string * newarray;
    newarray = new string [newSize];

    for (int i=0;i<m_itemCount;i++)
    {
        newarray[i]=m_data[i];
    }
    delete m_data;
    m_data = newarray;
    newarray = NULL;
    m_arraySize=newSize;

}




