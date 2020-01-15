//
// Created by ivan on 09.01.20.
//

#ifndef DATA_STRUCTURES_BINOMIALHEAP_H
#define DATA_STRUCTURES_BINOMIALHEAP_H

#include <cmath>
#include "List.h"
#include <iostream>
#include <initializer_list>
#include <cassert>
#define MAX_B_H_SIZE 100000

using std::cout;
using std::initializer_list;
using std::endl;
using LISTspace::List;

namespace BinomialHeapSPACE
{
    template<class T>
    class BinomialHeap
    {
    private:
        // binomial tree node
        struct Node
        {
            T data;
            int degree{};
            Node *child, *parent, *sibling;

            explicit Node(T data)
            {
                this->data = data;
                this->degree = 0;
                this->child = this->parent = this->sibling = nullptr;
            }

            Node(Node* node)
            {
                this->data    = node->data;
                this->degree  = node->degree;
                this->child   = node->child;
                this->sibling = node->sibling;
                this->parent  = node->parent;
            }
        };

        List<Node*> m_list;
        int m_size;

        void merge(BinomialHeap& bh);

        Node* getMinNode();

    public:
        BinomialHeap() : m_size(0) {}

        BinomialHeap(BinomialHeap& bh);

        explicit BinomialHeap(Node* node);

        BinomialHeap(initializer_list<T> list);

        BinomialHeap& operator=(BinomialHeap& bh);

        BinomialHeap& insert(T data);

        T getMin();

        BinomialHeap& connect( BinomialHeap& bh);

        int size(){return m_size;}

        BinomialHeap& extractMin();

        bool empty(){return m_size == 0;}

    };



}






#endif //DATA_STRUCTURES_BINOMIALHEAP_H








