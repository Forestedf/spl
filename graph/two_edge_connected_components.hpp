#pragma once
#include "graph.hpp"
template <typename T>
std::vector<int> two_edge_connected_components(const Graph<T> &g) {
    std::vector<int> comp(g.v(), -1);
    int cc = 0;
    std::vector<int> ord(g.v(), -1), low(g.v(), -1), vs;
    int t = 0;
    auto dfs = [&](auto dfs, int v, int p) -> void {
        ord[v] = low[v] = t++;
        vs.push_back(v);
        bool pf = false;
        for (const Edge<T> &e : g[v]) {
            if (ord[e.to] == -1) {
                dfs(dfs, e.to, v);
                if (low[e.to] < low[v]) {
                    low[v] = low[e.to];
                }
            } else if (e.to == p && !pf) {
                pf = true;
            } else {
                if (ord[e.to] < low[v]) {
                    low[v] = ord[e.to];
                }
            }
        }
        if (ord[v] == low[v]) {
            while (comp[v] == -1) {
                comp[vs.back()] = cc;
                vs.pop_back();
            }
            ++cc;
        }
    };
    for (int i = 0; i < g.v(); ++i) {
        if (comp[i] == -1) {
            dfs(dfs, i, -1);
        }
    }
    return comp;
}