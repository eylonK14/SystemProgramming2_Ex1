#include "Graph.hpp"

void ariel::Graph::loadGraph(std::vector<std::vector<int>> matrix)
{
    for (std::size_t i = 0; i < matrix.size(); i++)
    {
        if(matrix[i].size() != matrix.size())
        {
            throw new std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        this->_vertexs.insert(i);

        for (int j = 0; j < matrix[i].size(); j++)
        {
            this->_vertexs.insert({(i, j), matrix[i][j]});
        }
    }
}