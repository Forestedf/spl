#pragma once
#include <algorithm>
#include <cassert>
#include <queue>
#include <utility>
#include <vector>
#include "../template/random.hpp"

// heuristic version
// if not shuffle, then hackable
std::pair<std::vector<int>, std::vector<int>> bipartite_matching(int l, int r, std::vector<std::pair<int, int>> edges) {
    std::shuffle(edges.begin(), edges.end(), mt);
    assert(0 <= l && 0 <= r);
    std::vector<std::vector<int>> g(l);
    for (auto [u, v] : edges) {
        g[u].push_back(v);
    }
    std::vector<int> p(l, -1), q(r, -1);
    while (true) {
        std::vector<int> par(l, -1), root(l, -1);
        std::queue<int> que;
        for (int i = 0; i < l; ++i) {
            if (p[i] == -1) {
                que.push(i);
                root[i] = i;
            }
        }
        bool upd = false;
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            if (p[root[v]] != -1) {
                continue;
            }
            for (int u : g[v]) {
                if (q[u] == -1) {
                    while (u != -1) {
                        q[u] = v;
                        std::swap(p[v], u);
                        v = par[v];
                    }
                    upd = true;
                    break;
                }
                int u_ = q[u];
                if (par[u_] == -1) {
                    root[u_] = root[v];
                    par[u_] = v;
                    que.push(u_);
                }
            }
        }
        if (!upd) {
            break;
        }
    }
    return std::make_pair(p, q);
}
