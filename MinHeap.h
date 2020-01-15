//
// Created by ivan on 06.01.20.
//

#ifndef DATA_STRUCTURES_MINHEAP_H
#define DATA_STRUCTURES_MINHEAP_H

#include <iostream>
#include <cassert>
#include <initializer_list>

#define MAX_MIN_HEAP_SIZE 100000

using std::cout;
using std::endl;
using std::initializer_list;


namespace MinHeapSPACE
{
    template<class T, int capacity = 100>
    class MinHeap
    {
    private:  //private members

        T* m_arr;
        int m_size;
        int m_capacity{};

    private: // private methods

        void swap(T& n1, T& n2);

        // returns index of parent
        int parent(int i) { return ((i-1) / 2);}

        // returns index pf left child
        int left(int i) { return (2*i + 1); }

        // returns index of right child
        int right(int i) { return (2*i + 2); }

        void heapify(int i);

        void decreaseKey(int i,int new_key);

    public:
        MinHeap();

        MinHeap(initializer_list<T> list);

        // constructor of copy
        MinHeap(const MinHeap& copyHeap);

        ~MinHeap() {delete[] m_arr;}

        int size(){ return m_size;}

        int getCapacity() {return m_capacity;}

        MinHeap& insert(T data);

        // extend new capacity to  bigger one
        MinHeap& extend(int new_capacity);

        // narrow down capacity to a smaller one
        MinHeap& narrow_down(int new_capacity);

        T getMinElem() { assert(m_size!=0); return m_arr[0]; }

        void see();

        //deletes minimum element
        MinHeap& deleteMin();

        bool empty() {return m_size == 0;}

        //deletes element with certain index i
        MinHeap& delete_elem(int i);

        MinHeap& operator=(const MinHeap& copyHeap);

        void erase();

    };

    template<class T, int capacity>
    MinHeap<T, capacity>::MinHeap() : m_size(0), m_capacity(capacity)
    {
        m_arr = new T[m_capacity];
    }

    template<class T, int capacity>
    MinHeap<T, capacity>::MinHeap(initializer_list<T> list) : MinHeap()
    {
        if(list.size() > m_capacity )
        {
            m_capacity = list.size();
            delete [] m_arr;
            m_arr = new T[m_capacity];
        }

        for(auto item : list)
        {
            insert(item);
        }

    }


    template<class T, int capacity>
    MinHeap<T, capacity>::MinHeap(const MinHeap &copyHeap)
    {
        m_size = copyHeap.m_size;
        m_capacity = copyHeap.m_capacity;

        if (copyHeap.m_arr)
        {
            m_arr = new T[m_size];

            for (int i = 0; i < m_size; i++)
                m_arr[i] = copyHeap.m_arr[i];
        }
        else
            m_arr = 0;
    }


    template<class T, int capacity>
    MinHeap<T,capacity>& MinHeap<T, capacity>::insert(T data)
    {

        assert(m_size <= MAX_MIN_HEAP_SIZE);
        if(m_capacity == m_size)
        {
            extend(m_size + 1);
        }

        m_arr[m_size] = data;

        m_size++;

        int i = m_size - 1;

        while(i != 0 && m_arr[parent(i)] > m_arr[i])
        {
            swap(m_arr[parent(i)] ,m_arr[i]);
            i = parent(i);
        }

        return *this;
    }

    template<class T, int capacity>
    MinHeap<T,capacity>& MinHeap<T, capacity>::extend(int new_capacity)
    {
        assert( new_capacity > m_capacity);

        m_capacity = new_capacity;

        T* new_arr  = new T[new_capacity];

        for(int i = 0; i < m_size; i++)
        {
            new_arr[i] = m_arr[i];
        }

        delete[] m_arr;
        m_arr = new_arr;

        return *this;
    }

    template<class T, int capacity>
    MinHeap<T,capacity> &MinHeap<T, capacity>::narrow_down(int new_capacity)
    {
        assert(new_capacity < m_capacity && new_capacity >= 0);

        m_size = new_capacity;
        m_capacity = new_capacity;
        T* new_arr = new T[m_capacity];

        for(int i = 0; i < m_size; i++)
        {
            new_arr[i] = m_arr[i];
        }

        delete[] m_arr;
        m_arr = new_arr;

        return *this;
    }

    template<class T, int capacity>
    void MinHeap<T, capacity>::swap(T& n1, T& n2)
    {
        T n3 = n1;
        n1 = n2;
        n2 = n3;
    }

    template<class T, int capacity>
    void MinHeap<T, capacity>::see()
    {
        for(int i = 0; i < m_size; i++)
        {
            cout << m_arr[i]<<" ";
        }
    }

    template<class T, int capacity>
    MinHeap<T,capacity> &MinHeap<T, capacity>::deleteMin()
    {
        if(m_size == 0)
        {
            cout<<"heap is empty!";
        }
        else if(m_size == 1)
        {
            m_size--;
        }
        else
        {
            m_size--;
            m_arr[0] = m_arr[m_size];
            heapify(0);
        }

        return *this;
    }

    template<class T, int capacity>
    void MinHeap<T, capacity>::heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < m_size && m_arr[l] < m_arr[i])
            smallest = l;
        if (r < m_size && m_arr[r] < m_arr[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(m_arr[i], m_arr[smallest]);
            heapify(smallest);
        }
    }

    template<class T, int capacity>
    MinHeap<T,capacity> &MinHeap<T, capacity>::delete_elem(int i)
    {
        assert( i >=0 && i < m_size);
        decreaseKey(i,INT32_MIN);
        deleteMin();
        return *this;
    }

    template<class T, int capacity>
    void MinHeap<T, capacity>::decreaseKey(int i, int new_key)
    {
        assert(new_key <= m_arr[i]);

        m_arr[i] = new_key;

        while(i != 0 && m_arr[parent(i)] > m_arr[i])
        {
            swap(m_arr[i],m_arr[parent(i)]);
            i = parent(i);
        }
    }

    template<class T, int capacity>
    MinHeap<T,capacity> &MinHeap<T, capacity>::operator=(const MinHeap &copyHeap)
    {
        // checking for self-assignment
        if (this == &copyHeap)
            return *this;

        delete[] m_arr;

        m_size = copyHeap.m_size;
        m_capacity = copyHeap.m_capacity;

        // m_arr є вказівником , тому нам слід виконати глибоке копіювання,
        // при умові ,що вказівние не є нульовим
        if (copyHeap.m_arr)
        {
            m_arr = new T[m_size];

            for (int i = 0; i < m_size; i++)
                m_arr[i] = copyHeap.m_arr[i];
        }
        else
            m_arr = 0;

        return *this;
    }

    template<class T, int capacity>
    void MinHeap<T, capacity>::erase()
    {
        delete[] m_arr;
        m_arr = new T[m_capacity];
        m_size = 0;
    }

}


#endif //DATA_STRUCTURES_MINHEAP_H
