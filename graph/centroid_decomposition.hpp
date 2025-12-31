#pragma once
#include "graph.hpp"
class CentroidDecomposition {
    Graph<int, true> to;
    std::vector<bool> used;
    std::vector<int> size;
    int first;
    
    template <typename T>
    void dfs(const Graph<T> &g, int v, int p) {
        size[v] = 1;
        for (const Edge<T> &e : g[v]) {
            if (e.to != p && !used[e.to]) {
                dfs(g, e.to, v);
                size[v] += size[e.to];
            }
        }
    }
    
    template <typename T>
    int find_centroid(const Graph<T> &g, int v) {
        dfs(g, v, -1);
        int sz = size[v];
        int p = -1;
        while (true) {
            bool ok = true;
            for (const Edge<T> &e : g[v]) {
                if (e.to == p || used[e.to]) {
                    continue;
                }
                if (size[e.to] > sz / 2) {
                    p = v;
                    v = e.to;
                    ok = false;
                    break;
                }
            }
            if (ok) {
                break;
            }
        }
        return v;
    }
    
    template <typename T>
    int decompose(const Graph<T> &g, int v) {
        int cent = find_centroid(g, v);
        used[cent] = true;
        for (const Edge<T> &e : g[cent]) {
            if (!used[e.to]) {
                to.add_edge(cent, decompose(g, e.to));
            }
        }
        return cent;
    }
    
public:
    template <typename T>
    CentroidDecomposition(const Graph<T> &g) : to(g.v()), used(g.v(), false), size(g.v(), 0) {
        first = decompose(g, 0);
        to.build();
    }
    
    int first_centroid() const {
        return first;
    }
    typename Graph<int, true>::ConstAdjacency operator[](int v) const {
        return to[v];
    }
    const Graph<int, true> &get_tree() const {
        return to;
    }
};
