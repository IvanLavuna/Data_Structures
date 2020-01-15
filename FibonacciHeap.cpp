//
// Created by ivan on 15.01.20.
//

#include "FibonacciHeap.h"

using namespace FHeapSPACE;

template<class T>
FibonacciHeap<T>::FibonacciHeap(FibonacciHeap::Node *node) : m_size(0)
{
    m_list.push_back(node);
    m_pos = m_list.begin();
    m_size++;
}


typedef FibonacciHeap<int> heap;

int main()
{

}







