// id: 325550069  mail: yehudav03@gmail.com
#include "Graph.hpp"

namespace ariel
{
    Graph::Graph()
    {
        this->size = 0;
        this->Edges = 0;
        this->weighted = false;
        this->directed = false;
        this->negative = false;
    }

    Graph::Graph(vector<vector<int>> graph)
    {
        this->size = 0;
        this->Edges = 0;
        this->weighted = false;
        this->directed = false;
        this->negative = false;
        this->loadGraph(std::move(graph));
    }

    void Graph::loadGraph(std::vector<std::vector<int>> graph)
    {
        if (graph.empty())
        {
            throw invalid_argument("The graph is empty.");
        }

        for (size_t i = 0; i < graph.size(); i++)
        {
            if (graph[i].size() != graph.size())
            {
                throw invalid_argument("The graph is not a square matrix.");
            }
        }

        this->Edges = 0;
        // Check if the graph is symmetric.
        for (size_t i = 0; i < graph.size(); i++)
        {
            for (size_t j = 0; j < graph.size(); j++)
            {
                if (graph.at(i).at(j) != graph.at(j).at(i))
                {
                    directed = true;
                }

                if (graph.at(i).at(j) != 0)
                {
                    if (graph.at(i).at(j) != 1)
                    {
                        weighted = true;
                    }

                    if (graph.at(i).at(j) < 0)
                    {
                        negative = true;
                    }

                    this->Edges++;
                }

                // count the number of edges.
            }
        }

        this->size = graph.size();
        this->adjacency_matrix = graph;
    }

    void Graph::printGraph() const
    {
        cout << "Graph with " << this->size << " vertices and " << this->Edges << " edges." << endl;
    }

    vector<int> Graph::getNeighbors(size_t vertex) const
    {
        if (vertex < 0 || vertex >= this->size)
        {
            throw invalid_argument("The vertex is not exist.");
        }

        vector<int> neighbors;
        for (size_t i = 0; i < this->size; i++)
        {
            if (this->adjacency_matrix.at(vertex).at(i) != 0)
            {
                neighbors.push_back(i);
            }
        }

        return neighbors;
    }

    vector<vector<int>> Graph::getAdjacencyMatrix() const
    {
        return this->adjacency_matrix;
    }

    int Graph::getWeight(size_t vertex1, size_t vertex2) const
    {
        if (vertex1 < 0 || vertex1 >= this->size || vertex2 < 0 || vertex2 >= this->size)
        {
            throw invalid_argument("The vertex is not exist.");
        }

        return this->adjacency_matrix.at(vertex1).at(vertex2);
    }

    bool Graph::isDirected() const
    {
        return this->directed;
    }

    bool Graph::isWeighted() const
    {
        return this->weighted;
    }

    bool Graph::isNegative() const
    {
        return this->negative;
    }

    size_t Graph::get_size() const
    {
        return this->size;
    }

    int Graph::getEdges() const
    {
        return this->Edges;
    }

    
} // namespace ariel
