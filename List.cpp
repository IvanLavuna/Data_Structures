//
// Created by ivan on 17.11.19.
//
#include "List.h"
using namespace LISTspace;


template<class T>
List<T>::List(std::initializer_list<T> list) : List<T>::List()
{
    for (auto i = list.begin(); i != list.end(); ++i)
    {
        push_back(*i);
    }
}

template<class T>
void List<T>::swap(Iterator it1,Iterator it2)
{
    T temp = it1.cur_node->data;
    it1.cur_node->data = it2.cur_node->data;
    it2.cur_node->data = temp;
}

template <class T>
List<T>::~List()
{
    while(m_size!=0)
    {
        remove_first();
    }
}

template<class T>
List<T>& List<T>::push_back(T data)
{
    Node* new_node = new Node(data);

    if(m_size == 0)
    {
        m_end = m_begin = new_node;
    }
    else
    {
        m_end->next = new_node;
        new_node->prev = m_end;
        m_end = new_node;
    }
    m_size++;
    return *this;
}

template <class T>
List<T>& List<T>::push_front(T data)
{
    Node* new_node = new Node(data);

    if(m_size == 0)
    {
        m_begin = m_end = new_node;
    }
    else{
        new_node->next = m_begin;
        m_begin->prev = new_node;
        m_begin = new_node;
    }
    m_size++;
    return *this;

}

template <class T>
List<T>& List<T>::insert_after(int position, T data)
{
    assert(position >= 0 && position < m_size);

    Node* new_node = new Node(data);

    if(m_size == 0)
    {
        push_back(data);
        return *this;
    }

    auto iterator1 = begin();
    int i = 0;
    while(i!=position)
    {
        iterator1++;
        i++;
    }
    if(iterator1.cur_node == m_end)
    {
        push_back(data);
        return *this;
    }

    iterator1.cur_node->next->prev = new_node;
    new_node->prev = iterator1.cur_node;
    new_node->next = iterator1.cur_node->next;
    iterator1.cur_node->next = new_node;
    m_size++;
    return *this;


}

template<class T>
List<T>& List<T>::insert_after(T after, T data, bool not_integer)
{
    Node* new_node = new Node(data);

    if(m_size == 0)
    {
        push_back(data);
        return *this;
    }

    auto iterator1 = begin();

    while(*iterator1 != after){iterator1++;}

    if(iterator1.cur_node == m_end)
    {
        push_back(data);
        return *this;
    }

    iterator1.cur_node->next->prev = new_node;
    new_node->prev = iterator1.cur_node;
    new_node->next = iterator1.cur_node->next;
    iterator1.cur_node->next = new_node;

    m_size++;

    return *this;

}

template <class T>
List<T>& List<T>::remove_first()
{
    assert(m_size >0);

    if(m_size == 1)
    {
        delete m_begin;
        m_begin = m_end = NULL;
    }
    else
    {
        m_begin = m_begin->next;
        m_begin->prev = NULL;
        delete m_begin->prev;
    }

    m_size--;

    return *this;
}

template <class T>
List<T>& List<T>::remove_last()
{
    assert(m_size >0);

    if(m_size == 1)
    {
        delete m_end;
        m_end = m_begin = NULL;
    }
    else
    {
        m_end = m_end->prev;
        m_end->next = NULL;
        delete m_end->next;
    }

    m_size--;

    return *this;
}

template <class T>
List<T>& List<T>::remove(int position)
{
    assert(position >=0 && position < m_size);

    auto iter = begin();

    int i =0;

    while(i!=position)
    {
        iter++;
        i++;
    }

    if(iter.cur_node == m_begin)
    {
        remove_first();
        return *this;
    }
    else if (iter.cur_node == m_end)
    {
        remove_last();
        return *this;
    }

    iter.cur_node->next->prev = iter.cur_node->prev;

    iter.cur_node->prev->next = iter.cur_node->next;

    delete iter.cur_node;

    m_size--;

    return *this;
}

template <class T>
List<T>& List<T>::remove(T data,bool not_integer)
{
    assert(m_size > 0);

    auto iter = begin();

    while(*iter != data ){ iter++; }

    if(iter.cur_node == m_begin)
    {
        remove_first();
        return *this;
    }
    else if (iter.cur_node == m_end)
    {
        remove_last();
        return *this;
    }

    iter.cur_node->next->prev = iter.cur_node->prev;

    iter.cur_node->prev->next = iter.cur_node->next;

    delete iter.cur_node;

    m_size--;

    return *this;

}

template<class T>
List<T>& List<T>::sort()
{
    bool ok = true;

    while(ok)
    {
        ok = false;

        auto i = begin();
        auto i_fr = ++begin();

        while (i.cur_node != m_end)
        {
            if (*i > *i_fr)
            {
                swap(i, i_fr);
                ok = true;
            }
            i++;
            i_fr++;
        }
    }
    return *this;
}

template<class T>
List<T>& List<T>::reverse()
{
    auto it_begin = begin();
    auto it_end = end();

    for(int i =0;i<m_size/2;i++)
    {
        swap(it_begin,it_end);
        it_begin++;
        it_end--;
    }
    return *this;
}

template <class T>
List<T>& List<T>::erase()
{
    while(m_size!=0)
    {
        remove_first();
    }
}

template <class T>
T& List<T>::operator[](int index)
{
    assert(index >= 0 && index < m_size);

    int i =0;
    auto iter = begin();
    while(i!=index){i++;iter++;}

    return iter.cur_node->data;
}
