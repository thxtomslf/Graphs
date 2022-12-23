//
// Created by Pavel on 23.12.2022.
//

#ifndef GRAPHS_LISTGRAPH_H
#define GRAPHS_LISTGRAPH_H

#include "IGraph.h"
#include "forward_list"

class ListGraph : public IGraph {
public:
    explicit ListGraph(size_t verticesCount);
    ListGraph(const IGraph&);

    ~ListGraph() override = default;

    void AddEdge(int from, int to) override;

    size_t VerticesCount() const  override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::vector<std::forward_list<int>> graph;
    size_t verticesCount{};
};



#endif //GRAPHS_LISTGRAPH_H
