#pragma once
#include "static_top_tree.hpp"

template <typename TreeDP, typename T = int>
class DynamicRerootingDP {
    using Value = typename TreeDP::Value;
    using Func = typename TreeDP::Func;
    using NT = typename StaticTopTree::NodeType;
    Graph<T> &g;
    TreeDP &dp;
    StaticTopTree stt;
    int root;
    std::vector<Value> value;
    std::vector<Func> up, down;
    
    void init(int x) {
        const StaticTopTree::Node &node = stt.nodes[x];
        if (node.lch != -1) {
            init(node.lch);
        }
        if (node.rch != -1) {
            init(node.rch);
        }
        update_single(x);
    }
    void update_single(int x) {
        const StaticTopTree::Node &node = stt.nodes[x];
        if (node.ty == NT::AddVertex) {
            Value s = (node.lch == -1 ? dp.id() : value[node.lch]);
            if (x != root) {
                auto e = g[x][g[x].size() - 1];
                up[x] = dp.lift(x, e.to, e.id, s);
            }
            if (has_heavy(x)) {
                auto e = g[x][0];
                down[x] = dp.lift(x, e.to, e.id, s);
            }
        } else if (node.ty == NT::Compress) {
            if (node.top != root) {
                up[x] = dp.composite(up[node.lch], up[node.rch]);
            }
            if (has_heavy(node.bottom)) {
                down[x] = dp.composite(down[node.rch], down[node.lch]);
            }
        } else if (node.ty == NT::AddEdge) {
            if (node.top != root) {
                value[x] = dp.apply(up[node.lch], dp.id());
            }
        } else {
            value[x] = dp.op(value[node.lch], value[node.rch]);
        }
    }
    bool has_heavy(int v) const {
        return g[v].size() > int(v != root);
    }
    
    void descend(int x, Value &a, Value &b, Value &side) const {
        int p = stt.nodes[x].par;
        if (p == -1) {
            return;
        }
        descend(p, a, b, side);
        const StaticTopTree::Node &node = stt.nodes[p];
        if (node.ty == NT::Compress) {
            if (node.lch == x) {
                b = dp.apply(up[node.rch], b);
            } else {
                a = dp.apply(down[node.lch], a);
            }
        } else if (node.ty == NT::AddVertex) {
            side = dp.op(a, b);
        } else if (node.ty == NT::Rake) {
            side = dp.op(side, value[node.lch == x ? node.rch : node.lch]);
        } else {
            int v = node.top;
            if (v != root) {
                auto e = g[v][g[v].size() - 1];
                a = dp.apply(dp.lift(e.to, v, e.id, side), dp.id());
                b = dp.id();
            }
        }
    }
    
public:
    DynamicRerootingDP(Graph<T> &g, TreeDP &dp, int root = 0)
        : g(g),
          dp(dp),
          stt(g, root),
          root(root),
          value(stt.nodes.size()),
          up(stt.nodes.size()),
          down(stt.nodes.size()) {
        init(stt.stt_root);
    }
    
    // edge update: call update on both endpoints (in any order)
    void update(int v) {
        for (int x = v; x != -1; x = stt.nodes[x].par) {
            update_single(x);
        }
    }
    Value get(int v) const {
        Value a = dp.id(), b = dp.id(), side = dp.id();
        descend(v, a, b, side);
        Value s = dp.op(a, b);
        const StaticTopTree::Node &node = stt.nodes[v];
        if (node.lch != -1) {
            s = dp.op(value[node.lch], s);
        }
        return dp.vertex(v, s);
    }
};
