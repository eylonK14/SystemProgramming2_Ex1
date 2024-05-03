#pragma once

namespace ariel
{
    class Graph
    {
        private:
            std::vector<std::vector<int>> _graph;

        public:
            void loadGraph(std::vector<std::vector<int>>);
            void printGraph();

    };
}