#ifndef INPUT_GENERATOR_CHAIN_HPP_
#define INPUT_GENERATOR_CHAIN_HPP_

#include "exception.hpp"
#include "boolean.hpp"
#include "graph.hpp"

namespace inputGenerator {

// you can generate a non-random graph if you really want
// by making the second parameter false
// this is undirected
template<class NodeData = void, class EdgeData = void>
Graph<NodeData, EdgeData> chain(const int &size = 1,
                                Boolean::Object random = Boolean::True) {
#ifdef INPUT_GENERATOR_DEBUG
    if (size <= 0)
        throw Exception("Chains must have strictly positive sizes");
#endif
    Graph<NodeData, EdgeData> graph(size);
    for (int i = 1; i < size; ++i) {
        addEdge(graph[i - 1], graph[i]);
    }

    if (random)
        graph.Index();

    return graph;
}

template<class NodeData = void, class EdgeData = void>
Graph<NodeData, EdgeData> path(const int &size = 1,
                               Boolean::Object random = Boolean::True) {
#ifdef INPUT_GENERATOR_DEBUG
    if (size <= 0)
        throw Exception("Paths must have strictly positive sizes");
#endif
    Graph<NodeData, EdgeData> graph(size);
    for (int i = 1; i < size; ++i)
        graph[i - 1].addEdge(graph[i]);

    if (random)
        graph.Index();

    return graph;
}

}  // namespace inputGenerator

#endif  // INPUT_GENERATOR_CHAIN_HPP_

