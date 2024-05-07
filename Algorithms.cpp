#include "Algorithms.hpp"

std::string ariel::Algorithms::shortestPath(ariel::Graph g, int start, int end)
{
    std::vector<int> distanceList, parentList;
    if (BellmanFord(g, start, distanceList, parentList).compare("There are no negative cycles in the graph."))
    {
        std::string path = std::to_string(parentList[end]);
        for (std::size_t i = parentList[end]; i < start; i++)
        {
            path += ">-" + parentList[i];
        }

        std::reverse(path.begin(), path.end());
        return path;
    }
    return "-1";
}

std::string ariel::Algorithms::negativeCycle(ariel::Graph g)
{
    std::vector<int> distanceList, parentList;
    std::string bellmanFord = BellmanFord(g, 0, distanceList, parentList);

    if(bellmanFord.compare("There are no negative cycles in the graph.") == 0)
    {
        return bellmanFord;
    }

    std::reverse(bellmanFord.begin(), bellmanFord.end());
    return bellmanFord;
}

void ariel::Algorithms::relax(std::pair<std::pair<int, int>, int> edge, std::vector<int> distanceList, std::vector<int> parentList)
{
    if (distanceList[edge.first.first] > distanceList[edge.first.second] + edge.second)
    {
        distanceList[edge.first.first] = distanceList[edge.first.second] + edge.second;
        parentList[edge.first.first] = edge.first.second;
    }
}

std::string ariel::Algorithms::BellmanFord(ariel::Graph g, int start, std::vector<int> distanceList, std::vector<int> parentList)
{
    for (int i : g.getVertexs())
    {
        distanceList[i] = __INT_MAX__;
        parentList[i] = -1;
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
            int father = edge.first.first;
            std::string path = "";
            path += father;

            std::size_t i = parentList[father - 1];

            while (i != father)
            {
                path += ">-" + parentList[i];
                i = parentList[i];
            }

            return path;
        }
    }

    return "There are no negative cycles in the graph.";
}