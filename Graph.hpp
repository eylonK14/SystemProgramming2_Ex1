#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <map>

namespace ariel
{
    class Graph
    {
        private:
            std::set<int> _vertexs;
            std::map<std::pair<int, int>, int> _edges;

        public:
            void loadGraph(std::vector<std::vector<int>>);
            void printGraph() {std::cout << "Graph with " << this->_vertexs.size() << " vertices and " << this->_edges.size() << " edges." << std::endl;};

            std::set<int> getVertexs() {return this->_vertexs;}
            std::map<std::pair<int, int>, int> getEdges() {return this->_edges;}

            int getVertexsSize() {return this->_vertexs.size();}
    };
}