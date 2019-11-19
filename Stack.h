//
// Created by ivan on 18.11.19.
//
// STACK
//
#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

#include "List.h"
#include "List.cpp"
#include <cassert>
#include <initializer_list>

#define MAX_SIZE 20000

namespace STACKspace
{
    template<class T>
    class Stack
    {
    private:
        LISTspace::List<T> m_stack;

        int m_size;

    public:
        Stack(): m_size(0) { }

        Stack(std::initializer_list<T> list);

        ~Stack();

        Stack& push(T data);

        Stack& pop();

        T top();

        int size(){ return m_size; }

        bool empty(){return m_size==0;}
    };
}

#endif //DATA_STRUCTURES_STACK_H




