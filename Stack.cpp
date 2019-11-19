//
// Created by ivan on 18.11.19.
//

#include "Stack.h"

using namespace STACKspace;

template<class T>
Stack<T>::~Stack()
{
    while(m_size!=0)
    {
        pop();
    }
}

template<class T>
Stack<T>::Stack(std::initializer_list<T> list) : Stack<T>::Stack()
{
    for(auto i = list.begin();i!=list.end();i++)
    {
        push(*i);
    }
}

template <class T>
Stack<T>& Stack<T>::push(T data)
{
    assert(m_size < MAX_SIZE && "STACK IS OVERLOADED");
    m_stack.push_back(data);
    m_size++;
}

template <class T>
Stack<T>& Stack<T>::pop()
{
    assert(m_size>0);
    m_stack.remove_last();
    m_size--;
}

template<class T>
T Stack<T>::top()
{
    assert(m_size>0);
    return *(m_stack.end());
}
