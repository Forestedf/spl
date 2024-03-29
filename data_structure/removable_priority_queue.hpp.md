---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/removable_priority_queue.hpp\"\n#include\
    \ <cassert>\n#include <queue>\ntemplate <typename T, typename Comp = std::less<T>>\n\
    class RemovablePriorityQueue {\n    std::priority_queue<T, std::vector<T>, Comp>\
    \ pq, rem;\n    void remove_() {\n        while (!pq.empty() && !rem.empty() &&\
    \ pq.top() == rem.top()) {\n            pq.pop();\n            rem.pop();\n  \
    \      }\n    }\npublic:\n    RemovablePriorityQueue(Comp comp = Comp()) : pq(comp),\
    \ rem(comp) {}\n    void push(T x) {\n        pq.push(x);\n    }\n    void remove(T\
    \ x) {\n        rem.push(x);\n    }\n    T pop() {\n        remove_();\n     \
    \   assert(!pq.empty());\n        T ret = pq.top();\n        pq.pop();\n     \
    \   return ret;\n    }\n    T top() {\n        remove_();\n        assert(!pq.empty());\n\
    \        return pq.top();\n    }\n    int size() const {\n        return (int)pq.size()\
    \ - (int)rem.size();\n    }\n    bool empty() const {\n        return size() ==\
    \ 0;\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <queue>\ntemplate <typename T,\
    \ typename Comp = std::less<T>>\nclass RemovablePriorityQueue {\n    std::priority_queue<T,\
    \ std::vector<T>, Comp> pq, rem;\n    void remove_() {\n        while (!pq.empty()\
    \ && !rem.empty() && pq.top() == rem.top()) {\n            pq.pop();\n       \
    \     rem.pop();\n        }\n    }\npublic:\n    RemovablePriorityQueue(Comp comp\
    \ = Comp()) : pq(comp), rem(comp) {}\n    void push(T x) {\n        pq.push(x);\n\
    \    }\n    void remove(T x) {\n        rem.push(x);\n    }\n    T pop() {\n \
    \       remove_();\n        assert(!pq.empty());\n        T ret = pq.top();\n\
    \        pq.pop();\n        return ret;\n    }\n    T top() {\n        remove_();\n\
    \        assert(!pq.empty());\n        return pq.top();\n    }\n    int size()\
    \ const {\n        return (int)pq.size() - (int)rem.size();\n    }\n    bool empty()\
    \ const {\n        return size() == 0;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/removable_priority_queue.hpp
  requiredBy: []
  timestamp: '2024-02-24 22:02:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/removable_priority_queue.hpp
layout: document
redirect_from:
- /library/data_structure/removable_priority_queue.hpp
- /library/data_structure/removable_priority_queue.hpp.html
title: data_structure/removable_priority_queue.hpp
---
