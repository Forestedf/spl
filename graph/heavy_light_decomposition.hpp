#pragma once
#include <algorithm>
#include <utility>
#include "graph.hpp"
class HeavyLightDecomposition {
public:
    std::vector<int> siz, par, hea, in, out, dep, rev;

private:
    template <typename T, bool DIR>
    void dfs1(Graph<T, DIR> &g, int v) {
        if (g[v].size() >= 1 && g[v][0].to == par[v]) {
            std::swap(g[v][0], g[v][g[v].size() - 1]);
        }
        for (Edge<T> &e : g[v]) {
            if (e.to != par[v]) {
                par[e.to] = v;
                dfs1(g, e.to);
                siz[v] += siz[e.to];
                if (siz[e.to] > siz[g[v][0].to]) {
                    std::swap(g[v][0], e);
                }
            }
        }
    }
    template <typename T, bool DIR>
    void dfs2(const Graph<T, DIR> &g, int v, int &t) {
        in[v] = t;
        rev[t++] = v;
        for (const Edge<T> &e : g[v]) {
            if (e.to == par[v]) {
                continue;
            }
            if (e.to == g[v][0].to) {
                hea[e.to] = hea[v];
            } else {
                hea[e.to] = e.to;
            }
            dep[e.to] = dep[v] + 1;
            dfs2(g, e.to, t);
        }
        out[v] = t;
    }

public:
    template <typename T, bool DIR>
    HeavyLightDecomposition(Graph<T, DIR> &g, int root = 0)
        : siz(g.v(), 1),
          par(g.v(), root),
          hea(g.v(), root),
          in(g.v(), 0),
          out(g.v(), 0),
          dep(g.v(), 0),
          rev(g.v(), 0) {
        assert(0 <= root && root < g.v());
        dfs1(g, root);
        int t = 0;
        dfs2(g, root, t);
    }
    // par^k
    int la(int v, int k) const {
        assert(0 <= v && v < (int)dep.size());
        assert(k >= 0);
        if (k > dep[v]) {
            return -1;
        }
        while (true) {
            int u = hea[v];
            if (in[u] + k <= in[v]) {
                return rev[in[v] - k];
            }
            k -= in[v] - in[u] + 1;
            v = par[u];
        }
        return 0;
    }
    int lca(int u, int v) const {
        assert(0 <= u && u < (int)dep.size());
        assert(0 <= v && v < (int)dep.size());
        while (u != v) {
            if (in[u] > in[v]) {
                std::swap(u, v);
            }
            if (hea[u] == hea[v]) {
                v = u;
            } else {
                v = par[hea[v]];
            }
        }
        return u;
    }
    int dist(int u, int v) const {
        assert(0 <= u && u < (int)dep.size());
        assert(0 <= v && v < (int)dep.size());
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    int jump(int u, int v, int k) const {
        assert(0 <= u && u < (int)dep.size());
        assert(0 <= v && v < (int)dep.size());
        assert(k >= 0);
        int l = lca(u, v);
        int dis = dep[u] + dep[v] - 2 * dep[l];
        if (k > dis) {
            return -1;
        }
        if (k <= dep[u] - dep[l]) {
            return la(u, k);
        } else {
            return la(v, dis - k);
        }
    }
    int meet(int u, int v, int w) const {
        return lca(u, v) ^ lca(v, w) ^ lca(w, u);
    }
    std::vector<std::pair<int, int>> path(int u, int v, bool edge) const {
        assert(0 <= u && u < (int)dep.size());
        assert(0 <= v && v < (int)dep.size());
        std::vector<std::pair<int, int>> fromu, fromv;
        bool rev = false;
        while (true) {
            if (u == v && edge) {
                break;
            }
            if (in[u] > in[v]) {
                std::swap(u, v);
                std::swap(fromu, fromv);
                rev ^= true;
            }
            if (hea[u] == hea[v]) {
                fromv.emplace_back(in[v], in[u] + (int)edge);
                v = u;
                break;
            } else {
                fromv.emplace_back(in[v], in[hea[v]]);
                v = par[hea[v]];
            }
        }
        if (rev) {
            std::swap(fromu, fromv);
        }
        std::reverse(fromv.begin(), fromv.end());
        fromu.reserve(fromv.size());
        for (auto [x, y] : fromv) {
            fromu.emplace_back(y, x);
        }
        return fromu;
    }
};
