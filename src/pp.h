#pragma once
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>

const int INF = 1e9;

class Graph {
    std::vector<std::vector<int>> adj_matrix;
    int size;

public:
    Graph(int n) {
        size = n;
        adj_matrix = std::vector<std::vector<int>> (n, std::vector<int>(n, INF));
    }

    void add_edge(int u, int , int w = 1);
    std::vector<int> neighbors(int node) const;
    int cost(int u, int v) const;
    
};

std::vector<int> BFS(int start, int end, const Graph& graph);
std::vector<int> dijkstra(int start, int end, const Graph& graph);