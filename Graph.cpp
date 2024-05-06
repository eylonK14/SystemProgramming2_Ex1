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

    for (std::size_t i = 0; i < matrix.size(); i++)
    {
        for (std::size_t j = 0; j < matrix[i].size(); j++)
        {
            this->_graph[i][j] = matrix[i][j];
        }
    }
}

void ariel::Graph::printGraph()
{
    int edges = 0;
    for (std::size_t i = 0; i < this->_graph.size(); i++)
    {
        for (std::size_t j = 0; j < this->_graph[i].size(); j++)
        {
            if (this->_graph[i][j] != 0 && this->_graph[j][i] != 0)
            {
                edges++;
            }
        }
    }

    std::cout << "Graph with " << this->_graph[0].size() << " vertices and " << edges << " edges." << std::endl;
}
