cmake_minimum_required(VERSION 3.22)
project(Graphs)

set(CMAKE_CXX_STANDARD 14)

add_executable(Graphs include/IGraph.h src/ListGraph.cpp include/ListGraph.h main.cpp src/MatrixGraph.cpp include/MatrixGraph.h include/SetGraph.h src/SetGraph.cpp src/ArcGraph.cpp src/ArcGraph.h)
