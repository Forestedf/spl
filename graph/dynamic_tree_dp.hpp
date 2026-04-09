#pragma once
#include "static_top_tree.hpp"

template <typename TreeDP>
struct DynamicTreeDP {
    using Value = typename TreeDP::Value;
    using Func = typename TreeDP::Func;
    TreeDP &dp;
    StaticTopTree stt;
    std::vector<Value> value;
    std::vector<Func> func;
    template <typename T, bool DIR>
    DynamicTreeDP(Graph<T, DIR> &g, TreeDP &dp, int root = 0) : dp(dp), stt(g, root), value(stt.nodes.size()), func(stt.nodes.size()) {
        init(stt.stt_root);
    }
    Value update(int v) {
        while (v != -1) {
            update_single(v);
            v = stt.nodes[v].par;
        }
        return value[stt.stt_root];
    }
    Value get() const {
        return value[stt.stt_root];
    }

private:
    void init(int v) {
        const StaticTopTree::Node &node = stt.nodes[v];
        if (node.lch != -1) {
            init(node.lch);
        }
        if (node.rch != -1) {
            init(node.rch);
        }
        update_single(v);
    }
    void update_single(int v) {
        const StaticTopTree::Node &node = stt.nodes[v];
        if (node.ty == StaticTopTree::NodeType::AddEdge) {
            value[v] = dp.apply(func[node.lch], dp.id());
        } else if (node.ty == StaticTopTree::NodeType::AddVertex) {
            func[v] = dp.lift(v, node.lch == -1 ? dp.id() : value[node.lch]);
        } else if (node.ty == StaticTopTree::NodeType::Compress) {
            func[v] = dp.composite(func[node.lch], func[node.rch]);
        } else {
            value[v] = dp.op(value[node.lch], value[node.rch]);
        }
    }
};
