
#ifndef STACK_HPP
#define STACK_HPP

#include "DoublyLinkedList.hpp"

template <typename T>
class Stack2 : public DoublyLinkedList<T>
{
    public:
    Stack2():DoublyLinkedList<T>()
    {

    }

    virtual ~Stack2()
    {
    }

    virtual void push( T data )
    {
		DoublyLinkedList<T>::PushBack(data);
    }

    virtual void pop()
    {
        try
        {
            DoublyLinkedList<T>::PopBack();
        }
        catch(out_of_range& ex)
        {
            cout << endl << "paused...." << ex.what() << endl;
            cin.get();
        }
    }

    virtual T top()
    {
        try
        {
            return(DoublyLinkedList<T>::GetBack());
        }
        catch(out_of_range& ex)
        {
            cout << endl << "paused...." << ex.what() << endl;
            cin.get();

        }
    }

    virtual T Take()
    {
        return(DoublyLinkedList<T>::GetBack());
    }

    virtual int GetStackSize()
    {
        return (DoublyLinkedList<T>::GetSize());
    }
};

#endif
