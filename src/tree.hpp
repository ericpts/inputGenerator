#ifndef INPUT_GENERATOR_TREE_HPP_
#define INPUT_GENERATOR_TREE_HPP_

#include "exception.hpp"
#include "graph.hpp"
#include "vectors.hpp"

namespace inputGenerator {

template<class NodeData = int, class EdgeData = int>
Graph<NodeData, EdgeData> tree(const int &size = 1) {
    if (size <= 0)
        throw Exception("Trees must have strictly positive sizes");

    Graph<NodeData, EdgeData> graph;
    for (int i = 1; i < size; ++i) {
        typename Graph<NodeData, EdgeData>::Node node;
        typename Graph<NodeData, EdgeData>::Node &parent = randomElement(graph);

        parent.addEdge(node);
        node.addEdge(parent);

        graph.addNodes({node});
    }

    graph.Index();

    return graph;
}

}

#endif // INPUT_GENERATOR_HPP_