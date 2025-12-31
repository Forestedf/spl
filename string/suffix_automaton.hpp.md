---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: string/test/number_of_substrings.test.cpp
    title: string/test/number_of_substrings.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/suffix_automaton.hpp\"\n\n#include <unordered_map>\n\
    #include <utility>\n#include <vector>\n\nstruct SuffixAutomaton {\n    struct\
    \ Node {\n        std::unordered_map<char, int> next;\n        int link;\n   \
    \     int len;\n    };\n    std::vector<Node> nodes;\n    int last;\n\n    SuffixAutomaton()\
    \ : nodes(1, Node{{}, -1, 0}), last(0) {}\n\n    void push(char c) {\n       \
    \ int nn = (int)nodes.size();\n        nodes.emplace_back(Node{{}, 0, nodes[last].len\
    \ + 1});\n        int p = std::exchange(last, nn);\n        while (p != -1 &&\
    \ !nodes[p].next.count(c)) {\n            nodes[p].next[c] = nn;\n           \
    \ p = nodes[p].link;\n        }\n        if (p == -1) {\n            return;\n\
    \        }\n        int q = nodes[p].next[c];\n        if (nodes[p].len + 1 ==\
    \ nodes[q].len) {\n            nodes[nn].link = q;\n        } else {\n       \
    \     int nq = (int)nodes.size();\n            nodes.emplace_back(\n         \
    \       Node{nodes[q].next, nodes[q].link, nodes[p].len + 1});\n            nodes[q].link\
    \ = nq;\n            nodes[nn].link = nq;\n            while (p != -1 && nodes[p].next[c]\
    \ == q) {\n                nodes[p].next[c] = nq;\n                p = nodes[p].link;\n\
    \            }\n        }\n    }\n};\n"
  code: "#pragma once\n\n#include <unordered_map>\n#include <utility>\n#include <vector>\n\
    \nstruct SuffixAutomaton {\n    struct Node {\n        std::unordered_map<char,\
    \ int> next;\n        int link;\n        int len;\n    };\n    std::vector<Node>\
    \ nodes;\n    int last;\n\n    SuffixAutomaton() : nodes(1, Node{{}, -1, 0}),\
    \ last(0) {}\n\n    void push(char c) {\n        int nn = (int)nodes.size();\n\
    \        nodes.emplace_back(Node{{}, 0, nodes[last].len + 1});\n        int p\
    \ = std::exchange(last, nn);\n        while (p != -1 && !nodes[p].next.count(c))\
    \ {\n            nodes[p].next[c] = nn;\n            p = nodes[p].link;\n    \
    \    }\n        if (p == -1) {\n            return;\n        }\n        int q\
    \ = nodes[p].next[c];\n        if (nodes[p].len + 1 == nodes[q].len) {\n     \
    \       nodes[nn].link = q;\n        } else {\n            int nq = (int)nodes.size();\n\
    \            nodes.emplace_back(\n                Node{nodes[q].next, nodes[q].link,\
    \ nodes[p].len + 1});\n            nodes[q].link = nq;\n            nodes[nn].link\
    \ = nq;\n            while (p != -1 && nodes[p].next[c] == q) {\n            \
    \    nodes[p].next[c] = nq;\n                p = nodes[p].link;\n            }\n\
    \        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/suffix_automaton.hpp
  requiredBy: []
  timestamp: '2025-12-02 11:14:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - string/test/number_of_substrings.test.cpp
documentation_of: string/suffix_automaton.hpp
layout: document
redirect_from:
- /library/string/suffix_automaton.hpp
- /library/string/suffix_automaton.hpp.html
title: string/suffix_automaton.hpp
---
