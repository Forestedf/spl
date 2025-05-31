---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/mul_mod_p_conv.hpp
    title: convolution/mul_mod_p_conv.hpp
  - icon: ':heavy_check_mark:'
    path: number_theory/factorize.hpp
    title: number_theory/factorize.hpp
  - icon: ':heavy_check_mark:'
    path: number_theory/primitive_root.hpp
    title: number_theory/primitive_root.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: convolution/test/mul_modp_convolution.test.cpp
    title: convolution/test/mul_modp_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/wavelet_matrix.test.cpp
    title: data_structure/test/wavelet_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: number_theory/test/ax_by_c_stress.test.cpp
    title: number_theory/test/ax_by_c_stress.test.cpp
  - icon: ':heavy_check_mark:'
    path: number_theory/test/binary_gcd_stress.test.cpp
    title: number_theory/test/binary_gcd_stress.test.cpp
  - icon: ':heavy_check_mark:'
    path: number_theory/test/extgcd2_stress.test.cpp
    title: number_theory/test/extgcd2_stress.test.cpp
  - icon: ':heavy_check_mark:'
    path: number_theory/test/factorize.test.cpp
    title: number_theory/test/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: number_theory/test/frac_binsearch_stress.test.cpp
    title: number_theory/test/frac_binsearch_stress.test.cpp
  - icon: ':heavy_check_mark:'
    path: number_theory/test/inv_mod_stress.test.cpp
    title: number_theory/test/inv_mod_stress.test.cpp
  - icon: ':heavy_check_mark:'
    path: number_theory/test/montgomery_64_stress.test.cpp
    title: number_theory/test/montgomery_64_stress.test.cpp
  - icon: ':heavy_check_mark:'
    path: number_theory/test/primitive_root.test.cpp
    title: number_theory/test/primitive_root.test.cpp
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
    \ n - 1)(mt);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: template/random.hpp
  requiredBy:
  - number_theory/factorize.hpp
  - number_theory/primitive_root.hpp
  - convolution/mul_mod_p_conv.hpp
  timestamp: '2024-07-18 16:56:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - number_theory/test/factorize.test.cpp
  - number_theory/test/extgcd2_stress.test.cpp
  - number_theory/test/binary_gcd_stress.test.cpp
  - number_theory/test/frac_binsearch_stress.test.cpp
  - number_theory/test/inv_mod_stress.test.cpp
  - number_theory/test/ax_by_c_stress.test.cpp
  - number_theory/test/montgomery_64_stress.test.cpp
  - number_theory/test/primitive_root.test.cpp
  - convolution/test/mul_modp_convolution.test.cpp
  - data_structure/test/wavelet_matrix.test.cpp
documentation_of: template/random.hpp
layout: document
redirect_from:
- /library/template/random.hpp
- /library/template/random.hpp.html
title: template/random.hpp
---
