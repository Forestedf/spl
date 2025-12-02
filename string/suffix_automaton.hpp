#pragma once

#include <unordered_map>
#include <utility>
#include <vector>

struct SuffixAutomaton {
    struct Node {
        std::unordered_map<char, int> next;
        int link;
        int len;
    };
    std::vector<Node> nodes;
    int last;

    SuffixAutomaton() : nodes(1, Node{{}, -1, 0}), last(0) {}

    void push(char c) {
        int nn = (int)nodes.size();
        nodes.emplace_back(Node{{}, 0, nodes[last].len + 1});
        int p = std::exchange(last, nn);
        while (p != -1 && !nodes[p].next.count(c)) {
            nodes[p].next[c] = nn;
            p = nodes[p].link;
        }
        if (p == -1) {
            return;
        }
        int q = nodes[p].next[c];
        if (nodes[p].len + 1 == nodes[q].len) {
            nodes[nn].link = q;
        } else {
            int nq = (int)nodes.size();
            nodes.emplace_back(
                Node{nodes[q].next, nodes[q].link, nodes[p].len + 1});
            nodes[q].link = nq;
            nodes[nn].link = nq;
            while (p != -1 && nodes[p].next[c] == q) {
                nodes[p].next[c] = nq;
                p = nodes[p].link;
            }
        }
    }
};
