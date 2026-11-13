#pragma once
#include "spl/graph/graph.hpp"

// rake :: Data -> Data -> Data
// add_vertex :: Data -> int(root) -> Data
// add_edge :: Data -> int(root) -> int(new root) -> int(edge index) -> Data
template <typename Data>
class RerootingDP {
    std::vector<Data> dp;
    std::vector<Data> edp;
    std::vector<int> vs, rank;
    
public:
    template <typename T, typename F1, typename F2, typename F3>
    RerootingDP(const Graph<T, false> &g, const F1 &rake, const F2 &add_vertex, const F3 &add_edge, const Data &id) {
        assert(g.v() >= 1);
        std::vector<int> par(g.v(), -1), stc;
        vs.reserve(g.v());
        stc.push_back(0);
        while (!stc.empty()) {
            int v = stc.back();
            stc.pop_back();
            vs.push_back(v);
            for (Edge<T> e : g[v]) {
                if (e.to != par[v]) {
                    par[e.to] = v;
                    stc.push_back(e.to);
                }
            }
        }
        
        rank.resize(g.v() + 1, 0);
        for (int i = 0; i < g.v(); ++i) {
            rank[i + 1] = rank[i] + g[i].size();
        }
        
        dp.resize(g.v(), id);
        edp.resize(rank.back(), id);
        
        // DP (1st)
        for (int i = g.v() - 1; i >= 0; --i) {
            int v = vs[i];
            for (int j = 0; j < g[v].size(); ++j) {
                Edge<T> e = g[v][j];
                if (e.to == par[v]) {
                    continue;
                }
                edp[rank[v] + j] = add_edge(add_vertex(dp[e.to], e.to), e.to, v, e.id);
                dp[v] = rake(dp[v], edp[rank[v] + j]);
            }
        }
        
        // DP (2nd)
        std::vector<Data> trans(g.v(), id);
        std::vector<Data> forw(g.v(), id), bacw(g.v(), id);
        for (int i = 0; i < g.v(); ++i) {
            int v = vs[i];
            dp[v] = add_vertex(rake(dp[v], trans[v]), v);
            int k = g[v].size();
            for (int j = 0; j < k; ++j) {
                if (g[v][j].to == par[v]) {
                    edp[rank[v] + j] = trans[v];
                }
                forw[j + 1] = rake(forw[j], edp[rank[v] + j]);
            }
            bacw[k] = id;
            for (int j = k - 1; j >= 0; --j) {
                bacw[j] = rake(bacw[j + 1], edp[rank[v] + j]);
            }
            for (int j = 0; j < k; ++j) {
                if (int to = g[v][j].to; to != par[v]) {
                    int id = g[v][j].id;
                    trans[to] = add_edge(add_vertex(rake(forw[j], bacw[j + 1]), v), v, to, id);
                }
            }
        }
    }
    
    const Data &operator[](int v) const {
        return dp[v];
    }
};
