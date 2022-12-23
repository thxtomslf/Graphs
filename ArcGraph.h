//
// Created by Pavel on 23.12.2022.
//

#ifndef GRAPHS_ARCGRAPH_H
#define GRAPHS_ARCGRAPH_H

#include "IGraph.h"

struct ArcGraph : public IGraph {
public:
    explicit ArcGraph(size_t verticesCount);
    ArcGraph(const IGraph&);

    ~ArcGraph() = default;

    void AddEdge(int from, int to) override;

    size_t VerticesCount() const  override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::vector<std::pair<int, int>> graph;
    size_t verticesCount;
};


#endif //GRAPHS_ARCGRAPH_H
