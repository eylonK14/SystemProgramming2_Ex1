#include "Algorithms.hpp"

std::string ariel::Algorithms::shortestPath(ariel::Graph g, int start, int end)
{
    std::vector<int> distanceList, parentList;
    if(BellmanFord(g, start, distanceList, parentList))
    {
        std::string path = std::to_string(parentList[end]);
        for (std::size_t i = parentList[end]; i < start; i++)
        {
            path += ">-" + parentList[i];
        }
        return path;
    }
    return "-1";
}

void ariel::Algorithms::relax(std::pair<std::pair<int, int>, int> edge, std::vector<int> distanceList, std::vector<int> parentList)
{
    if (distanceList[edge.first.first] > distanceList[edge.first.second] + edge.second)
    {
        distanceList[edge.first.first] = distanceList[edge.first.second] + edge.second;
        parentList[edge.first.first] = edge.first.second;
    }
}

bool ariel::Algorithms::BellmanFord(ariel::Graph g, int start, std::vector<int> distanceList, std::vector<int> parentList)
{
    for (int i : g.getVertexs())
    {
        distanceList[i] = __INT_MAX__;
        parentList[i] = -1; //remember to change
    }

    distanceList[start] = 0;

    for (int i = 0; i < g.getVertexsSize(); i++)
    {
        for (const auto &edge : g.getEdges())
        {
            relax(edge, distanceList, parentList);
        }
    }

    for (const auto &edge : g.getEdges())
    {
        if (distanceList[edge.first.first] > distanceList[edge.first.second] + edge.second)
        {
            return false;
        }
    }

    return true;
}