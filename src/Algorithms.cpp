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

std::vector<int> BFS(int start, int end, const Graph& graph, bool early_exit) {
    std::queue<int> frontier;
    frontier.push(start);

    std::unordered_map<int, int> path_map;
    path_map[start] = -1;

    // std::set<int> reached;
    // reached.insert(start);

    while (!frontier.empty()) {

        int current = frontier.front();

        if (current == end && early_exit) {
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

std::vector<int> dijkstra(int start, int end, const Graph& graph) {
    std::priority_queue<
        std::pair<int, int>,                    // pair (cost, node)
        std::vector<std::pair<int, int>>,       // underlying storage
        std::greater<>                          // for min heap -> front is lowest
    > frontier;

    frontier.push({start, 0});

    std::unordered_map<int, int> path_map;
    std::unordered_map<int, int> cost_so_far;
    path_map[start] = -1;
    cost_so_far[start] = 0;

    // std::set<int> reached;
    // reached.insert(start);

    while (!frontier.empty()) {
        auto [cost, current_node] = frontier.top(); // highest priority element

        if (current_node == end) break;

        std::vector<int> neighbourhood = graph.neighbors(current_node);

        for (auto next_node : neighbourhood) {
            int new_cost = cost_so_far[current_node] + graph.cost(current_node, next_node);

            if (cost_so_far.find(next_node) == cost_so_far.end() || new_cost < cost_so_far[next_node]) {
                cost_so_far[next_node] = new_cost;
                int priority = new_cost;
                frontier.push({priority, next_node});
                path_map[next_node] = current_node;
            }
        }
        frontier.pop();
    }
    if (path_map.find(end) == path_map.end()) return {};

    return path(start, end, path_map);
}