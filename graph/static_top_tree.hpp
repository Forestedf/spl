#pragma once
#include <algorithm>
#include <queue>
#include "graph.hpp"

class StaticTopTree {
public:
    enum class NodeType {
        AddEdge,
        AddVertex,
        Compress,
        Rake
    };
    struct Node {
        NodeType ty;
        int par, lch, rch;
    };

    std::vector<Node> nodes;
    int stt_root;

    template <typename T, bool DIR>
    StaticTopTree(Graph<T, DIR> &g, int root = 0) {
        assert(0 <= root && root < g.v());
        nodes.reserve(3 * g.v());
        dfs(g, root, -1);
        nodes.resize(g.v(), Node{NodeType::AddVertex, -1, -1, -1});
        stt_root = compress(g, root, -1).second;
    }

private:
    template <typename T, bool DIR>
    int dfs(Graph<T, DIR> &g, int v, int p) {
        int sz = 1, mx = 0;
        for (Edge<T> &e : g[v]) {
            if (e.to == p) {
                continue;
            }
            int t = dfs(g, e.to, v);
            if (mx < t) {
                mx = t;
                swap(g[v][0], e);
            }
            sz += t;
        }
        return sz;
    }
    int make_node(NodeType ty, int lch, int rch) {
        int v = (int)nodes.size();
        nodes.emplace_back(Node{ty, -1, lch, rch});
        if (lch != -1) {
            nodes[lch].par = v;
        }
        if (rch != -1) {
            nodes[rch].par = v;
        }
        return v;
    }
    void merge(std::vector<std::pair<int, int>> &path) {
        auto [xf, xs] = path.back();
        path.pop_back();
        auto [yf, ys] = path.back();
        path.pop_back();
        path.emplace_back(std::max(xf, yf) + 1, make_node(NodeType::Compress, ys, xs));
    }
    template <typename T, bool DIR>
    std::pair<int, int> compress(const Graph<T, DIR> &g, int v, int p) {
        std::vector<std::pair<int, int>> path;
        while (true) {
            path.emplace_back(rake(g, v, p));
            while (true) {
                int l = (int)path.size();
                if (l >= 3 && (path[l - 3].first == path[l - 2].first || path[l - 3].first <= path[l - 1].first)) {
                    std::pair<int, int> t = path.back();
                    path.pop_back();
                    merge(path);
                    path.emplace_back(t);
                } else if (l >= 2 && path[l - 2].first <= path[l - 1].first) {
                    merge(path);
                } else {
                    break;
                }
            }
            if (g[v].size() == 0 || g[v][0].to == p) {
                break;
            }
            p = v;
            v = g[v][0].to;
        }
        while (path.size() >= 2) {
            merge(path);
        }
        auto [xf, xs] = path.back();
        int z = make_node(NodeType::AddEdge, xs, -1);
        return std::pair<int, int>(xf + 1, z);
    }
    template <typename T, bool DIR>
    std::pair<int, int> rake(const Graph<T, DIR> &g, int v, int p) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        for (int i = 1; i < (int)g[v].size(); ++i) {
            const Edge<T> &e = g[v][i];
            if (e.to == p) {
                continue;
            }
            pq.emplace(compress(g, e.to, v));
        }
        if (pq.empty()) {
            return std::pair<int, int>(0, v);
        }
        while (pq.size() >= 2) {
            auto [xf, xs] = pq.top();
            pq.pop();
            auto [yf, ys] = pq.top();
            pq.pop();
            pq.emplace(std::max(xf, yf) + 1, make_node(NodeType::Rake, xs, ys));
        }
        auto [rf, rs] = pq.top();
        nodes[v].lch = rs;
        nodes[rs].par = v;
        return std::pair<int, int>(rf + 1, v);
    }
};
