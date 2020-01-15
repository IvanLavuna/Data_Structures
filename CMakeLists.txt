cmake_minimum_required(VERSION 3.15)

project(Data_Structures)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES List.h Queue.h Stack.h BST.h BST.cpp Graph.h Graph.cpp AlgoBST.h MinHeap.h MaxHeap.h Priority_Queue.h BinomialHeap.cpp BinomialHeap.h FibonacciHeap.cpp FibonacciHeap.h)

#adding library

add_executable(Data_Structures ${SOURCE_FILES})
