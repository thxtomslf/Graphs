//
// Created by Pavel on 23.12.2022.
//

#ifndef GRAPHS_SETGRAPH_H
#define GRAPHS_SETGRAPH_H

#include "IGraph.h"
#include "unordered_set"

struct SetGraph : public IGraph {
public:
    explicit SetGraph(size_t verticesCount);
    SetGraph(const IGraph&);

    ~SetGraph() override = default;

    void AddEdge(int from, int to) override;

    size_t VerticesCount() const  override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::vector<std::unordered_set<int>> graph;
    size_t verticesCount;
};

#endif //GRAPHS_SETGRAPH_H
