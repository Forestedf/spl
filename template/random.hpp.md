---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/wavelet_matrix.test.cpp
    title: data_structure/test/wavelet_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: number_theory/test/frac_binsearch_stress.test.cpp
    title: number_theory/test/frac_binsearch_stress.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/random.hpp\"\n#include <chrono>\n#include <random>\n\
    \n#if defined(LOCAL) || defined(FIX_SEED)\nstd::mt19937_64 mt(123456789);\n#else\n\
    std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    #endif\n\ntemplate <typename T>\nT uniform(T l, T r) {\n    return std::uniform_int_distribution<T>(l,\
    \ r - 1)(mt);\n}\ntemplate <typename T>\nT uniform(T n) {\n    return std::uniform_int_distribution<T>(0,\
    \ n - 1)(mt);\n}\n"
  code: "#pragma once\n#include <chrono>\n#include <random>\n\n#if defined(LOCAL)\
    \ || defined(FIX_SEED)\nstd::mt19937_64 mt(123456789);\n#else\nstd::mt19937_64\
    \ mt(std::chrono::steady_clock::now().time_since_epoch().count());\n#endif\n\n\
    template <typename T>\nT uniform(T l, T r) {\n    return std::uniform_int_distribution<T>(l,\
    \ r - 1)(mt);\n}\ntemplate <typename T>\nT uniform(T n) {\n    return std::uniform_int_distribution<T>(0,\
    \ n - 1)(mt);\n}"
  dependsOn: []
  isVerificationFile: false
  path: template/random.hpp
  requiredBy: []
  timestamp: '2023-12-26 16:56:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - number_theory/test/frac_binsearch_stress.test.cpp
  - data_structure/test/wavelet_matrix.test.cpp
documentation_of: template/random.hpp
layout: document
redirect_from:
- /library/template/random.hpp
- /library/template/random.hpp.html
title: template/random.hpp
---