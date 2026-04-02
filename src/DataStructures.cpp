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