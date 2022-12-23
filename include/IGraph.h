#include <vector>

#ifndef GRAPHS_IGRAPH_H
#define GRAPHS_IGRAPH_H

struct IGraph {
    virtual ~IGraph() = default;

    // Добавление ребра от from к to.
    virtual void AddEdge(int from, int to) = 0;

    virtual size_t VerticesCount() const  = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};


#endif //GRAPHS_IGRAPH_H