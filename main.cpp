#include <iostream>

#include "include/ListGraph.h"
#include "src/ArcGraph.h"
#include "include/SetGraph.h"
#include "include/MatrixGraph.h"


int main() {
    std::cout << "==========ListGraphTest=========" << std::endl;
    ListGraph listGraph(5);
    listGraph.AddEdge(2, 3);
    listGraph.AddEdge(3, 4);
    listGraph.AddEdge(4, 2);
    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 2);

    std::cout << "Children of 0" << std::endl;
    std::vector<int> children = listGraph.GetNextVertices(0);
    for (int ver : children) {
        std::cout << ver << "\n";
    }

    std::cout << "Parent of 2" << std::endl;
    std::vector<int> parent = listGraph.GetPrevVertices(2);
    for (int ver : parent) {
        std::cout << ver << "\n";
    }


    std::cout << "==========SetGraphTest=========" << std::endl;
    // Тестирование констркутора копирования
    SetGraph setGraph(listGraph);

    std::cout << "Children of 0" << std::endl;
    std::vector<int> children2 = setGraph.GetNextVertices(0);
    for (int ver : children2) {
        std::cout << ver << "\n";
    }

    std::cout << "Parent of 2" << std::endl;
    std::vector<int> parent2 = setGraph.GetPrevVertices(2);
    for (int ver : parent2) {
        std::cout << ver << "\n";
    }

    std::cout << "==========MatrixGraphTest=========" << std::endl;
    // Тестирование констркутора копирования
    MatrixGraph matrixGraph(setGraph);

    std::cout << "Children of 0" << std::endl;
    std::vector<int> children3 = matrixGraph.GetNextVertices(0);
    for (int ver : children3) {
        std::cout << ver << "\n";
    }

    std::cout << "Parent of 2" << std::endl;
    std::vector<int> parent3 = matrixGraph.GetPrevVertices(2);
    for (int ver : parent3) {
        std::cout << ver << "\n";
    }

    std::cout << "==========ArcGraphTest=========" << std::endl;
    // Тестирование констркутора копирования
    ArcGraph arcGraph(matrixGraph);

    std::cout << "Children of 0" << std::endl;
    std::vector<int> children4 = arcGraph.GetNextVertices(0);
    for (int ver : children4) {
        std::cout << ver << "\n";
    }

    std::cout << "Parent of 2" << std::endl;
    std::vector<int> parent4 = arcGraph.GetPrevVertices(2);
    for (int ver : parent4) {
        std::cout << ver << "\n";
    }

    std::cout << "==========ListGraphTest2=========" << std::endl;
    // Тестирование констркутора копирования
    ListGraph listGraph2(arcGraph);

    std::cout << "Children of 0" << std::endl;
    std::vector<int> children5 = listGraph2.GetNextVertices(0);
    for (int ver : children4) {
        std::cout << ver << "\n";
    }

    std::cout << "Parent of 2" << std::endl;
    std::vector<int> parent5 = listGraph2.GetPrevVertices(2);
    for (int ver : parent5) {
        std::cout << ver << "\n";
    }

    return 0;
}
