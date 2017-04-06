#include "StudentTable.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <exception>
using namespace std;

/* DONE */ StudentTable::StudentTable()
{
    m_collisionMethod = LINEAR; // default
    for ( int i = 0; i < TABLE_SIZE; i++ )
    {
        // Initialize students
        m_students[i].key = -1;
        m_students[i].value = "";
    }
}

/* DONE */ void StudentTable::SetCollisionMethod( CollisionMethod cm )
{
    cout << "Collision method: " << cm << endl << endl;
    m_collisionMethod = cm;
}

/* Insert
Take in the studentId (key) and name (value), and
use your hash function to figure out an index
for this new value.
Then, set the values of the Student object in the array.
*/
void StudentTable::Insert( int studentId, const string& name )
{
    // Generate index from the studentId
    // Insert into the m_students array
	int hold = HashFunction(studentId);

	m_students[HashFunction(studentId)].key = studentId;
	m_students[HashFunction(studentId)].value = name;
		
}

/* DONE */ void StudentTable::Output( const string& filename )
{
    cout << "Output table to: " << filename << endl << endl;

    ofstream output( filename );
    for ( int i = 0; i < TABLE_SIZE; i++ )
    {
        output << i << ".";
        if ( i < 10 )
        {
            output << "   ";
        }
        else if ( i < 100 )
        {
            output << "  ";
        }
        else
        {
            output << " ";
        }

        if ( m_students[i].key != -1 )
        {
            output << "Student ID: " << m_students[i].key << " \t Student Name: " << m_students[i].value;
        }
        output << endl;
    }
    output.close();
}

/* HashFunction
Take in the key and generate an index.
This function should handle collisions, and
the returned index should be the index of an
available "slot" in the array.

Use an if statement to decide which collision
method to use.

if ( m_collisionMethod == LINEAR ) // ...
*/
int StudentTable::HashFunction( int key )
{
	if (m_collisionMethod == LINEAR)
	{
		int index = key % TABLE_SIZE;
		if (m_students[index].value == "")
		{
			return index;
		}
		index = LinearProbe(key);
		return (index);

	}
	else if (m_collisionMethod == QUADRATIC)
	{
		int index = key % TABLE_SIZE;
		if (m_students[index].value == "")
		{
			return index;
		}

		int count = 0;
		for (int j = index; index < TABLE_SIZE; j++)
		{
			count++;
			index = QuadraticProbe(key, count);
			if (m_students[index].value == "")
			{
				return index;
			}
		}
	
	}
	else
	{
		int index = key % TABLE_SIZE;
		if (m_students[index].value == "")
		{
			return index;
		}
		index = HashFunction2(key);
		return (index);
	}
		
}

/* Linear probing
    You can use my function prototype or write your own.
*/
int StudentTable::LinearProbe( int key )
{
	int index = key % TABLE_SIZE;
	for (int j = index; j < TABLE_SIZE; j++)
	{
		if (m_students[j].value == "")
		{
			return j;
		}
	}
	
}

/* Quadratic probing
    You can use my function prototype or write your own.
*/
int StudentTable::QuadraticProbe( int key, int& addValue )
{
	int index = key % TABLE_SIZE;
	int newindex = index + (addValue * addValue);

	if (newindex >= TABLE_SIZE)
	{
		return (newindex % TABLE_SIZE);
	}
	return (newindex);
}

/* Double hashing
    You can use my function prototype or write your own.
*/
int StudentTable::HashFunction2( int key )
{
	int index = key % TABLE_SIZE;
	int hash2 = 7 - (key % 7);
	int newindex = index + hash2;
	if (newindex >= TABLE_SIZE)
	{
		return (newindex % TABLE_SIZE);
	}
	return (newindex);
}
