//
// Created by sajith on 3/30/21.
//

#include <iostream>

class UndirectedGraph
{
};

class DirectedGraph
{
};


template<typename Graph>
struct GraphAlgorithm
{
    const Graph graph;

    void search()
    {
        std::cout << "Some search algorithm  for graph\n";
    }
};


template<>
struct GraphAlgorithm<DirectedGraph>
{
    const DirectedGraph directedGraph;

    void search()
    {
        std::cout << "Some search algorithm only for directed graph\n";
    }
};


template<typename Graph>
void run(const Graph &graph)
{
    GraphAlgorithm<Graph> algo{graph};
    algo.search();
}

int main()
{
    run(UndirectedGraph());
    run(DirectedGraph());
    return 0;
}