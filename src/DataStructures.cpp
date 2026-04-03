#include "pp.h"

void Graph::add_edge(int u, int v, int w) {
    if (u == v) {adj_matrix[u][v] = 0;}
    adj_matrix[u][v] = w;
    adj_matrix[v][u] = w;
}

int Graph::cost(int u, int v) const {
    return adj_matrix[u][v];
}

std::vector<int> Graph::neighbors(int node) const {
    std::vector<int> nbd = {};
    for (int i = 0; i < size; i++) {
        if (adj_matrix[node][i] != INF) {
            nbd.push_back(i);
        }
    }
    return nbd;
}

// different inadmessible heuristics
float manhattan(auto a, auto b) {
    return std::abs(a[0] - b[0]) + std::abs(a[1] - b[1]);
}

float euclidean2D(auto a, auto b) {
    return std::sqrt( std::pow((a[0] - b[0]), 2) + std::pow((a[1] - b[1]), 2) );
}