#pragma once
#include <limits>
#include <queue>
#include "graph.hpp"
// (dist, from)
template <typename T, bool DIR>
std::pair<std::vector<T>, std::vector<int>> dijkstra(
    const Graph<T, DIR> &g, int s, T inf = std::numeric_limits<T>::max()) {
    assert(0 <= s && s < g.v());
    std::vector<T> dist(g.v(), inf);
    std::vector<int> par(g.v(), -1);
    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>,
                        std::greater<>>
        pq;
    dist[s] = 0;
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (d > dist[v]) {
            continue;
        }
        for (const Edge<T> &e : g[v]) {
            if (d + e.weight < dist[e.to]) {
                dist[e.to] = d + e.weight;
                par[e.to] = v;
                pq.emplace(dist[e.to], e.to);
            }
        }
    }
    return std::make_pair(dist, par);
}