#include "Graph.hpp"

namespace ariel
{
    class Algorithms
    {
        public:
            static int isConnected(ariel::Graph);
            static char* shortestPath(ariel::Graph, int, int);
            static char* isContainsCycle(ariel::Graph);
            static char* isBipartite(ariel::Graph);
            static char* negativeCycle(ariel::Graph);

    };
}