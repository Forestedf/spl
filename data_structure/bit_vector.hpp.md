---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  _extendedRequiredBy:
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
  bundledCode: "#line 2 \"data_structure/bit_vector.hpp\"\n#include <vector>\n#line\
    \ 2 \"template/bitop.hpp\"\n\ntemplate <typename T, typename U>\nbool ith_bit(T\
    \ n, U i) {\n    return (n & ((T)1 << i)) != 0;\n}\n\nint popcount(int x) { return\
    \ __builtin_popcount(x); }\nunsigned popcount(unsigned x) { return __builtin_popcount(x);\
    \ }\nlong long popcount(long long x) { return __builtin_popcountll(x); }\nunsigned\
    \ long long popcount(unsigned long long x) {\n    return __builtin_popcountll(x);\n\
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
    \ T n) {\n    T mask = ((T)1 << n) - 1;\n    return x & mask;\n}\n#line 4 \"data_structure/bit_vector.hpp\"\
    \n\nclass BitVector {\n    static constexpr int WIDTH = 64;\n\n    int n;\n  \
    \  std::vector<unsigned long long> bits;\n    std::vector<unsigned long long>\
    \ sum;\n    int zeros;\n\npublic:\n    BitVector(int _n)\n        : n(_n), bits(n\
    \ / WIDTH + 1, 0), sum(n / WIDTH + 1, 0), zeros(0) {}\n\n    void rev(int idx)\
    \ { bits[idx / WIDTH] ^= 1ULL << (idx % WIDTH); }\n\n    bool operator[](int idx)\
    \ const {\n        return (bits[idx / WIDTH] & (1ULL << (idx % WIDTH))) != 0;\n\
    \    }\n\n    void build() {\n        for (int i = 1; i < (int)sum.size(); ++i)\
    \ {\n            sum[i] = sum[i - 1] + popcount(bits[i - 1]);\n        }\n   \
    \     zeros = rank0(n);\n    }\n\n    int rank0(int n) const { return n - rank1(n);\
    \ }\n    int rank1(int n) const {\n        return sum[n / WIDTH] +\n         \
    \      popcount(\n                   mask_n(bits[n / WIDTH], (unsigned long long)(n\
    \ % WIDTH)));\n    }\n    int all_zeros() const { return zeros; }\n};\n"
  code: "#pragma once\n#include <vector>\n#include \"../template/bitop.hpp\"\n\nclass\
    \ BitVector {\n    static constexpr int WIDTH = 64;\n\n    int n;\n    std::vector<unsigned\
    \ long long> bits;\n    std::vector<unsigned long long> sum;\n    int zeros;\n\
    \npublic:\n    BitVector(int _n)\n        : n(_n), bits(n / WIDTH + 1, 0), sum(n\
    \ / WIDTH + 1, 0), zeros(0) {}\n\n    void rev(int idx) { bits[idx / WIDTH] ^=\
    \ 1ULL << (idx % WIDTH); }\n\n    bool operator[](int idx) const {\n        return\
    \ (bits[idx / WIDTH] & (1ULL << (idx % WIDTH))) != 0;\n    }\n\n    void build()\
    \ {\n        for (int i = 1; i < (int)sum.size(); ++i) {\n            sum[i] =\
    \ sum[i - 1] + popcount(bits[i - 1]);\n        }\n        zeros = rank0(n);\n\
    \    }\n\n    int rank0(int n) const { return n - rank1(n); }\n    int rank1(int\
    \ n) const {\n        return sum[n / WIDTH] +\n               popcount(\n    \
    \               mask_n(bits[n / WIDTH], (unsigned long long)(n % WIDTH)));\n \
    \   }\n    int all_zeros() const { return zeros; }\n};"
  dependsOn:
  - template/bitop.hpp
  isVerificationFile: false
  path: data_structure/bit_vector.hpp
  requiredBy:
  - data_structure/wavelet_matrix.hpp
  timestamp: '2024-07-18 16:56:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/range_kth_smallest.test.cpp
  - data_structure/test/wavelet_matrix.test.cpp
  - data_structure/test/static_range_frequency.test.cpp
documentation_of: data_structure/bit_vector.hpp
layout: document
redirect_from:
- /library/data_structure/bit_vector.hpp
- /library/data_structure/bit_vector.hpp.html
title: data_structure/bit_vector.hpp
---
