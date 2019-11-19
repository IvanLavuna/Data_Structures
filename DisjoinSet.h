//
// Created by ivan on 18.11.19.
//

#ifndef DATA_STRUCTURES_DISJOINSET_H
#define DATA_STRUCTURES_DISJOINSET_H

#include <cassert>
#include <initializer_list>

namespace SETspace
{
    template<class T>
    class DisjoinSet
    {
    private:
        struct Node
        {
            int rank;
            T data;
            Node *parent;
            Node(T data)
            {
                this->data = data;
                this->parent = NULL;
                this->rank = 0;
            }
        };

        Node *root;

    public:


    };
}

#endif //DATA_STRUCTURES_DISJOINSET_H




