//
// Created by ivan on 15.01.20.
//

#ifndef DATA_STRUCTURES_FIBONACCIHEAP_H
#define DATA_STRUCTURES_FIBONACCIHEAP_H

#include "List.h"
#include <iostream>
#include <cassert>
#include <initializer_list>
#define MAX_FHEAP_SIZE 100000

using LISTspace::List;
using std::endl;
using std::cout;
using std::initializer_list;


namespace FHeapSPACE
{
    template <class T>
    class FibonacciHeap
    {
    private:
        struct Node
        {
            Node* parent;
            Node* child;
            Node* left; // Pointer to the sibling node on the left
            Node* right; // Pointer to the sibling node on the right
            T data; // Value of the node
            int degree{}; // Degree of the node
            char mark; // Black or white mark of the node

            explicit Node(T data)
            {
                parent = child = left = right = nullptr;
                this->data = data;
                this->degree = 0;
                mark = 'W';
            }
            explicit Node(Node *node)
            {
                parent = node->parent;
                child = node->child;
                left = node->left;
                right = node->right;
                data = node->data;
                degree = node->degree;
                mark = node->mark;
            }
        };

        List<Node*> m_list;
        typename List<Node*>::Iterator m_pos; // position of MinNode in list
        int m_size;

    public:

        FibonacciHeap() : m_size(0) {}

        explicit FibonacciHeap(Node* node);




        // push
        // popMin(go through all process of merging a heap)
        // decrease key
        // clean up(go through all process of merging a heap) and go through
        // all list at the end and find minNode
    };

}

#endif //DATA_STRUCTURES_FIBONACCIHEAP_H
