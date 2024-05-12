#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}}; // Connected Undirected graph
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    graph = {
        {0, -3, 0},
        {-3, 0, 1},
        {0, 1, 0}}; // Connected Undirected graph with negative weight
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    graph = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 1, 0}}; // Not connected Directed graph
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    graph = {
        {0, 1, 0},
        {-1, 0, 1},
        {0, 1, 0}}; // Connected Directed graph with negative weight
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}}; // Not connected undirected graph
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "-1");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->1->2->0");
}

TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}

TEST_CASE("Whole Graph Test")
{
    ariel::Graph g;
    vector<vector<int>> complete_undirected_graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 0}};

    g.loadGraph(complete_undirected_graph);           // Load the graph to the object.
    CHECK(ariel::Algorithms::isBipartite(g) == "0");  // Should print: "0" (false).
    CHECK(ariel::Algorithms::isConnected(g) == true); // Should print: "1" (true).
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->1->2->0"); // Should print: "The cycle is: 0->1->2->0".
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->3");               // Should print: 0->3.
    CHECK(ariel::Algorithms::negativeCycle(g) == false);                     // Should print: "0" (false).
}

TEST_CASE("Unconnected Directed Graph Test")
{
    ariel::Graph g;
    vector<vector<int>> directed = {
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 0, 0}};

    g.loadGraph(directed);                                        // Load the graph to the object.
    CHECK(ariel::Algorithms::isBipartite(g) == "0");              // Should print: "0" (false).
    CHECK(ariel::Algorithms::isConnected(g) == false);            // Should print: "0" (false).
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->3"); // Should print: 0->1->3.
    CHECK(ariel::Algorithms::shortestPath(g, 2, 3) == "2->1->3"); // Should print: 2->1->3.
}

TEST_CASE("Connected Directed Weighted Graph Tests")
{

    ariel::Graph g;
    vector<vector<int>> dwg = {
        {0, 5, 4, 1, 10},
        {2, 0, 1, 3, 4},
        {0, 0, 0, 3, 3},
        {0, 2, 2, 0, 7},
        {1, 0, 2, 0, 0}};

    g.loadGraph(dwg); // Load the graph to the object.

    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "0->3->2->4");         // Should print: 0->3->2->4. weight of 6
    CHECK(ariel::Algorithms::isConnected(g) == true);                        // Should print: "1" (true).
    CHECK(ariel::Algorithms::isBipartite(g) == "0");                         // Should print: "0" (false).
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->1->0"); // Should print: "-1" (false).
}

TEST_CASE("Graph with no edges")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 1, 2}, B={}");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 2) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 1) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 2, 0) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 2, 1) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 0) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 0) == "0");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 1) == "1");
    CHECK(ariel::Algorithms::shortestPath(g, 2, 2) == "2");
}

TEST_CASE("Directed Graph with Cycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->1->2->3->0");

    vector<vector<int>> graph2 = {
        {0, 1, 3, 0},
        {0, 0, 2, 0},
        {4, 0, 0, 1},
        {0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->2->0");

    vector<vector<int>> graph3 = {
        {0, 1, 3, 0},
        {0, 0, 2, 0},
        {4, 0, 0, 1},
        {0, 0, 0, 1}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 3 -> 3");
}

TEST_CASE("Invalid Input")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));

    vector<vector<int>> graph1 = {
        {0, 1, 2},
        {1, 0, 3, 0},
        {2, 3, 0},
    };

    CHECK_THROWS(g.loadGraph(graph1));

    vector<vector<int>> graph2 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0},
    };

    g.loadGraph(graph2);

    CHECK_THROWS(ariel::Algorithms::shortestPath(g, -1, 2)); // invalid source vertex (negative value)
    CHECK_THROWS(ariel::Algorithms::shortestPath(g, 0, 4));  // invalid destination vertex (out of range)
    CHECK_THROWS(ariel::Algorithms::shortestPath(g, 0, -1)); // invalid destination vertex (negative value)
    CHECK_THROWS(ariel::Algorithms::shortestPath(g, 3, 2));  // invalid source vertex (out of range)
}

TEST_CASE("Negative Weight Graphs")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, -1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->1->0");

    vector<vector<int>> graph2 = {
        {0, -3, 0, -1, 0},
        {0, 0, 5, -2, 4},
        {3, 1, 0, 3, 3},
        {-3, 2, 2, 0, 7},
        {8, 6, -6, -1, 0}};
    
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "Negative cycle detected. There is no shortest path to this vertex.");
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->1->2->0");
    CHECK(ariel::Algorithms::negativeCycle(g) == true);

    vector<vector<int>> graph3 = {
        {0, -1, 0, 0},
        {0, 0, 0, 1},
        {2, 0, 0, 0},
        {1, 0, 0, 0}};

    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->3");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->1->3->0");

    vector<vector<int>> graph4 = { // Directed Graph with no negative cycles
        {0, 5, 0, 0, 0, 0, 0},
        {-3, 0, 2, 0, 0, 0, 0},
        {0, 0, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 5, 0, 0},
        {0, 0, 0, -2, 0, 4, 0},
        {0, 0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0, 0}};

    g.loadGraph(graph4);

}