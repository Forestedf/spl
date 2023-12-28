#pragma once
#include "graph.hpp"
template <typename T>
std::vector<int> strongly_connected_components(const Graph<T, true> &g) {
    std::vector<int> comp(g.v(), -1);
    int t = 0, cc = 0;
    std::vector<int> vs, ord(g.v(), -1), low(g.v(), -1);
    auto dfs = [&](auto dfs, int v) -> void {
        vs.push_back(v);
        ord[v] = low[v] = t++;
        for (const Edge<T> &e : g[v]) {
            if (comp[e.to] != -1) {
                continue;
            }
            if (ord[e.to] == -1) {
                dfs(dfs, e.to);
            }
            if (low[e.to] < low[v]) {
                low[v] = low[e.to];
            }
        }
        if (low[v] == ord[v]) {
            while (comp[v] == -1) {
                int u = vs.back();
                vs.pop_back();
                comp[u] = cc;
            }
            ++cc;
        }
    };
    for (int i = 0; i < g.v(); ++i) {
        if (ord[i] == -1) {
            dfs(dfs, i);
        }
    }
    for (int i = 0; i < g.v(); ++i) {
        comp[i] = cc - 1 - comp[i];
    }
    return comp;
}