//
// Created by ivan on 07.01.20.
//

#ifndef DATA_STRUCTURES_MAXHEAP_H
#define DATA_STRUCTURES_MAXHEAP_H
#include <iostream>
#include <cassert>
#include <initializer_list>

#define MAX_MAX_HEAP_SIZE 100000

using std::cout;
using std::endl;
using std::initializer_list;

namespace MaxHeapSPACE
{
    template<class T,int capacity = 100>
    class MaxHeap
    {
    private: //private members
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

        // move down
        void heapify(int i);

        // move up
        void enlargeKey(int i,int new_data);

    public:
        MaxHeap();

        MaxHeap(initializer_list<T> list);

        MaxHeap(const MaxHeap& copyHeap);

        ~MaxHeap() {delete[] m_arr;}

        int size(){ return m_size;}

        int getCapacity() {return m_capacity;}

        MaxHeap& insert(T data);

        // extend new capacity to  bigger one
        MaxHeap& extend(int new_capacity);

        // narrow down capacity to a smaller one
        MaxHeap& narrow_down(int new_capacity);

        T getMaxElem() { assert(m_size!=0); return m_arr[0]; }

        void see();

        //deletes maximum element
        MaxHeap& deleteMax();

        bool empty() {return m_size == 0;}

        // to delete element with certain index i
        MaxHeap& delete_elem(int i);

        MaxHeap& operator=(const MaxHeap& copyHeap);

        void erase();

    };

    template<class T, int capacity>
    MaxHeap<T, capacity>::MaxHeap() : m_size(0), m_capacity(capacity)
    {
        m_arr = new T[m_capacity];
    }

    template<class T, int capacity>
    MaxHeap<T, capacity>::MaxHeap(initializer_list <T> list) : MaxHeap()
    {
        if(list.size() > m_capacity )
        {
            m_capacity = list.size();
            delete[] m_arr;
            m_arr = new T[m_capacity];
        }

        for(auto item : list)
        {
            insert(item);
        }
    }

    template<class T, int capacity>
    MaxHeap<T, capacity>::MaxHeap(const MaxHeap &copyHeap)
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
    MaxHeap<T,capacity> &MaxHeap<T, capacity>::insert(T data)
    {
        assert(m_size <= MAX_MAX_HEAP_SIZE);
        if(m_capacity == m_size)
        {
            extend(m_size + 1);
        }
        m_arr[m_size] = data;

        m_size++;
        int i = m_size - 1;

        enlargeKey(i,data);

        return *this;
    }

    template<class T, int capacity>
    void MaxHeap<T, capacity>::swap(T& n1, T& n2)
    {
        T n3 = n1;
        n1 = n2;
        n2 = n3;
    }

    template<class T, int capacity>
    MaxHeap<T,capacity> &MaxHeap<T, capacity>::extend(int new_capacity)
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
    MaxHeap<T,capacity> &MaxHeap<T, capacity>::narrow_down(int new_capacity)
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
    void MaxHeap<T, capacity>::see()
    {
        for(int i = 0; i < m_size; i++)
        {
            cout << m_arr[i]<<" ";
        }
    }

//move up
    template<class T, int capacity>
    void MaxHeap<T, capacity>::enlargeKey(int i, int new_data)
    {
        assert(new_data >= m_arr[i]);

        m_arr[i] = new_data;

        while(i != 0 && m_arr[parent(i)] < m_arr[i])
        {
            swap(m_arr[parent(i)],m_arr[i]);
            i = parent(i);
        }
    }

//move down
    template<class T, int capacity>
    void MaxHeap<T, capacity>::heapify(int i)
    {
        assert(i >=0 && i < m_size);

        int l = left(i);
        int r = right(i);

        int biggest = i;

        if (l < m_size && m_arr[l] > m_arr[i])
            biggest = l;
        if (r < m_size && m_arr[r] > m_arr[biggest])
            biggest = r;
        if (biggest != i)
        {
            swap(m_arr[i], m_arr[biggest]);
            heapify(biggest);
        }
    }

    template<class T, int capacity>
    MaxHeap<T,capacity> &MaxHeap<T, capacity>::operator=(const MaxHeap &copyHeap)
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
    MaxHeap<T,capacity> &MaxHeap<T, capacity>::deleteMax()
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

// to delete element with certain index i
    template<class T, int capacity>
    MaxHeap<T,capacity> &MaxHeap<T, capacity>::delete_elem(int i)
    {
        assert( i >= 0 && i < m_size);
        enlargeKey(i,INT32_MAX);
        deleteMax();
        return *this;
    }
    template<class T, int capacity>
    void MaxHeap<T, capacity>::erase()
    {
        delete[] m_arr;
        m_arr = new T[m_capacity];
        m_size = 0;
    }
}

#endif //DATA_STRUCTURES_MAXHEAP_H
