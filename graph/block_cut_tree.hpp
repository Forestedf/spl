#pragma once
#include "graph.hpp"
template <typename T>
Graph<> block_cut_tree(const Graph<T> &g) {
    std::vector<int> ord(g.v()), low(g.v()), used(g.v(), 0);
    std::vector<int> vstc;
    vstc.reserve(g.v());
    Graph<> tree(g.v());
    int t = 0;
    auto dfs = [&](auto dfs, int v, int p) -> void {
        used[v] = 1;
        ord[v] = t++;
        low[v] = t;
        vstc.push_back(v);
        bool pf = false;
        int chl = 0;
        for (const auto &e : g[v]) {
            if (e.to == p && !pf) {
                pf = true;
                continue;
            }
            if (used[e.to]) {
                low[v] = std::min(low[v], ord[e.to]);
            } else {
                int vsz = (int)vstc.size();
                ++chl;
                dfs(dfs, e.to, v);
                low[v] = std::min(low[v], low[e.to]);
                if ((p == -1 && chl >= 2) || (p != -1 && low[e.to] >= ord[v])) {
                    int bcc = tree.add_vertex();
                    while ((int)vstc.size() > vsz) {
                        tree.add_edge(bcc, vstc.back());
                        vstc.pop_back();
                    }
                    tree.add_edge(bcc, v);
                }
            }
        }
    };
    for (int i = 0; i < g.v(); ++i) {
        if (!used[i]) {
            dfs(dfs, i, -1);
            int bcc = tree.add_vertex();
            for (int v : vstc) {
                tree.add_edge(bcc, v);
            }
            vstc.clear();
        }
    }
    tree.build();
    return tree;
}
