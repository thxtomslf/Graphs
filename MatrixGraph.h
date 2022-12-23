//
// Created by Pavel on 23.12.2022.
//

#ifndef GRAPHS_MATRIXGRAPH_H
#define GRAPHS_MATRIXGRAPH_H

#include "IGraph.h"

struct MatrixGraph : public IGraph {
public:
    explicit MatrixGraph(size_t verticesCount);
    MatrixGraph(const IGraph&);

    ~MatrixGraph() override;

    void AddEdge(int from, int to) override;

    size_t VerticesCount() const  override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
private:
    int **graph{};
    size_t verticesCount{};
};

#endif //GRAPHS_MATRIXGRAPH_H
