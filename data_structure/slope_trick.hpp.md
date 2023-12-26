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
  bundledCode: "#line 2 \"data_structure/slope_trick.hpp\"\n#include <cassert>\n#include\
    \ <limits>\n#include <queue>\n#include <type_traits>\n\ntemplate <typename T>\n\
    class SlopeTrick {\npublic:\n    static constexpr T MIN = std::numeric_limits<T>::min()\
    \ / 2;\n    static constexpr T MAX = std::numeric_limits<T>::max() / 2;\n\nprivate:\n\
    \    template <bool REV>\n    class PriorityQueue {\n        std::priority_queue<\n\
    \            T, std::vector<T>,\n            typename std::conditional<REV, std::greater<T>,\
    \ std::less<T>>::type>\n            pq;\n        T added;\n\n    public:\n   \
    \     PriorityQueue() : pq(), added(0) {\n            if constexpr (REV)\n   \
    \             pq.push(MAX);\n            else\n                pq.push(MIN);\n\
    \        }\n\n        void push(const T &x) { pq.push(x - added); }\n\n      \
    \  void add(const T &x) { added += x; }\n\n        T top() const { return pq.top()\
    \ + added; }\n\n        T pop() {\n            T ret = pq.top();\n           \
    \ pq.pop();\n            return ret += added;\n        }\n\n        void clear()\
    \ {\n            while (pq.size() > 1) pq.pop();\n        }\n    };\n\n    PriorityQueue<false>\
    \ l;\n    PriorityQueue<true> r;\n    T minimum;\n\npublic:\n    SlopeTrick()\
    \ : l(), r(), minimum(T(0)) {}\n\n    T min() const { return minimum; }\n\n  \
    \  std::pair<T, T> min_arg() const {\n        return std::pair<T, T>(l.top(),\
    \ r.top());\n    }\n\n    void add_constant(const T &a) { minimum += a; }\n\n\
    \    void add_plus(const T &a) {\n        if (l.top() > a) {\n            minimum\
    \ += l.top() - a;\n            l.push(a);\n            r.push(l.pop());\n    \
    \    } else {\n            r.push(a);\n        }\n    }\n\n    void add_minus(const\
    \ T &a) {\n        if (r.top() < a) {\n            minimum += a - r.top();\n \
    \           r.push(a);\n            l.push(r.pop());\n        } else {\n     \
    \       l.push(a);\n        }\n    }\n\n    void add_abs(const T &a) {\n     \
    \   add_plus(a);\n        add_minus(a);\n    }\n\n    void clear_left() { l.clear();\
    \ }\n\n    void clear_right() { r.clear(); }\n\n    void slide_min(const T &a,\
    \ const T &b) {\n        assert(a <= b);\n        l.add(a);\n        r.add(b);\n\
    \    }\n\n    void slide(const T &a) {\n        l.add(a);\n        r.add(a);\n\
    \    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <limits>\n#include <queue>\n#include\
    \ <type_traits>\n\ntemplate <typename T>\nclass SlopeTrick {\npublic:\n    static\
    \ constexpr T MIN = std::numeric_limits<T>::min() / 2;\n    static constexpr T\
    \ MAX = std::numeric_limits<T>::max() / 2;\n\nprivate:\n    template <bool REV>\n\
    \    class PriorityQueue {\n        std::priority_queue<\n            T, std::vector<T>,\n\
    \            typename std::conditional<REV, std::greater<T>, std::less<T>>::type>\n\
    \            pq;\n        T added;\n\n    public:\n        PriorityQueue() : pq(),\
    \ added(0) {\n            if constexpr (REV)\n                pq.push(MAX);\n\
    \            else\n                pq.push(MIN);\n        }\n\n        void push(const\
    \ T &x) { pq.push(x - added); }\n\n        void add(const T &x) { added += x;\
    \ }\n\n        T top() const { return pq.top() + added; }\n\n        T pop() {\n\
    \            T ret = pq.top();\n            pq.pop();\n            return ret\
    \ += added;\n        }\n\n        void clear() {\n            while (pq.size()\
    \ > 1) pq.pop();\n        }\n    };\n\n    PriorityQueue<false> l;\n    PriorityQueue<true>\
    \ r;\n    T minimum;\n\npublic:\n    SlopeTrick() : l(), r(), minimum(T(0)) {}\n\
    \n    T min() const { return minimum; }\n\n    std::pair<T, T> min_arg() const\
    \ {\n        return std::pair<T, T>(l.top(), r.top());\n    }\n\n    void add_constant(const\
    \ T &a) { minimum += a; }\n\n    void add_plus(const T &a) {\n        if (l.top()\
    \ > a) {\n            minimum += l.top() - a;\n            l.push(a);\n      \
    \      r.push(l.pop());\n        } else {\n            r.push(a);\n        }\n\
    \    }\n\n    void add_minus(const T &a) {\n        if (r.top() < a) {\n     \
    \       minimum += a - r.top();\n            r.push(a);\n            l.push(r.pop());\n\
    \        } else {\n            l.push(a);\n        }\n    }\n\n    void add_abs(const\
    \ T &a) {\n        add_plus(a);\n        add_minus(a);\n    }\n\n    void clear_left()\
    \ { l.clear(); }\n\n    void clear_right() { r.clear(); }\n\n    void slide_min(const\
    \ T &a, const T &b) {\n        assert(a <= b);\n        l.add(a);\n        r.add(b);\n\
    \    }\n\n    void slide(const T &a) {\n        l.add(a);\n        r.add(a);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/slope_trick.hpp
  requiredBy: []
  timestamp: '2023-12-26 16:56:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/slope_trick.hpp
layout: document
redirect_from:
- /library/data_structure/slope_trick.hpp
- /library/data_structure/slope_trick.hpp.html
title: data_structure/slope_trick.hpp
---
