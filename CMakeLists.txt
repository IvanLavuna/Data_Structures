cmake_minimum_required(VERSION 3.15)
project(Data_Structures)

set(CMAKE_CXX_STANDARD 14)

add_executable(Data_Structures List.h List.cpp main.cpp Stack.cpp Stack.h Queue.cpp Queue.h DisjoinSet.cpp DisjoinSet.h)

