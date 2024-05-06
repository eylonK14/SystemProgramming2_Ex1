#include "Graph.hpp"

namespace ariel
{
    class Algorithms
    {
        public:
            static int isConnected(ariel::Graph);
            static std::string shortestPath(ariel::Graph, int, int);
            static std::string isContainsCycle(ariel::Graph);
            static std::string isBipartite(ariel::Graph);
            static std::string negativeCycle(ariel::Graph);

        private:
            static bool BellmanFord(ariel::Graph, int, std::vector<int>, std::vector<int>);
            static void relax(std::pair<std::pair<int, int>, int>, std::vector<int>, std::vector<int>);

    };
}