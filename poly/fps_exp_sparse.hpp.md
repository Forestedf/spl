---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: number_theory/factorial.hpp
    title: number_theory/factorial.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: poly/test/exp_of_formal_power_series_sparse.test.cpp
    title: poly/test/exp_of_formal_power_series_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"poly/fps_exp_sparse.hpp\"\n#include <cassert>\n#include\
    \ <utility>\n#include <vector>\n#line 4 \"number_theory/factorial.hpp\"\n\ntemplate\
    \ <typename M>\nM inv(int n) {\n    static std::vector<M> data{M::raw(0), M::raw(1)};\n\
    \    static constexpr unsigned MOD = M::get_mod();\n    assert(0 < n);\n    while\
    \ ((int)data.size() <= n) {\n        unsigned k = (unsigned)data.size();\n   \
    \     unsigned r = MOD / k + 1;\n        data.push_back(M::raw(r) * data[k * r\
    \ - MOD]);\n    }\n    return data[n];\n}\n\ntemplate <typename M>\nM fact(int\
    \ n) {\n    static std::vector<M> data{M::raw(1), M::raw(1)};\n    assert(0 <=\
    \ n);\n    while ((int)data.size() <= n) {\n        unsigned k = (unsigned)data.size();\n\
    \        data.push_back(M::raw(k) * data.back());\n    }\n    return data[n];\n\
    }\n\ntemplate <typename M>\nM inv_fact(int n) {\n    static std::vector<M> data{M::raw(1),\
    \ M::raw(1)};\n    assert(0 <= n);\n    while ((int)data.size() <= n) {\n    \
    \    unsigned k = (unsigned)data.size();\n        data.push_back(inv<M>(k) * data.back());\n\
    \    }\n    return data[n];\n}\n\ntemplate <typename M>\nM binom(int n, int k)\
    \ {\n    assert(0 <= n);\n    if (k < 0 || n < k) {\n        return M::raw(0);\n\
    \    }\n    return fact<M>(n) * inv_fact<M>(k) * inv_fact<M>(n - k);\n}\n\ntemplate\
    \ <typename M>\nM n_terms_sum_k(int n, int k) {\n    assert(0 <= n && 0 <= k);\n\
    \    if (n == 0) {\n        return (k == 0 ? M::raw(1) : M::raw(0));\n    }\n\
    \    return binom<M>(n + k - 1, n - 1);\n}\n#line 6 \"poly/fps_exp_sparse.hpp\"\
    \n// O(n * (# of nonzero))\ntemplate <typename T>\nstd::vector<T> fps_exp_sparse(const\
    \ std::vector<T> &f) {\n    if (f.empty()) {\n        return std::vector<T>(0);\n\
    \    }\n    assert(!f.empty() && f[0] == T(0));\n    int n = (int)f.size();\n\
    \    std::vector<std::pair<int, T>> nonzero;\n    for (int i = 1; i < n; ++i)\
    \ {\n        if (f[i] != T()) {\n            nonzero.emplace_back(i, f[i]);\n\
    \        }\n    }\n    std::vector<T> g(n, T(0));\n    g[0] = T(1);\n    for (int\
    \ i = 1; i < n; ++i) {\n        for (auto [j, val] : nonzero) {\n            if\
    \ (j > i) {\n                break;\n            }\n            g[i] += T(j) *\
    \ val * g[i - j];\n        }\n        g[i] *= inv<T>(i);\n    }\n    return g;\n\
    }\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    #include \"../number_theory/factorial.hpp\"\n// O(n * (# of nonzero))\ntemplate\
    \ <typename T>\nstd::vector<T> fps_exp_sparse(const std::vector<T> &f) {\n   \
    \ if (f.empty()) {\n        return std::vector<T>(0);\n    }\n    assert(!f.empty()\
    \ && f[0] == T(0));\n    int n = (int)f.size();\n    std::vector<std::pair<int,\
    \ T>> nonzero;\n    for (int i = 1; i < n; ++i) {\n        if (f[i] != T()) {\n\
    \            nonzero.emplace_back(i, f[i]);\n        }\n    }\n    std::vector<T>\
    \ g(n, T(0));\n    g[0] = T(1);\n    for (int i = 1; i < n; ++i) {\n        for\
    \ (auto [j, val] : nonzero) {\n            if (j > i) {\n                break;\n\
    \            }\n            g[i] += T(j) * val * g[i - j];\n        }\n      \
    \  g[i] *= inv<T>(i);\n    }\n    return g;\n}\n"
  dependsOn:
  - number_theory/factorial.hpp
  isVerificationFile: false
  path: poly/fps_exp_sparse.hpp
  requiredBy: []
  timestamp: '2024-04-29 14:44:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - poly/test/exp_of_formal_power_series_sparse.test.cpp
documentation_of: poly/fps_exp_sparse.hpp
layout: document
redirect_from:
- /library/poly/fps_exp_sparse.hpp
- /library/poly/fps_exp_sparse.hpp.html
title: poly/fps_exp_sparse.hpp
---
