//
// Created by Pavel on 23.12.2022.
//

#include "../include/SetGraph.h"

SetGraph::SetGraph(size_t verticesCount) : verticesCount(verticesCount), graph(verticesCount) {}

SetGraph::SetGraph(const IGraph &otherGraph) {
    size_t size = otherGraph.VerticesCount();
    verticesCount = size;
    graph = std::vector<std::unordered_set<int>>(otherGraph.VerticesCount());
    for (int parent = 0; parent < size; ++parent) {
        for (int ver : otherGraph.GetNextVertices(parent)) {
            graph[parent].insert(ver);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    graph[from].insert(to);
}

size_t SetGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;

    for (int ver : graph[vertex]) {
        result.push_back(ver);
    }
    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int parent = 0; parent < verticesCount; ++parent) {
        for (int ver : graph[parent]) {
            if (ver == vertex) {
                result.push_back(parent);
                break;
            }
        }
    }
    return result;
}

