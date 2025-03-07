#pragma once
#include "graph.hpp"
#include <algorithm>
#include <numeric>
// g: simple
template <typename T, typename F>
void enumerate_triangles(const Graph<T, false> &g, F f) {
    int n = g.v();
    Graph<int, true> h(n);
    for (int v = 0; v < n; ++v) {
        for (const auto &e : g[v]) {
            if (v < e.to) {
                if (g[v].size() < g[e.to].size()) {
                    h.add_edge(v, e.to);
                } else {
                    h.add_edge(e.to, v);
                }
            }
        }
    }
    h.build();
    std::vector<bool> mem(n, false);
    for (int v = 0; v < n; ++v) {
        for (const auto &e : h[v]) {
            mem[e.to] = true;
        }
        for (const auto &e : h[v]) {
            for (const auto &e2 : h[e.to]) {
                if (mem[e2.to]) {
                    f(v, e.to, e2.to);
                }
            }
        }
        for (const auto &e : h[v]) {
            mem[e.to] = false;
        }
    }
}
