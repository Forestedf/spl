#pragma once
#include "graph.hpp"
template <typename T>
std::vector<int> complement_graph_connected_components(const Graph<T> &g) {
    std::vector<int> comp(g.v(), -1), tmp(g.v(), 0), rem(g.v()), stc, nrem;
    for (int i = 0; i < g.v(); ++i) {
        rem[i] = i;
    }
    int c = 0;
    while (!rem.empty()) {
        int r = rem.back();
        rem.pop_back();
        comp[r] = c;
        stc.push_back(r);
        while (!stc.empty()) {
            int v = stc.back();
            stc.pop_back();
            for (const Edge<T> &e : g[v]) {
                tmp[e.to] = 1;
            }
            for (int u : rem) {
                if (tmp[u]) {
                    nrem.push_back(u);
                } else if (comp[u] == -1) {
                    comp[u] = c;
                    stc.push_back(u);
                }
            }
            for (const Edge<T> &e : g[v]) {
                tmp[e.to] = 0;
            }
            std::swap(rem, nrem);
            nrem.clear();
        }
        ++c;
    }
    return comp;
}