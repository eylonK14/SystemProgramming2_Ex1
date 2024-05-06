#pragma once

#include <iostream>
#include <vector>

namespace ariel
{
    class Graph
    {
        private:
            std::vector<std::vector<int>> _graph;
            bool _isWeighted;
            bool _isDirected;

        public:
            void loadGraph(std::vector<std::vector<int>>);
            void printGraph();

            bool isWeighted() {return this->_isWeighted;}
            bool isDirected() {return this->_isDirected;}

    };
}