#include "pp.h"

void Graph::add_edge(int u, int v) {
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1;
}

std::vector<int> Graph::neighbors(int node) const {
    std::vector<int> nbd = {};
    for (int i = 0; i < size; i++) {
        if (adj_matrix[node][i] == 1) {
            nbd.push_back(i);
        }
    }
    return nbd;
}