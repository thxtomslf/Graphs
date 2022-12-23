//
// Created by Pavel on 23.12.2022.
//

#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(size_t verticesCount) : verticesCount(verticesCount) {
    graph = new int*[verticesCount];

    for (size_t i = 0; i < verticesCount; ++i) {
        graph[i] = new int[verticesCount];
        for (size_t j = 0; j < verticesCount; ++j) {
            graph[i][j] = 0;
        }
    }
}

MatrixGraph::MatrixGraph(const IGraph &otherGraph) {
    size_t size = otherGraph.VerticesCount();
    verticesCount = size;
    graph = new int*[size];
    for (int i = 0; i < size; ++i) {
        graph[i] = new int[size];
        for (size_t j = 0; j < size; ++j) {
            graph[i][j] = 0;
        }
        for (int ver : otherGraph.GetNextVertices(i)) {
            graph[i][ver] = 1;
        }
    }
}

MatrixGraph::~MatrixGraph() {
    for (size_t i = 0; i < verticesCount; ++i) {
        delete graph[i];
    }
    delete graph;
}

void MatrixGraph::AddEdge(int from, int to) {
    graph[from][to] = 1;
}

size_t MatrixGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i < verticesCount; ++i) {
        if (graph[vertex][i] != 0) {
            result.push_back(i);
        }
    }

    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i < verticesCount; ++i) {
        if (graph[i][vertex] != 0) {
            result.push_back(i);
        }
    }

    return result;
}

