#pragma once
#include <algorithm>
#include <cassert>
#include <queue>
#include <utility>
#include <vector>
#include "../template/random.hpp"

std::pair<std::vector<int>, std::vector<int>> bipartite_matching(
    int l, int r, std::vector<std::pair<int, int>> &es) {
    std::shuffle(es.begin(), es.end(), mt);
    std::vector<int> rank(l + 1, 0);
    for (auto [u, v] : es) {
        ++rank[u];
    }
    for (int i = 0; i < l; ++i) {
        rank[i + 1] += rank[i];
    }
    std::vector<int> to(es.size(), 0);
    for (auto [u, v] : es) {
        to[--rank[u]] = v;
    }

    std::vector<int> ml(l, -1), mr(r, -1);
    std::vector<int> que(l);
    std::vector<int> dist(l, -1), vis(l, -1);
    int stamp = 0;

    auto bfs = [&]() -> bool {
        std::fill(dist.begin(), dist.end(), -1);
        bool ret = false;
        int ql = 0, qr = 0;
        for (int i = 0; i < l; ++i) {
            if (ml[i] == -1) {
                que[qr++] = i;
                dist[i] = 0;
            }
        }
        while (ql < qr) {
            int u = que[ql++];
            for (int i = rank[u]; i < rank[u + 1]; ++i) {
                int v = to[i];
                if (mr[v] == -1) {
                    ret = true;
                } else {
                    int w = mr[v];
                    if (dist[w] == -1) {
                        que[qr++] = w;
                        dist[w] = dist[u] + 1;
                    }
                }
            }
        }
        return ret;
    };

    auto dfs = [&](auto dfs, int u) -> bool {
        vis[u] = stamp;
        for (int i = rank[u]; i < rank[u + 1]; ++i) {
            int v = to[i];
            int w = mr[v];
            if (w == -1 ||
                (vis[w] != stamp && dist[w] == dist[u] + 1 && dfs(dfs, w))) {
                ml[u] = v;
                mr[v] = u;
                return true;
            }
        }
        return false;
    };

    for (;; ++stamp) {
        if (!bfs()) {
            break;
        }
        for (int i = 0; i < l; ++i) {
            if (ml[i] == -1) {
                dfs(dfs, i);
            }
        }
    }

    return std::make_pair(ml, mr);
}
