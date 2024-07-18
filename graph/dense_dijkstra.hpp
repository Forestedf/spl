#pragma once
#include <limits>
#include <queue>
#include "graph.hpp"
// (dist, from)
template <typename T, bool DIR>
std::pair<std::vector<T>, std::vector<int>> dense_dijkstra(
    const Graph<T, DIR> &g, int s, T inf = std::numeric_limits<T>::max()) {
    assert(0 <= s && s < g.v());
    std::vector<T> dist(g.v(), inf);
    std::vector<int> par(g.v(), -1);
    std::vector<int> used(g.v(), 0);
    dist[s] = 0;
    while (true) {
        T d = inf;
        int v = -1;
        for (int i = 0; i < g.v(); ++i) {
            if (!used[i] && dist[i] < d) {
                d = dist[i];
                v = i;
            }
        } 
        if (v == -1) {
            break;
        }
        used[v] = 1;
        for (const Edge<T> &e : g[v]) {
            if (d + e.weight < dist[e.to]) {
                dist[e.to] = d + e.weight;
                par[e.to] = v;
            }
        }
    }
    return std::make_pair(dist, par);
}
