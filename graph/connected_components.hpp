#pragma once
#include "graph.hpp"
template <typename T>
std::vector<int> connected_components(const Graph<T> &g) {
    std::vector<int> comp(g.v(), -1), stc;
    int c = 0;
    for (int r = 0; r < g.v(); ++r) {
        if (comp[r] == -1) {
            comp[r] = c++;
            stc.push_back(r);
            while (!stc.empty()) {
                int v = stc.back();
                stc.pop_back();
                for (const Edge<T> &e : g[v]) {
                    if (comp[e.to] == -1) {
                        comp[e.to] = comp[v];
                        stc.push_back(e.to);
                    }
                }
            }
        }
    }
    return comp;
}
