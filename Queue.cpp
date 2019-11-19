//
// Created by ivan on 18.11.19.
//

#include "Queue.h"
using namespace QUEUEspace;

template<class T>
Queue<T>::Queue(std::initializer_list<T> list) : Queue<T>::Queue()
{
    for(auto i = list.begin();i<list.end();i++)
    {
        push(*i);
    }
}

template<class T>
Queue<T>::~Queue()
{
    while(m_size!=0)
    {
        pop();
    }
}

template <class T>
Queue<T>& Queue<T>::push(T data)
{
    assert(m_size < MAX_SIZE);
    m_queue.push_back(data);
    m_size++;
}

template <class T>
Queue<T>& Queue<T>::pop()
{
    assert(m_size > 0);
    m_queue.remove_first();
    m_size--;
}

template <class T>
T Queue<T>::front()
{
    assert(m_size > 0);

    return *(m_queue.begin());
}

template<class T>
Queue<T>& Queue<T>::erase()
{
    while(m_size!=0)
    {
        pop();
    }
}
