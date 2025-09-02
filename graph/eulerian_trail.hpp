#pragma once
#include <algorithm>
#include <utility>
#include "graph.hpp"

template <typename T>
std::pair<std::vector<int>, std::vector<int>> eulerian_trail_directed(
    const Graph<T, true> &g) {
    assert(g.v() >= 1);
    std::vector<int> vs, es;
    std::vector<int> itr(g.v(), 0);
    auto dfs = [&](auto dfs, int v) -> void {
        while (itr[v] < g[v].size()) {
            const Edge<T> &e = g[v][itr[v]++];
            dfs(dfs, e.to);
            vs.push_back(e.to);
            es.push_back(e.id);
        }
    };

    std::vector<int> flux(g.v(), 0);
    for (int i = 0; i < g.v(); ++i) {
        flux[i] += g[i].size();
        for (auto e : g[i]) {
            --flux[e.to];
        }
    }
    int st = -1;
    for (int i = 0; i < g.v(); ++i) {
        if (flux[i] == 1) {
            if (st != -1) {
                // no eulerian trail
                return std::make_pair(vs, es);
            }
            st = i;
        }
        if (flux[i] >= 2) {
            // no eulerian trail
            return std::make_pair(vs, es);
        }
    }
    if (st == -1) {
        for (int i = 0; i < g.v(); ++i) {
            if (g[i].size() > 0) {
                st = i;
            }
        }
    }
    if (st == -1) {
        // no edge
        vs.push_back(0);
        return std::make_pair(vs, es);
    }

    vs.reserve(g.e() + 1);
    es.reserve(g.e());
    dfs(dfs, st);
    if ((int)es.size() != g.e()) {
        return std::make_pair(std::vector<int>(), std::vector<int>());
    }
    vs.push_back(st);
    std::reverse(vs.begin(), vs.end());
    std::reverse(es.begin(), es.end());
    return std::make_pair(vs, es);
}

template <typename T>
std::pair<std::vector<int>, std::vector<int>> eulerian_trail_undirected(
    const Graph<T, false> &g) {
    assert(g.v() >= 1);
    std::vector<int> vs, es;

    int st = -1;
    int cnt = 0;
    for (int i = 0; i < g.v(); ++i) {
        int deg = g[i].size();
        if (deg % 2 == 1) {
            ++cnt;
            st = i;
        }
    }
    if (cnt >= 3) {
        // no eulerian trail
        return std::make_pair(std::vector<int>(), std::vector<int>());
    }
    if (st == -1) {
        for (int i = 0; i < g.v(); ++i) {
            if (g[i].size() > 0) {
                st = i;
            }
        }
    }
    if (st == -1) {
        // no edge
        vs.push_back(0);
        return std::make_pair(vs, es);
    }

    std::vector<int> itr(g.v(), 0), used(g.e(), 0);
    auto dfs = [&](auto dfs, int v) -> void {
        while (itr[v] < g[v].size()) {
            const Edge<T> &e = g[v][itr[v]++];
            if (std::exchange(used[e.id], 1)) {
                continue;
            }
            dfs(dfs, e.to);
            vs.push_back(e.to);
            es.push_back(e.id);
        }
    };

    vs.reserve(g.e() + 1);
    es.reserve(g.e());
    dfs(dfs, st);
    if ((int)es.size() != g.e()) {
        return std::make_pair(std::vector<int>(), std::vector<int>());
    }
    vs.push_back(st);
    std::reverse(vs.begin(), vs.end());
    std::reverse(es.begin(), es.end());
    return std::make_pair(vs, es);
}

// (vs, es)
template <typename T, bool DIR>
std::pair<std::vector<int>, std::vector<int>> eulerian_trail(
    const Graph<T, DIR> &g) {
    if constexpr (DIR) {
        return eulerian_trail_directed(g);
    } else {
        return eulerian_trail_undirected(g);
    }
}
