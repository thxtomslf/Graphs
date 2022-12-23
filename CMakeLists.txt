cmake_minimum_required(VERSION 3.22)
project(Graphs)

set(CMAKE_CXX_STANDARD 14)

add_executable(Graphs IGraph.h ListGraph.cpp ListGraph.h main.cpp MatrixGraph.cpp MatrixGraph.h SetGraph.h SetGraph.cpp ArcGraph.cpp ArcGraph.h)
