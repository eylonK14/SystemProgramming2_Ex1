#include "Algorithms.hpp"

bool ariel::Algorithms::isConnected(ariel::Graph g)
{
    return true;
}

std::string ariel::Algorithms::isContainsCycle(ariel::Graph g)
{
    return "isContainsCycle not implemeted";
}

std::string ariel::Algorithms::isBipartite(ariel::Graph g)
{
    return "isBipartite not implemeted";
}

std::string ariel::Algorithms::shortestPath(ariel::Graph g, int start, int end)
{
    std::size_t s = static_cast<std::size_t>(start);
    std::size_t e = static_cast<std::size_t>(end);

    std::vector<std::size_t> parentList;
    std::vector<int> distanceList;

    std::string Bellmanford = BellmanFord(g, s, distanceList, parentList);

    if (Bellmanford.compare("There are no negative cycles in the graph.") == 0)
    {
        std::string path = std::to_string(e);
        for (std::size_t i = parentList[e]; i >= start && i != __INT_MAX__;)
        {
            path += ">-";
            path += std::to_string(i);
            i = parentList[i];
        }

        std::reverse(path.begin(), path.end());
        if (path[0] == (char)(start + '0'))
        {
            return path;
        }
        return "-1";
    }
    return "-1";
}

std::string ariel::Algorithms::negativeCycle(ariel::Graph g)
{
    std::vector<std::size_t> parentList;
    std::vector<int> distanceList;
    std::string bellmanFord = BellmanFord(g, 0, distanceList, parentList);

    if (bellmanFord.compare("There are no negative cycles in the graph.") == 0)
    {
        return bellmanFord;
    }

    std::reverse(bellmanFord.begin(), bellmanFord.end());
    return bellmanFord;
}

void ariel::Algorithms::relax(std::pair<std::pair<std::size_t, std::size_t>, int> edge, std::vector<int> &distanceList, std::vector<std::size_t> &parentList)
{
    if (distanceList[edge.first.second] > distanceList[edge.first.first] + edge.second)
    {
        distanceList[edge.first.second] = distanceList[edge.first.first] + edge.second;
        parentList[edge.first.second] = edge.first.first;
    }
}

std::string ariel::Algorithms::BellmanFord(ariel::Graph g, std::size_t start, std::vector<int> &distanceList, std::vector<std::size_t> &parentList)
{
    for (long i = 0; i < g.getVertexs().size(); i++)
    {
        distanceList.insert(distanceList.begin() + i, __INT_MAX__);
        parentList.insert(parentList.begin() + i, __INT_MAX__);
    }

    distanceList[start] = 0;

    for (std::size_t i = 0; i < g.getVertexsSize() - 1; i++)
    {
        for (const auto &edge : g.getEdges())
        {
            relax(edge, distanceList, parentList);
        }
    }

    for (const auto &edge : g.getEdges())
    {
        if (distanceList[edge.first.second] > distanceList[edge.first.first] + edge.second)
        {
            std::size_t father = edge.first.first;
            std::string path = std::to_string(father);
            std::size_t i = parentList[father];
            bool flag = true;

            while (flag)
            {
                path += ">-";
                path += std::to_string(i);
                i = parentList[i];
                flag = !(i == parentList[father]);
            }

            return path;
        }
    }

    return "There are no negative cycles in the graph.";
}