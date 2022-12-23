//
// Created by Pavel on 23.12.2022.
//

#include "ArcGraph.h"
#include "set"

ArcGraph::ArcGraph(size_t verticesCount) : verticesCount(verticesCount), graph(verticesCount) {}

ArcGraph::ArcGraph(const IGraph &otherGraph) {
    size_t size = otherGraph.VerticesCount();
    verticesCount = size;
    for (int parent = 0; parent < size; ++parent) {
        for (int ver : otherGraph.GetNextVertices(parent)) {
            graph.push_back({parent, ver});
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    graph.push_back({from ,to});
}

size_t ArcGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (auto pair : graph) {
        if (pair.first == vertex) {
            result.push_back(pair.second);
        }
    }
    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::set<int> uniqueVertexes;
    std::vector<int> result;
    for (auto pair : graph) {
        if (pair.second == vertex) {
            result.push_back(pair.first);
        }
    }

    for (auto pair : uniqueVertexes) {
        result.push_back(pair);
    }

    return result;
}
