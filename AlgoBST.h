//
// Created by ivan on 28.12.19.
//
// Algorithms to Binary Search tree
//
//
#ifndef DATA_STRUCTURES_ALGOBST_H
#define DATA_STRUCTURES_ALGOBST_H

#include "BST.h"
using std::cin;
using std::cout;
using std::endl;

namespace AlgoBSTspace
{
    using namespace BSTspace;

    template<class T>
    class AlgoBST : public BST<T>
    {
    public:
        // find diameter of a given tree with root as a parameter and
        // parameter 'd' as a value that will be give a diameter of BST
        int diameter(typename BST<T>::Node* root,int &d);

        // to find height of a given tree with root as a parameter
        int height(typename BST<T>::Node *root);

        T min_val(typename BST<T>::Node * root);

        T max_val(typename BST<T>::Node * root);
    };

    // This function returns height of BST,but
// in parameter 'd' it will write the diameter of BST
    template<class T>
    int AlgoBST<T>::diameter(typename BST<T>::Node* root, int &d)
    {
        int h_l = 0, h_r = 0, h = 0;
        if(root == NULL)
        {
            return 0;
        }

        h_l = diameter(root->right,d);
        h_r = diameter(root->left,d);
        h = std::max(h_l ,h_r) + 1;
        d = std::max(d,h_l + h_r + 1);

        return h;
    }

    template<class T>
    int AlgoBST<T>::height(typename BST<T>::Node * root)
    {
        if(root == NULL)
            return 0;

        return std::max(height(root->left),height(root->right)) + 1;
    }

    template<class T>
    T AlgoBST<T>::min_val(typename BST<T>::Node * root)
    {
        while(root->left != NULL)
        {
            root = root->left;
        }
        return root->data;
    }

    template<class T>
    T AlgoBST<T>::max_val(typename BST<T>::Node * root)
    {
        while(root->right != NULL)
        {
            root = root->right;
        }
        return root->data;
    }


}



#endif //DATA_STRUCTURES_ALGOBST_H
