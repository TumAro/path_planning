#pragma once
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>

class Graph {
    std::vector<std::vector<int>> adj_matrix;
    int size;

public:
    Graph(int n) {
        size = n;
        adj_matrix = std::vector<std::vector<int>> (n, std::vector<int>(n,0));
    }

    void add_edge(int u, int v);
    std::vector<int> neighbors(int node) const;
    
};

std::vector<int> BFS(int start, int end, const Graph& graph);