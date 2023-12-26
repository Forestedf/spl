---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/cartesian_tree.test.cpp
    title: data_structure/test/cartesian_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/cartesian_tree.hpp\"\n\n#include <vector>\n\
    \ntemplate <typename T, typename Compare = std::less<T>>\nstd::vector<int> cartesian_tree(const\
    \ std::vector<T> &a, Compare comp = Compare()) {\n    std::vector<int> stc;\n\
    \    std::vector<int> par(a.size(), -1);\n    for (int i = 0; i < a.size(); ++i)\
    \ {\n        while (stc.size() >= 2 && comp(a[i], a[stc.back()])) {\n        \
    \    if (comp(a[i], a[stc[stc.size() - 2]])) {\n                par[stc.back()]\
    \ = stc[stc.size() - 2];\n            } else {\n                par[stc.back()]\
    \ = i;\n            }\n            stc.pop_back();\n        }\n        if (stc.size()\
    \ == 1 && comp(a[i], a[stc.back()])) {\n            par[stc.back()] = i;\n   \
    \         stc.pop_back();\n        }\n        stc.push_back(i);\n    }\n    while\
    \ (stc.size() >= 2) {\n        par[stc.back()] = stc[stc.size() - 2];\n      \
    \  stc.pop_back();\n    }\n    return par;\n}\n"
  code: "#pragma once\n\n#include <vector>\n\ntemplate <typename T, typename Compare\
    \ = std::less<T>>\nstd::vector<int> cartesian_tree(const std::vector<T> &a, Compare\
    \ comp = Compare()) {\n    std::vector<int> stc;\n    std::vector<int> par(a.size(),\
    \ -1);\n    for (int i = 0; i < a.size(); ++i) {\n        while (stc.size() >=\
    \ 2 && comp(a[i], a[stc.back()])) {\n            if (comp(a[i], a[stc[stc.size()\
    \ - 2]])) {\n                par[stc.back()] = stc[stc.size() - 2];\n        \
    \    } else {\n                par[stc.back()] = i;\n            }\n         \
    \   stc.pop_back();\n        }\n        if (stc.size() == 1 && comp(a[i], a[stc.back()]))\
    \ {\n            par[stc.back()] = i;\n            stc.pop_back();\n        }\n\
    \        stc.push_back(i);\n    }\n    while (stc.size() >= 2) {\n        par[stc.back()]\
    \ = stc[stc.size() - 2];\n        stc.pop_back();\n    }\n    return par;\n}"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2023-12-26 16:56:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/cartesian_tree.test.cpp
documentation_of: data_structure/cartesian_tree.hpp
layout: document
redirect_from:
- /library/data_structure/cartesian_tree.hpp
- /library/data_structure/cartesian_tree.hpp.html
title: data_structure/cartesian_tree.hpp
---
