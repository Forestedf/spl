#pragma once
#include "graph.hpp"
template <typename T>
struct BiConnectedComponentInfo {
    std::vector<int> vertices;
    std::vector<Edge<T>> edges;
};
template <typename T>
std::vector<BiConnectedComponentInfo<T>> bi_connected_components(
    const Graph<T> &g) {
    std::vector<int> ord(g.v()), low(g.v()), used(g.v(), 0);
    std::vector<int> vstc;
    std::vector<Edge<T>> estc;
    std::vector<BiConnectedComponentInfo<T>> ret;
    int t = 0;
    auto dfs = [&](auto dfs, int v, int p) -> void {
        used[v] = 1;
        ord[v] = t++;
        low[v] = t;
        vstc.push_back(v);
        bool pf = false;
        int chl = 0;
        for (const auto &e : g[v]) {
            if (used[e.to] && ord[e.to] < ord[v]) {
                estc.push_back(e);
            }
            if (e.to == p && !pf) {
                pf = true;
                continue;
            }
            if (used[e.to]) {
                low[v] = std::min(low[v], ord[e.to]);
            } else {
                int vsz = (int)vstc.size();
                int esz = (int)estc.size();
                ++chl;
                dfs(dfs, e.to, v);
                low[v] = std::min(low[v], low[e.to]);
                if ((p == -1 && chl >= 2) || (p != -1 && low[e.to] >= ord[v])) {
                    BiConnectedComponentInfo<T> bcc;
                    while ((int)vstc.size() > vsz) {
                        bcc.vertices.push_back(vstc.back());
                        vstc.pop_back();
                    }
                    while ((int)estc.size() > esz) {
                        bcc.edges.push_back(estc.back());
                        estc.pop_back();
                    }
                    bcc.vertices.push_back(v);
                    ret.push_back(bcc);
                }
            }
        }
    };
    for (int i = 0; i < g.v(); ++i) {
        if (!used[i]) {
            dfs(dfs, i, -1);
            ret.push_back(BiConnectedComponentInfo<T>{vstc, estc});
            vstc.clear();
            estc.clear();
        }
    }
    return ret;
}