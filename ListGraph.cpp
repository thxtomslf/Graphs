//
// Created by Pavel on 23.12.2022.
//
#include "ListGraph.h"

ListGraph::ListGraph(size_t verticesCount) : graph(verticesCount), verticesCount(verticesCount) {}

ListGraph::ListGraph(const IGraph &otherGraph) {
    size_t size = otherGraph.VerticesCount();
    verticesCount = size;
    graph = std::vector<std::forward_list<int>>(size);
    for (int parent = 0; parent < size; ++parent) {
        for (int ver : otherGraph.GetNextVertices(parent)) {
            graph[parent].push_front(ver);
        }
    }

}


void ListGraph::AddEdge(int from, int to) {
    graph[from].push_front(to);
}

size_t ListGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (int ver : graph[vertex]) {
        result.push_back(ver);
    }
    return result;
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int parent = 0; parent < verticesCount; ++parent) {
        for (int ver : graph[parent]) {
            if (ver == vertex) {
                result.push_back(parent);
            }
        }
    }
    return result;
}



