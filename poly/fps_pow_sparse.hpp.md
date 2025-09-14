---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: number_theory/factorial.hpp
    title: number_theory/factorial.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: poly/test/pow_of_formal_power_series.test.cpp
    title: poly/test/pow_of_formal_power_series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"poly/fps_pow_sparse.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <utility>\n#include <vector>\n#line 4 \"number_theory/factorial.hpp\"\
    \n\ntemplate <typename M>\nM inv(int n) {\n    static std::vector<M> data{M::raw(0),\
    \ M::raw(1)};\n    static constexpr unsigned MOD = M::get_mod();\n    assert(0\
    \ < n);\n    while ((int)data.size() <= n) {\n        unsigned k = (unsigned)data.size();\n\
    \        unsigned r = MOD / k + 1;\n        data.push_back(M::raw(r) * data[k\
    \ * r - MOD]);\n    }\n    return data[n];\n}\n\ntemplate <typename M>\nM fact(int\
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
    \    return binom<M>(n + k - 1, n - 1);\n}\n#line 7 \"poly/fps_pow_sparse.hpp\"\
    \n// O(n * (# of nonzero))\ntemplate <typename T>\nstd::vector<T> fps_pow_sparse_constant_1(const\
    \ std::vector<T> &f, T m) {\n    assert(!f.empty() && f[0] == T(1));\n    int\
    \ n = (int)f.size();\n    std::vector<std::pair<int, T>> nonzero;\n    for (int\
    \ i = 1; i < n; ++i) {\n        if (f[i] != T()) {\n            nonzero.emplace_back(i,\
    \ f[i]);\n        }\n    }\n    std::vector<T> g(f.size(), T(0));\n    g[0] =\
    \ T(1);\n    for (int i = 1; i < n; ++i) {\n        for (auto [j, val] : nonzero)\
    \ {\n            if (j > i) {\n                break;\n            }\n       \
    \     g[i] += ((m + T(1)) * T(j) - T(i)) * val * g[i - j];\n        }\n      \
    \  g[i] *= inv<T>(i);\n    }\n    return g;\n}\ntemplate <typename T>\nstd::vector<T>\
    \ fps_pow_sparse(std::vector<T> f, long long m) {\n    assert(m >= 0);\n    if\
    \ (m == 0) {\n        std::vector<T> g(f.size());\n        if (!g.empty()) {\n\
    \            g[0] = T(1);\n        }\n        return g;\n    }\n    int n = (int)f.size();\n\
    \    int ord = -1;\n    for (int i = 0; i < n; ++i) {\n        if (f[i] != T(0))\
    \ {\n            ord = i;\n            break;\n        }\n    }\n    if (ord ==\
    \ -1 || (m > 0 && (long long)ord > (long long)n / m)) {\n        return std::vector<T>(f.size(),\
    \ T(0));\n    }\n    std::rotate(f.begin(), f.begin() + ord, f.end());\n    T\
    \ first = f[0];\n    T inv_first = T(1) / f[0];\n    for (int i = 0; i < n; ++i)\
    \ {\n        f[i] *= inv_first;\n    }\n    std::vector<T> g = fps_pow_sparse_constant_1(f,\
    \ T(m));\n    int ret_ord = (int)(ord * m);\n    std::rotate(g.begin(), g.begin()\
    \ + (n - ret_ord), g.end());\n    std::fill(g.begin(), g.begin() + ret_ord, T(0));\n\
    \    T pw = first.pow(m);\n    for (int i = ret_ord; i < n; ++i) {\n        g[i]\
    \ *= pw;\n    }\n    return g;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n#include \"../number_theory/factorial.hpp\"\n// O(n * (# of\
    \ nonzero))\ntemplate <typename T>\nstd::vector<T> fps_pow_sparse_constant_1(const\
    \ std::vector<T> &f, T m) {\n    assert(!f.empty() && f[0] == T(1));\n    int\
    \ n = (int)f.size();\n    std::vector<std::pair<int, T>> nonzero;\n    for (int\
    \ i = 1; i < n; ++i) {\n        if (f[i] != T()) {\n            nonzero.emplace_back(i,\
    \ f[i]);\n        }\n    }\n    std::vector<T> g(f.size(), T(0));\n    g[0] =\
    \ T(1);\n    for (int i = 1; i < n; ++i) {\n        for (auto [j, val] : nonzero)\
    \ {\n            if (j > i) {\n                break;\n            }\n       \
    \     g[i] += ((m + T(1)) * T(j) - T(i)) * val * g[i - j];\n        }\n      \
    \  g[i] *= inv<T>(i);\n    }\n    return g;\n}\ntemplate <typename T>\nstd::vector<T>\
    \ fps_pow_sparse(std::vector<T> f, long long m) {\n    assert(m >= 0);\n    if\
    \ (m == 0) {\n        std::vector<T> g(f.size());\n        if (!g.empty()) {\n\
    \            g[0] = T(1);\n        }\n        return g;\n    }\n    int n = (int)f.size();\n\
    \    int ord = -1;\n    for (int i = 0; i < n; ++i) {\n        if (f[i] != T(0))\
    \ {\n            ord = i;\n            break;\n        }\n    }\n    if (ord ==\
    \ -1 || (m > 0 && (long long)ord > (long long)n / m)) {\n        return std::vector<T>(f.size(),\
    \ T(0));\n    }\n    std::rotate(f.begin(), f.begin() + ord, f.end());\n    T\
    \ first = f[0];\n    T inv_first = T(1) / f[0];\n    for (int i = 0; i < n; ++i)\
    \ {\n        f[i] *= inv_first;\n    }\n    std::vector<T> g = fps_pow_sparse_constant_1(f,\
    \ T(m));\n    int ret_ord = (int)(ord * m);\n    std::rotate(g.begin(), g.begin()\
    \ + (n - ret_ord), g.end());\n    std::fill(g.begin(), g.begin() + ret_ord, T(0));\n\
    \    T pw = first.pow(m);\n    for (int i = ret_ord; i < n; ++i) {\n        g[i]\
    \ *= pw;\n    }\n    return g;\n}\n"
  dependsOn:
  - number_theory/factorial.hpp
  isVerificationFile: false
  path: poly/fps_pow_sparse.hpp
  requiredBy: []
  timestamp: '2024-04-29 14:44:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - poly/test/pow_of_formal_power_series.test.cpp
documentation_of: poly/fps_pow_sparse.hpp
layout: document
redirect_from:
- /library/poly/fps_pow_sparse.hpp
- /library/poly/fps_pow_sparse.hpp.html
title: poly/fps_pow_sparse.hpp
---
