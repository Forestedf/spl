---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/point_add_rectangle_sum.test.cpp
    title: data_structure/test/point_add_rectangle_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/general_range_tree.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\ntemplate <typename T>\nclass GRangeTree\
    \ {\n    std::vector<T> xs;\n    std::vector<std::pair<T, int>> arr;\n    std::vector<int>\
    \ rngs;\n\n    static bool compare_by_first(const std::pair<T, int> &p0,\n   \
    \                              const std::pair<T, int> &p1) {\n        return\
    \ p0.first < p1.first;\n    }\n\npublic:\n    GRangeTree(const std::vector<std::pair<T,\
    \ T>> &pts) : xs(), arr(), rngs() {\n        xs.reserve(pts.size());\n       \
    \ for (const auto &[x, _y] : pts) {\n            xs.push_back(x);\n        }\n\
    \        std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n        int xs_sz = (int)xs.size();\n        std::vector<std::vector<std::pair<T,\
    \ int>>> nodes(2 * xs_sz);\n        for (int i = 0; i < (int)pts.size(); ++i)\
    \ {\n            int xi =\n                (int)(std::lower_bound(xs.begin(),\
    \ xs.end(), pts[i].first) -\n                      xs.begin());\n            nodes[xs_sz\
    \ + xi].emplace_back(pts[i].second, i);\n        }\n        for (int i = xs_sz;\
    \ i < 2 * xs_sz; ++i) {\n            std::sort(nodes[i].begin(), nodes[i].end(),\
    \ compare_by_first);\n        }\n        for (int i = xs_sz - 1; i > 0; --i) {\n\
    \            nodes[i].reserve(nodes[2 * i].size() + nodes[2 * i + 1].size());\n\
    \            std::merge(nodes[2 * i].begin(), nodes[2 * i].end(),\n          \
    \             nodes[2 * i + 1].begin(), nodes[2 * i + 1].end(),\n            \
    \           std::back_inserter(nodes[i]), compare_by_first);\n        }\n    \
    \    int tot = 0;\n        for (int i = 1; i < 2 * xs_sz; ++i) {\n           \
    \ tot += (int)nodes[i].size();\n        }\n        arr.reserve(tot);\n       \
    \ for (int i = 1; i < 2 * xs_sz; ++i) {\n            for (auto ele : nodes[i])\
    \ {\n                arr.emplace_back(ele);\n            }\n        }\n      \
    \  rngs.resize(2 * xs_sz, 0);\n        for (int i = 1; i < 2 * xs_sz; ++i) {\n\
    \            rngs[i] = rngs[i - 1] + (int)nodes[i].size();\n        }\n    }\n\
    \n    int size() const { return (int)arr.size(); }\n    int operator[](int i)\
    \ const { return arr[i].second; }\n\n    // [xl, xr), [yl, yr)\n    std::vector<std::pair<int,\
    \ int>> rectangle(T xl, T xr, T yl, T yr) const {\n        int xli =\n       \
    \     (int)(std::lower_bound(xs.begin(), xs.end(), xl) - xs.begin());\n      \
    \  int xri =\n            (int)(std::lower_bound(xs.begin(), xs.end(), xr) - xs.begin());\n\
    \        std::vector<std::pair<int, int>> ret;\n        xli += (int)xs.size();\n\
    \        xri += (int)xs.size();\n        while (xli < xri) {\n            if (xli\
    \ % 2 == 1) {\n                int l = rngs[xli - 1];\n                int r =\
    \ rngs[xli];\n                ret.emplace_back(\n                    (int)(std::lower_bound(arr.begin()\
    \ + l, arr.begin() + r,\n                                           std::pair<T,\
    \ int>(yl, 0),\n                                           compare_by_first) -\n\
    \                          arr.begin()),\n                    (int)(std::lower_bound(arr.begin()\
    \ + l, arr.begin() + r,\n                                           std::pair<T,\
    \ int>(yr, 0),\n                                           compare_by_first) -\n\
    \                          arr.begin()));\n                ++xli;\n          \
    \  }\n            if (xri % 2 == 1) {\n                --xri;\n              \
    \  int l = rngs[xri - 1];\n                int r = rngs[xri];\n              \
    \  ret.emplace_back(\n                    (int)(std::lower_bound(arr.begin() +\
    \ l, arr.begin() + r,\n                                           std::pair<T,\
    \ int>(yl, 0),\n                                           compare_by_first) -\n\
    \                          arr.begin()),\n                    (int)(std::lower_bound(arr.begin()\
    \ + l, arr.begin() + r,\n                                           std::pair<T,\
    \ int>(yr, 0),\n                                           compare_by_first) -\n\
    \                          arr.begin()));\n            }\n            xli /= 2;\n\
    \            xri /= 2;\n        }\n        return ret;\n    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \ntemplate <typename T>\nclass GRangeTree {\n    std::vector<T> xs;\n    std::vector<std::pair<T,\
    \ int>> arr;\n    std::vector<int> rngs;\n\n    static bool compare_by_first(const\
    \ std::pair<T, int> &p0,\n                                 const std::pair<T,\
    \ int> &p1) {\n        return p0.first < p1.first;\n    }\n\npublic:\n    GRangeTree(const\
    \ std::vector<std::pair<T, T>> &pts) : xs(), arr(), rngs() {\n        xs.reserve(pts.size());\n\
    \        for (const auto &[x, _y] : pts) {\n            xs.push_back(x);\n   \
    \     }\n        std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n        int xs_sz = (int)xs.size();\n        std::vector<std::vector<std::pair<T,\
    \ int>>> nodes(2 * xs_sz);\n        for (int i = 0; i < (int)pts.size(); ++i)\
    \ {\n            int xi =\n                (int)(std::lower_bound(xs.begin(),\
    \ xs.end(), pts[i].first) -\n                      xs.begin());\n            nodes[xs_sz\
    \ + xi].emplace_back(pts[i].second, i);\n        }\n        for (int i = xs_sz;\
    \ i < 2 * xs_sz; ++i) {\n            std::sort(nodes[i].begin(), nodes[i].end(),\
    \ compare_by_first);\n        }\n        for (int i = xs_sz - 1; i > 0; --i) {\n\
    \            nodes[i].reserve(nodes[2 * i].size() + nodes[2 * i + 1].size());\n\
    \            std::merge(nodes[2 * i].begin(), nodes[2 * i].end(),\n          \
    \             nodes[2 * i + 1].begin(), nodes[2 * i + 1].end(),\n            \
    \           std::back_inserter(nodes[i]), compare_by_first);\n        }\n    \
    \    int tot = 0;\n        for (int i = 1; i < 2 * xs_sz; ++i) {\n           \
    \ tot += (int)nodes[i].size();\n        }\n        arr.reserve(tot);\n       \
    \ for (int i = 1; i < 2 * xs_sz; ++i) {\n            for (auto ele : nodes[i])\
    \ {\n                arr.emplace_back(ele);\n            }\n        }\n      \
    \  rngs.resize(2 * xs_sz, 0);\n        for (int i = 1; i < 2 * xs_sz; ++i) {\n\
    \            rngs[i] = rngs[i - 1] + (int)nodes[i].size();\n        }\n    }\n\
    \n    int size() const { return (int)arr.size(); }\n    int operator[](int i)\
    \ const { return arr[i].second; }\n\n    // [xl, xr), [yl, yr)\n    std::vector<std::pair<int,\
    \ int>> rectangle(T xl, T xr, T yl, T yr) const {\n        int xli =\n       \
    \     (int)(std::lower_bound(xs.begin(), xs.end(), xl) - xs.begin());\n      \
    \  int xri =\n            (int)(std::lower_bound(xs.begin(), xs.end(), xr) - xs.begin());\n\
    \        std::vector<std::pair<int, int>> ret;\n        xli += (int)xs.size();\n\
    \        xri += (int)xs.size();\n        while (xli < xri) {\n            if (xli\
    \ % 2 == 1) {\n                int l = rngs[xli - 1];\n                int r =\
    \ rngs[xli];\n                ret.emplace_back(\n                    (int)(std::lower_bound(arr.begin()\
    \ + l, arr.begin() + r,\n                                           std::pair<T,\
    \ int>(yl, 0),\n                                           compare_by_first) -\n\
    \                          arr.begin()),\n                    (int)(std::lower_bound(arr.begin()\
    \ + l, arr.begin() + r,\n                                           std::pair<T,\
    \ int>(yr, 0),\n                                           compare_by_first) -\n\
    \                          arr.begin()));\n                ++xli;\n          \
    \  }\n            if (xri % 2 == 1) {\n                --xri;\n              \
    \  int l = rngs[xri - 1];\n                int r = rngs[xri];\n              \
    \  ret.emplace_back(\n                    (int)(std::lower_bound(arr.begin() +\
    \ l, arr.begin() + r,\n                                           std::pair<T,\
    \ int>(yl, 0),\n                                           compare_by_first) -\n\
    \                          arr.begin()),\n                    (int)(std::lower_bound(arr.begin()\
    \ + l, arr.begin() + r,\n                                           std::pair<T,\
    \ int>(yr, 0),\n                                           compare_by_first) -\n\
    \                          arr.begin()));\n            }\n            xli /= 2;\n\
    \            xri /= 2;\n        }\n        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/general_range_tree.hpp
  requiredBy: []
  timestamp: '2023-12-26 16:56:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/point_add_rectangle_sum.test.cpp
documentation_of: data_structure/general_range_tree.hpp
layout: document
redirect_from:
- /library/data_structure/general_range_tree.hpp
- /library/data_structure/general_range_tree.hpp.html
title: data_structure/general_range_tree.hpp
---
