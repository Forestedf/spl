---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: poly/fps_exp.hpp
    title: poly/fps_exp.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_exp_sparse.hpp
    title: poly/fps_exp_sparse.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_log.hpp
    title: poly/fps_log.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_log_sparse.hpp
    title: poly/fps_log_sparse.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_pow_sparse.hpp
    title: poly/fps_pow_sparse.hpp
  - icon: ':heavy_check_mark:'
    path: poly/stirling1.hpp
    title: poly/stirling1.hpp
  - icon: ':heavy_check_mark:'
    path: poly/stirling2.hpp
    title: poly/stirling2.hpp
  - icon: ':heavy_check_mark:'
    path: poly/taylor_shift.hpp
    title: poly/taylor_shift.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: poly/test/exp_of_formal_power_series.test.cpp
    title: poly/test/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: poly/test/exp_of_formal_power_series_sparse.test.cpp
    title: poly/test/exp_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: poly/test/log_of_formal_power_series.test.cpp
    title: poly/test/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: poly/test/log_of_formal_power_series_sparse.test.cpp
    title: poly/test/log_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: poly/test/polynomial_taylor_shift.test.cpp
    title: poly/test/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: poly/test/pow_of_formal_power_series.test.cpp
    title: poly/test/pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: poly/test/stirling_number_of_the_first_kind.test.cpp
    title: poly/test/stirling_number_of_the_first_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: poly/test/stirling_number_of_the_second_kind.test.cpp
    title: poly/test/stirling_number_of_the_second_kind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"number_theory/factorial.hpp\"\n#include <cassert>\n#include\
    \ <vector>\n\ntemplate <typename M>\nM inv(int n) {\n    static std::vector<M>\
    \ data{M::raw(0), M::raw(1)};\n    static constexpr unsigned MOD = M::get_mod();\n\
    \    assert(0 < n);\n    while ((int)data.size() <= n) {\n        unsigned k =\
    \ (unsigned)data.size();\n        unsigned r = MOD / k + 1;\n        data.push_back(M::raw(r)\
    \ * data[k * r - MOD]);\n    }\n    return data[n];\n}\n\ntemplate <typename M>\n\
    M fact(int n) {\n    static std::vector<M> data{M::raw(1), M::raw(1)};\n    assert(0\
    \ <= n);\n    while ((int)data.size() <= n) {\n        unsigned k = (unsigned)data.size();\n\
    \        data.push_back(M::raw(k) * data.back());\n    }\n    return data[n];\n\
    }\n\ntemplate <typename M>\nM inv_fact(int n) {\n    static std::vector<M> data{M::raw(1),\
    \ M::raw(1)};\n    assert(0 <= n);\n    while ((int)data.size() <= n) {\n    \
    \    unsigned k = (unsigned)data.size();\n        data.push_back(inv<M>(k) * data.back());\n\
    \    }\n    return data[n];\n}\n\ntemplate <typename M>\nM binom(int n, int k)\
    \ {\n    assert(0 <= n);\n    if (k < 0 || n < k) {\n        return M::raw(0);\n\
    \    }\n    return fact<M>(n) * inv_fact<M>(k) * inv_fact<M>(n - k);\n}\n\ntemplate\
    \ <typename M>\nM n_terms_sum_k(int n, int k) {\n    assert(0 <= n && 0 <= k);\n\
    \    if (n == 0) {\n        return (k == 0 ? M::raw(1) : M::raw(0));\n    }\n\
    \    return binom<M>(n + k - 1, n - 1);\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ M>\nM inv(int n) {\n    static std::vector<M> data{M::raw(0), M::raw(1)};\n\
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
    \    return binom<M>(n + k - 1, n - 1);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/factorial.hpp
  requiredBy:
  - poly/fps_log_sparse.hpp
  - poly/fps_log.hpp
  - poly/taylor_shift.hpp
  - poly/fps_pow_sparse.hpp
  - poly/fps_exp.hpp
  - poly/stirling1.hpp
  - poly/stirling2.hpp
  - poly/fps_exp_sparse.hpp
  timestamp: '2024-03-29 17:56:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - poly/test/stirling_number_of_the_second_kind.test.cpp
  - poly/test/stirling_number_of_the_first_kind.test.cpp
  - poly/test/exp_of_formal_power_series_sparse.test.cpp
  - poly/test/log_of_formal_power_series.test.cpp
  - poly/test/exp_of_formal_power_series.test.cpp
  - poly/test/log_of_formal_power_series_sparse.test.cpp
  - poly/test/polynomial_taylor_shift.test.cpp
  - poly/test/pow_of_formal_power_series.test.cpp
documentation_of: number_theory/factorial.hpp
layout: document
redirect_from:
- /library/number_theory/factorial.hpp
- /library/number_theory/factorial.hpp.html
title: number_theory/factorial.hpp
---
