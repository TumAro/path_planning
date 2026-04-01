#include "pp.h"

std::vector<int> path(int start, int end, const std::unordered_map<int, int>& path_map) {
    int current = end;
    std::vector<int> road;

    while (current != start) {
        road.push_back(current);
        current = path_map.at(current);
    }

    road.push_back(start);
    return road;
}

std::vector<int> BFS(int start, int end, const Graph& graph) {
    std::queue<int> frontier;
    frontier.push(start);

    std::unordered_map<int, int> path_map;
    path_map[start] = -1;

    // std::set<int> reached;
    // reached.insert(start);

    while (!frontier.empty()) {

        int current = frontier.front();

        if (current == end) {
            break;
        }

        std::vector<int> neighbourhood = graph.neighbors(current);
        for (auto next_node : neighbourhood) {
            if (path_map.find(next_node) == path_map.end()) {
                frontier.push(next_node);
                path_map[next_node] = current;
            }
        }
        frontier.pop();
    }
    if (path_map.find(end) == path_map.end()) return {};

    return path(start, end, path_map);
}