---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/integer_convex_hull_trick.hpp\"\n\n#include\
    \ <cassert>\n#include <functional>\n#include <utility>\n#include <vector>\n\n\
    template <typename T, typename Compare = std::less<T>>\nclass IntegerConvexHullTrick\
    \ {\n    Compare comp;\n    std::vector<std::pair<T, T>> lines;\n\n    inline\
    \ T floor_div(T x, T y) const {\n        if (y < 0) {\n            return floor_div(-x,\
    \ -y);\n        } else {\n            if (x < 0) {\n                return -(-x\
    \ + y - 1) / y;\n            } else {\n                return x / y;\n       \
    \     }\n        }\n    }\n\n    inline bool need(const std::pair<T, T> &l0, const\
    \ std::pair<T, T> &l1,\n                     const std::pair<T, T> &l2) const\
    \ {\n        T x0 = floor_div(l1.second - l0.second, l0.first - l1.first);\n \
    \       T x1 = floor_div(l2.second - l1.second, l1.first - l2.first);\n      \
    \  return x0 < x1;\n    }\n\n    inline T eval(const std::pair<T, T> &l, T x)\
    \ const {\n        return l.first * x + l.second;\n    }\n\npublic:\n    IntegerConvexHullTrick(Compare\
    \ _c = Compare()) : comp(_c), lines() {}\n\n    // \\lambda x. ax + b\n    void\
    \ add(T a, T b) {\n        if (!lines.empty()) {\n            assert(!comp(lines.back().first,\
    \ a));\n            if (lines.back().first == a) {\n                if (comp(b,\
    \ lines.back().second)) {\n                    lines.pop_back();\n           \
    \     } else {\n                    return;\n                }\n            }\n\
    \        }\n        std::pair<T, T> l(a, b);\n        while (lines.size() >= 2\
    \ &&\n               !need(lines[lines.size() - 2], lines.back(), l)) {\n    \
    \        lines.pop_back();\n        }\n        lines.emplace_back(std::move(l));\n\
    \    }\n\n    T getmin(T x) const {\n        assert(!lines.empty());\n       \
    \ int ok = 0;\n        int ng = lines.size();\n        while (ng - ok > 1) {\n\
    \            int mid = (ok + ng) / 2;\n            if (comp(eval(lines[mid], x),\
    \ eval(lines[mid - 1], x))) {\n                ok = mid;\n            } else {\n\
    \                ng = mid;\n            }\n        }\n        return eval(lines[ok],\
    \ x);\n    }\n\n    const std::vector<std::pair<T, T>> &ref_lines() const { return\
    \ lines; }\n\n    friend IntegerConvexHullTrick<T> merge_two_chts(\n        const\
    \ IntegerConvexHullTrick<T> &cht0,\n        const IntegerConvexHullTrick<T> &cht1)\
    \ {\n        Compare comp;\n        IntegerConvexHullTrick<T> ret;\n        auto\
    \ it0 = cht0.lines.begin();\n        auto it1 = cht1.lines.begin();\n        while\
    \ (it0 != cht0.lines.end() || it1 != cht1.lines.end()) {\n            if (it1\
    \ == cht1.lines.end() ||\n                (it0 != cht0.lines.end() && !comp(it0->first,\
    \ it1->first))) {\n                ret.add(it0->first, it0->second);\n       \
    \         ++it0;\n            } else {\n                ret.add(it1->first, it1->second);\n\
    \                ++it1;\n            }\n        }\n        return ret;\n    }\n\
    };\n"
  code: "#pragma once\n\n#include <cassert>\n#include <functional>\n#include <utility>\n\
    #include <vector>\n\ntemplate <typename T, typename Compare = std::less<T>>\n\
    class IntegerConvexHullTrick {\n    Compare comp;\n    std::vector<std::pair<T,\
    \ T>> lines;\n\n    inline T floor_div(T x, T y) const {\n        if (y < 0) {\n\
    \            return floor_div(-x, -y);\n        } else {\n            if (x <\
    \ 0) {\n                return -(-x + y - 1) / y;\n            } else {\n    \
    \            return x / y;\n            }\n        }\n    }\n\n    inline bool\
    \ need(const std::pair<T, T> &l0, const std::pair<T, T> &l1,\n               \
    \      const std::pair<T, T> &l2) const {\n        T x0 = floor_div(l1.second\
    \ - l0.second, l0.first - l1.first);\n        T x1 = floor_div(l2.second - l1.second,\
    \ l1.first - l2.first);\n        return x0 < x1;\n    }\n\n    inline T eval(const\
    \ std::pair<T, T> &l, T x) const {\n        return l.first * x + l.second;\n \
    \   }\n\npublic:\n    IntegerConvexHullTrick(Compare _c = Compare()) : comp(_c),\
    \ lines() {}\n\n    // \\lambda x. ax + b\n    void add(T a, T b) {\n        if\
    \ (!lines.empty()) {\n            assert(!comp(lines.back().first, a));\n    \
    \        if (lines.back().first == a) {\n                if (comp(b, lines.back().second))\
    \ {\n                    lines.pop_back();\n                } else {\n       \
    \             return;\n                }\n            }\n        }\n        std::pair<T,\
    \ T> l(a, b);\n        while (lines.size() >= 2 &&\n               !need(lines[lines.size()\
    \ - 2], lines.back(), l)) {\n            lines.pop_back();\n        }\n      \
    \  lines.emplace_back(std::move(l));\n    }\n\n    T getmin(T x) const {\n   \
    \     assert(!lines.empty());\n        int ok = 0;\n        int ng = lines.size();\n\
    \        while (ng - ok > 1) {\n            int mid = (ok + ng) / 2;\n       \
    \     if (comp(eval(lines[mid], x), eval(lines[mid - 1], x))) {\n            \
    \    ok = mid;\n            } else {\n                ng = mid;\n            }\n\
    \        }\n        return eval(lines[ok], x);\n    }\n\n    const std::vector<std::pair<T,\
    \ T>> &ref_lines() const { return lines; }\n\n    friend IntegerConvexHullTrick<T>\
    \ merge_two_chts(\n        const IntegerConvexHullTrick<T> &cht0,\n        const\
    \ IntegerConvexHullTrick<T> &cht1) {\n        Compare comp;\n        IntegerConvexHullTrick<T>\
    \ ret;\n        auto it0 = cht0.lines.begin();\n        auto it1 = cht1.lines.begin();\n\
    \        while (it0 != cht0.lines.end() || it1 != cht1.lines.end()) {\n      \
    \      if (it1 == cht1.lines.end() ||\n                (it0 != cht0.lines.end()\
    \ && !comp(it0->first, it1->first))) {\n                ret.add(it0->first, it0->second);\n\
    \                ++it0;\n            } else {\n                ret.add(it1->first,\
    \ it1->second);\n                ++it1;\n            }\n        }\n        return\
    \ ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/integer_convex_hull_trick.hpp
  requiredBy: []
  timestamp: '2023-12-26 16:56:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/integer_convex_hull_trick.hpp
layout: document
redirect_from:
- /library/data_structure/integer_convex_hull_trick.hpp
- /library/data_structure/integer_convex_hull_trick.hpp.html
title: data_structure/integer_convex_hull_trick.hpp
---
