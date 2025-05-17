---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/bit_vector.hpp
    title: data_structure/bit_vector.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/wavelet_matrix.hpp
    title: data_structure/wavelet_matrix.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/range_kth_smallest.test.cpp
    title: data_structure/test/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/static_range_frequency.test.cpp
    title: data_structure/test/static_range_frequency.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/wavelet_matrix.test.cpp
    title: data_structure/test/wavelet_matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/bitop.hpp\"\n\ntemplate <typename T, typename U>\n\
    bool ith_bit(T n, U i) {\n    return (n & ((T)1 << i)) != 0;\n}\n\nint popcount(int\
    \ x) { return __builtin_popcount(x); }\nunsigned popcount(unsigned x) { return\
    \ __builtin_popcount(x); }\nlong long popcount(long long x) { return __builtin_popcountll(x);\
    \ }\nunsigned long long popcount(unsigned long long x) {\n    return __builtin_popcountll(x);\n\
    }\n\n// x must not be 0\nint clz(int x) { return __builtin_clz(x); }\nunsigned\
    \ clz(unsigned x) { return __builtin_clz(x); }\nlong long clz(long long x) { return\
    \ __builtin_clzll(x); }\nunsigned long long clz(unsigned long long x) { return\
    \ __builtin_clzll(x); }\n\n// x must not be 0\nint ctz(int x) { return __builtin_ctz(x);\
    \ }\nunsigned ctz(unsigned int x) { return __builtin_ctz(x); }\nlong long ctz(long\
    \ long x) { return __builtin_ctzll(x); }\nunsigned long long ctz(unsigned long\
    \ long x) { return __builtin_ctzll(x); }\n\nint floor_log2(int x) { return 31\
    \ - clz(x); }\nunsigned floor_log2(unsigned x) { return 31 - clz(x); }\nlong long\
    \ floor_log2(long long x) { return 63 - clz(x); }\nunsigned long long floor_log2(unsigned\
    \ long long x) { return 63 - clz(x); }\n\ntemplate <typename T>\nT mask_n(T x,\
    \ T n) {\n    T mask = ((T)1 << n) - 1;\n    return x & mask;\n}\n"
  code: "#pragma once\n\ntemplate <typename T, typename U>\nbool ith_bit(T n, U i)\
    \ {\n    return (n & ((T)1 << i)) != 0;\n}\n\nint popcount(int x) { return __builtin_popcount(x);\
    \ }\nunsigned popcount(unsigned x) { return __builtin_popcount(x); }\nlong long\
    \ popcount(long long x) { return __builtin_popcountll(x); }\nunsigned long long\
    \ popcount(unsigned long long x) {\n    return __builtin_popcountll(x);\n}\n\n\
    // x must not be 0\nint clz(int x) { return __builtin_clz(x); }\nunsigned clz(unsigned\
    \ x) { return __builtin_clz(x); }\nlong long clz(long long x) { return __builtin_clzll(x);\
    \ }\nunsigned long long clz(unsigned long long x) { return __builtin_clzll(x);\
    \ }\n\n// x must not be 0\nint ctz(int x) { return __builtin_ctz(x); }\nunsigned\
    \ ctz(unsigned int x) { return __builtin_ctz(x); }\nlong long ctz(long long x)\
    \ { return __builtin_ctzll(x); }\nunsigned long long ctz(unsigned long long x)\
    \ { return __builtin_ctzll(x); }\n\nint floor_log2(int x) { return 31 - clz(x);\
    \ }\nunsigned floor_log2(unsigned x) { return 31 - clz(x); }\nlong long floor_log2(long\
    \ long x) { return 63 - clz(x); }\nunsigned long long floor_log2(unsigned long\
    \ long x) { return 63 - clz(x); }\n\ntemplate <typename T>\nT mask_n(T x, T n)\
    \ {\n    T mask = ((T)1 << n) - 1;\n    return x & mask;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: template/bitop.hpp
  requiredBy:
  - data_structure/wavelet_matrix.hpp
  - data_structure/bit_vector.hpp
  timestamp: '2024-07-18 16:56:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/static_range_frequency.test.cpp
  - data_structure/test/range_kth_smallest.test.cpp
  - data_structure/test/wavelet_matrix.test.cpp
documentation_of: template/bitop.hpp
layout: document
redirect_from:
- /library/template/bitop.hpp
- /library/template/bitop.hpp.html
title: template/bitop.hpp
---
