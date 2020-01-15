//
// Created by ivan on 08.01.20.
//

#ifndef DATA_STRUCTURES_PRIORITY_QUEUE_H
#define DATA_STRUCTURES_PRIORITY_QUEUE_H

#include <cassert>
#include <iostream>
#include <initializer_list>
#include "MinHeap.h"
#include "MaxHeap.h"
#define MAX_PR_Q_SIZE 100000

using std::cout;
using std::endl;
using std::initializer_list;



namespace Priority_QueueSPACE
{
    using namespace MinHeapSPACE;
    using namespace MaxHeapSPACE;

    template<class T,bool bigger = true>
    class Priority_Queue
    {
    private:
        MinHeap<T> m_MinHeap;
        MaxHeap<T> m_MaxHeap;

    public:
        Priority_Queue() = default;

        Priority_Queue(initializer_list<T> list);

        int size(){ return m_MinHeap.size() + m_MaxHeap.size();}

        T top();

        bool empty(){return (m_MinHeap.size() + m_MaxHeap.size()) == 0;}

        Priority_Queue& push(T data);

        Priority_Queue& pop();

        Priority_Queue& erase();

    };


    template<class T, bool bigger>
    Priority_Queue<T, bigger>::Priority_Queue(initializer_list<T> list)
    {
        if(bigger)
        {
            for(auto item : list)
                m_MaxHeap.insert(item);
        } else
        {
            for(auto item : list)
                m_MinHeap.insert(item);
        }
    }

    template<class T, bool bigger>
    T Priority_Queue<T, bigger>::top()
    {
        assert(!empty() &&  "Priority_queue is empty!");
        if(bigger)
        {
            return m_MaxHeap.getMaxElem();
        }
        return m_MinHeap.getMinElem();
    }

    template<class T, bool bigger>
    Priority_Queue<T, bigger> &Priority_Queue<T, bigger>::push(T data)
    {
        if(bigger)
        {
            m_MaxHeap.insert(data);
        } else
        {
            m_MinHeap.insert(data);
        }
        return *this;
    }

    template<class T, bool bigger>
    Priority_Queue<T,bigger> &Priority_Queue<T, bigger>::pop()
    {
        assert(!empty() &&  "Priority_queue is empty!");
        if(bigger)
        {
            m_MaxHeap.deleteMax();
        } else
        {
            m_MinHeap.deleteMin();
        }
        return *this;
    }

    template<class T, bool bigger>
    Priority_Queue<T,bigger> &Priority_Queue<T, bigger>::erase()
    {
        if(bigger)
        {
            m_MaxHeap.erase();
        } else{
            m_MinHeap.erase();
        }
        return *this;
    }



}

#endif //DATA_STRUCTURES_PRIORITY_QUEUE_H










