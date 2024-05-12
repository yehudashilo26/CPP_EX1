#pragma once
#include <set>
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

namespace ariel
{
    class Graph
    {
    private:
        vector<vector<int>> adjacency_matrix;
        size_t size;
        int Edges;     // Number of edges.
        bool weighted; // 0 - unweighted, 1 - weighted.
        bool directed; // 0 - undirected, 1 - directed.
        bool negative; // 0 - non-negative, 1 - negative.

    public:
        Graph();
        Graph(vector<vector<int>> graph);
        void loadGraph(std::vector<std::vector<int>> graph);
        void printGraph() const;
        size_t get_size() const;
        int getEdges() const;
        std::vector<int> getNeighbors(size_t vertex) const;
        std::vector<std::vector<int>> getAdjacencyMatrix() const;
        int getWeight(size_t vertex1, size_t vertex2) const;
        bool isDirected() const;
        bool isWeighted() const;
        bool isNegative() const;

        // util functions for testing
    };
} // namespace ariel