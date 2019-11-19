//
// Created by ivan on 17.11.19.
//
//  DOUBLY LINKED LIST
//
#ifndef DATA_STRUCTURES_LIST_H
#define DATA_STRUCTURES_LIST_H

#include <iostream>
#include <cassert>
#include <initializer_list>

namespace LISTspace
{

    template <class T>
    class List
    {
    public:
        class Iterator;
    private:
        class Node
        {
        public:
            T data;
            Node*next;
            Node*prev;

            Node(T data)
            {
                this->data = data;
                this->next = NULL;
                this->prev = NULL;
            }
        };

        int m_size;
        Iterator iterator; //forgot to add m_ ((
        Node *m_begin;
        Node *m_end;

        void swap(Iterator it1,Iterator it2);
    public:
        class Iterator
        {
            friend class List;
        private:
            Node* cur_node;
        public:
            Iterator& operator++()
            {
                cur_node = cur_node->next;
                return *this;
            }
            Iterator operator++(int)
            {
                Iterator temp;
                temp.cur_node = cur_node;
                cur_node = cur_node->next;
                return temp;
            }
            Iterator& operator--()
            {
                cur_node = cur_node->prev;
                return *this;
            }
            Iterator operator--(int)
            {
                Iterator temp;
                temp.cur_node = cur_node;
                cur_node = cur_node->prev;
                return temp;
            }
            T operator*()
            {
                assert(cur_node!=NULL);
              return cur_node->data;
            }
            friend bool operator==(const Iterator& iter1,const Iterator& iter2)
            {
                return iter1.cur_node == iter2.cur_node;
            }
            friend bool operator!=(const Iterator& iter1,const Iterator& iter2)
            {
                return iter1.cur_node != iter2.cur_node;
            }
        };

        List(){m_size = 0;m_end = m_begin = NULL;}

        List(std::initializer_list<T> list);

        ~List();

        int size() {return m_size;}

        Iterator begin() {iterator.cur_node = m_begin; return iterator;}

        Iterator end() {iterator.cur_node = m_end; return iterator; }

        List& push_back(T data);

        List&  push_front(T data);

        List& insert_after(int position,T data);

        List& insert_after(T after, T data,bool not_integer);

        //removes last element
        List& remove_last();

        //removes_first();
        List& remove_first();

        //remove data with a given position;
        List& remove(int position);

        //remove given data
        List& remove(T data,bool not_integer);

        // bubble sort
        List& sort();

        List& reverse();

        List& erase();

        T& operator[](int index);

        friend std::ostream& operator<<(std::ostream &out,List &list)
        {
            Node* i = list.m_begin;

            while(i!=NULL)
            {
                out<< i->data;
                i=i->next;
            }

            return out;

        }
    };

}

#endif //DATA_STRUCTURES_LIST_H
