---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/range_kth_smallest.test.cpp
    title: data_structure/test/range_kth_smallest.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/coordinate_compression.hpp\"\n\n#include <algorithm>\n\
    #include <vector>\n\ntemplate <typename T>\nclass CoordinateCompression {\n  \
    \  std::vector<T> data;\n\n    int size_sum() { return 0; }\n\n    template <typename...\
    \ Tail>\n    int size_sum(const std::vector<T> &head, const Tail &...tail) {\n\
    \        return (int)head.size() + size_sum(tail...);\n    }\n\n    void push()\
    \ {}\n\n    template <typename... Tail>\n    void push(const std::vector<T> &head,\
    \ const Tail &...tail) {\n        for (const T &ele : head) {\n            data.emplace_back(ele);\n\
    \        }\n        push(tail...);\n    }\n\n    void compress() {}\n\n    template\
    \ <typename... Tail>\n    void compress(std::vector<T> &head, Tail &...tail) {\n\
    \        for (T &ele : head) {\n            ele = (T)(std::lower_bound(data.begin(),\
    \ data.end(), ele) -\n                      data.begin());\n        }\n      \
    \  compress(tail...);\n    }\n\npublic:\n    template <typename... V>\n    CoordinateCompression(V\
    \ &...v) {\n        data.reserve(size_sum(v...));\n        push(v...);\n     \
    \   std::sort(data.begin(), data.end());\n        data.erase(std::unique(data.begin(),\
    \ data.end()), data.end());\n        compress(v...);\n    }\n\n    const T &operator[](const\
    \ T &ele) const { return data[ele]; }\n\n    int size() const { return data.size();\
    \ }\n\n    bool contains(const T &ele) const {\n        auto it = std::lower_bound(data.begin(),\
    \ data.end(), ele);\n        return it != data.end() && *it == ele;\n    }\n\n\
    \    T cc(const T &ele) const {\n        return (T)(std::lower_bound(data.begin(),\
    \ data.end(), ele) -\n                   data.begin());\n    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\ntemplate <typename\
    \ T>\nclass CoordinateCompression {\n    std::vector<T> data;\n\n    int size_sum()\
    \ { return 0; }\n\n    template <typename... Tail>\n    int size_sum(const std::vector<T>\
    \ &head, const Tail &...tail) {\n        return (int)head.size() + size_sum(tail...);\n\
    \    }\n\n    void push() {}\n\n    template <typename... Tail>\n    void push(const\
    \ std::vector<T> &head, const Tail &...tail) {\n        for (const T &ele : head)\
    \ {\n            data.emplace_back(ele);\n        }\n        push(tail...);\n\
    \    }\n\n    void compress() {}\n\n    template <typename... Tail>\n    void\
    \ compress(std::vector<T> &head, Tail &...tail) {\n        for (T &ele : head)\
    \ {\n            ele = (T)(std::lower_bound(data.begin(), data.end(), ele) -\n\
    \                      data.begin());\n        }\n        compress(tail...);\n\
    \    }\n\npublic:\n    template <typename... V>\n    CoordinateCompression(V &...v)\
    \ {\n        data.reserve(size_sum(v...));\n        push(v...);\n        std::sort(data.begin(),\
    \ data.end());\n        data.erase(std::unique(data.begin(), data.end()), data.end());\n\
    \        compress(v...);\n    }\n\n    const T &operator[](const T &ele) const\
    \ { return data[ele]; }\n\n    int size() const { return data.size(); }\n\n  \
    \  bool contains(const T &ele) const {\n        auto it = std::lower_bound(data.begin(),\
    \ data.end(), ele);\n        return it != data.end() && *it == ele;\n    }\n\n\
    \    T cc(const T &ele) const {\n        return (T)(std::lower_bound(data.begin(),\
    \ data.end(), ele) -\n                   data.begin());\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: other/coordinate_compression.hpp
  requiredBy: []
  timestamp: '2024-07-18 16:56:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/range_kth_smallest.test.cpp
documentation_of: other/coordinate_compression.hpp
layout: document
redirect_from:
- /library/other/coordinate_compression.hpp
- /library/other/coordinate_compression.hpp.html
title: other/coordinate_compression.hpp
---
