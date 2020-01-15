//
// Created by ivan on 21.11.19.
//
// BINARY SEARCH TREE
//

#ifndef DATA_STRUCTURES_BST_H
#define DATA_STRUCTURES_BST_H

#include <iostream>
#include <initializer_list>
#include <cassert>

namespace BSTspace
{
    template<class T>
    class BST
    {

    protected:
        struct Node
        {
            T data;
            Node *left;
            Node *right;

            Node(T data)
            {
                this->data = data;
                this->left = nullptr;
                this->right = nullptr;
            }

        };
        Node* m_root;
        int m_size;
        Node * minValueNode(Node* node);

    public:
        BST();

        BST(std::initializer_list<T> list);

        explicit BST(T data);

        ~BST();

        BST& add(T data);

        Node *deleteNode(Node *root, T data);

        void preorder(Node *node);

        void postorder(Node *node);

        void inorder(Node *node);

        void erase( Node* root);

        int size(){return m_size;}

        Node* root(){return m_root;}

    };

    template <class T>
    BST<T>::BST()
    {
        m_size = 0;
        m_root = nullptr;
    }

    template <class T>
    BST<T>::BST(T data) : BST<T>::BST()
    {
        Node* new_node = new Node(data);
        m_root = new_node;
        m_size++;
    }

    template <class T>
    BST<T>::BST(std::initializer_list<T> list) : BST<T>::BST()
    {
        for(auto i = list.begin();i!=list.end();i++)
        {
            add(*i);
        }
    }

    template< class T>
    BST<T>::~BST()
    {
        erase(root());
    }


    template <class T>
    BST<T>& BST<T>::add(T data)
    {
        Node* new_node = new Node(data);

        if(m_root == nullptr)
        {
            m_root = new_node;
        }
        else
        {
            auto iter = root();

            while(true)
            {
                if(data == iter->data)
                {
                    delete new_node;
                    return *this;
                }
                else if(data > iter->data )
                {
                    if(iter->right == nullptr)
                    {
                        iter->right = new_node;
                        break;
                    }
                    iter = iter->right;
                }
                else if(data < iter->data )
                {
                    if(iter->left == nullptr)
                    {
                        iter->left = new_node;
                        break;
                    }
                    iter = iter->left;
                }

            }
        }

        m_size++;

        return *this;
    }

//
//  how to make parameter to this function by default????
//
//  left,root,right
    template <class T>
    void BST<T>::inorder(Node *node)
    {
        if(node!=nullptr)
        {
            inorder(node->left);
            std::cout<< node->data<<" ";
            inorder(node->right);
        }
    }

//
//  how to make parameter to this function by default????
//
//  left,right,root
    template <class T>
    void BST<T>::postorder(Node *node)
    {
        if(node!=nullptr)
        {
            postorder(node->left);
            postorder(node->right);
            std::cout<< node->data<<" ";
        }
    }

//
//how to make parameter to this function by default????
//
//root,left,right
    template <class T>
    void BST<T>::preorder(Node *node)
    {
        if(node!=nullptr)
        {
            std::cout<< node->data<<" ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    template<class T>
    typename BST<T>::Node* BST<T>::minValueNode(Node* current)
    {

        while (current && current->left != nullptr)
            current = current->left;

        return current;
    }


    template<class T>
    typename BST<T>::Node* BST<T>::deleteNode(Node* root, T data)
    {
        if (root == nullptr) return root;

        if (data < root->data)
            root->left = deleteNode(root->left, data);

        else if (data > root->data)
            root->right = deleteNode(root->right, data);

        else
        {
            if (root->left == nullptr)
            {
                Node *temp = root->right;
                if(root == m_root)
                {
                    m_root = m_root->right;
                }
                m_size --;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                Node *temp = root->left;
                if(root == m_root)
                {
                    m_root = m_root->left;
                }
                m_size--;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }

        return root;
    }

    template<class T>
    void BST<T>::erase(Node* root)
    {
        if(root != nullptr)
        {
            erase(root->right);
            erase(root->left);
            delete root;
        }
    }

}



#endif //DATA_STRUCTURES_BST_H