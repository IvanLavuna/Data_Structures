//
// Created by ivan on 18.11.19.
//
// QUEUE
//

#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H

#include <cassert>
#include <initializer_list>
#include "List.h"
#include "List.cpp"

#define MAX_SIZE 20000

namespace QUEUEspace
{
    template<class T>
    class Queue
    {
    private:
        LISTspace::List<T> m_queue;

        int m_size;

    public:
        Queue() : m_size(0) {};

        Queue(std::initializer_list<T> list);

        ~Queue();

        Queue& push(T data);

        Queue& pop();

        T front();

        int size() {return m_size;}

        bool empty(){return m_size == 0;}

        Queue& erase();

    };
}

#endif //DATA_STRUCTURES_QUEUE_H
