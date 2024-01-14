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
  bundledCode: "#line 2 \"template/debug.hpp\"\n\n#include <array>\n#include <atcoder/modint>\n\
    #include <deque>\n#include <iostream>\n#include <map>\n#include <queue>\n#include\
    \ <set>\n#include <stack>\n#include <tuple>\n#include <type_traits>\n#include\
    \ <utility>\n#include <vector>\ntemplate <typename T, std::enable_if_t<std::is_integral_v<T>>\
    \ * = nullptr>\nvoid debug(T x) {\n    std::cerr << x;\n}\n\ntemplate <typename\
    \ T, std::enable_if_t<std::is_floating_point_v<T>> * = nullptr>\nvoid debug(T\
    \ x) {\n    std::cerr << x;\n}\n\nvoid debug(bool b) {\n    if (b) {\n       \
    \ std::cerr << \"true\";\n    } else {\n        std::cerr << \"false\";\n    }\n\
    }\n\ntemplate <typename T>\nvoid debug(const std::vector<T> &x);\n\ntemplate <int\
    \ mod>\nvoid debug(atcoder::static_modint<mod> v) {\n    std::cerr << v.val();\n\
    }\n\nvoid debug(const std::string &s) { std::cerr << '\"' << s << '\"'; }\n\n\
    template <typename T, typename U>\nvoid debug(const std::pair<T, U> &p) {\n  \
    \  std::cerr << '(';\n    debug(p.first);\n    std::cerr << \", \";\n    debug(p.second);\n\
    \    std::cerr << ')';\n}\n\ntemplate <std::size_t cur, typename... Args>\nvoid\
    \ tuple_debug_inner(const std::tuple<Args...> &t) {\n    std::cerr << std::get<cur>(t);\n\
    \    if constexpr (cur + 1 != sizeof...(Args)) {\n        std::cerr << \", \"\
    ;\n        tuple_debug_inner<cur + 1, Args...>(t);\n    }\n}\n\ntemplate <typename...\
    \ Args>\nvoid debug(const std::tuple<Args...> &t) {\n    std::cerr << '(';\n \
    \   tuple_debug_inner<0, Args...>(t);\n    std::cerr << ')';\n}\n\ntemplate <typename\
    \ T, std::size_t s>\nvoid debug(const std::array<T, s> &arr) {\n    std::cerr\
    \ << '[';\n    for (std::size_t i = 0; i < s; ++i) {\n        debug(arr[i]);\n\
    \        if (i + 1 != s) {\n            std::cerr << \", \";\n        }\n    }\n\
    \    std::cerr << ']';\n}\n\ntemplate <typename K, typename V>\nvoid debug(const\
    \ std::map<K, V> &mp) {\n    std::cerr << '{';\n    for (const auto [k, v] : mp)\
    \ {\n        std::cerr << ' ';\n        debug(k);\n        std::cerr << ':';\n\
    \        debug(v);\n    }\n    std::cerr << \" }\";\n}\n\ntemplate <typename T>\n\
    void debug(const std::set<T> &st) {\n    std::cerr << '{';\n    for (const T &ele\
    \ : st) {\n        std::cerr << ' ';\n        debug(ele);\n    }\n    std::cerr\
    \ << \" }\";\n}\n\ntemplate <typename T>\nvoid debug(std::queue<T> que) {\n  \
    \  std::cerr << '[';\n    while (!que.empty()) {\n        T ele = que.front();\n\
    \        que.pop();\n        debug(ele);\n        if (!que.empty()) {\n      \
    \      std::cerr << ' ';\n        }\n    }\n    std::cerr << ']';\n}\n\ntemplate\
    \ <typename T>\nvoid debug(const std::vector<T> &v) {\n    std::cerr << '[';\n\
    \    for (std::size_t i = 0; i < v.size(); ++i) {\n        debug(v[i]);\n    \
    \    if (i + 1 != v.size()) {\n            std::cerr << \", \";\n        }\n \
    \   }\n    std::cerr << ']';\n}\n\ntemplate <typename T, typename Container, typename\
    \ Comp>\nvoid debug(std::priority_queue<T, Container, Comp> que) {\n    std::cerr\
    \ << '[';\n    while (!que.empty()) {\n        T ele = que.top();\n        que.pop();\n\
    \        debug(ele);\n        if (!que.empty()) {\n            std::cerr << '\
    \ ';\n        }\n    }\n    std::cerr << ']';\n}\n\ntemplate <typename T>\nvoid\
    \ debug(std::stack<T> sta) {\n    std::cerr << '[';\n    while (!sta.empty())\
    \ {\n        T ele = sta.top();\n        sta.pop();\n        debug(ele);\n   \
    \     if (!sta.empty()) {\n            std::cerr << ' ';\n        }\n    }\n \
    \   std::cerr << ']';\n}\n\ntemplate <typename T>\nvoid debug(std::deque<T> dq)\
    \ {\n    std::cerr << '[';\n    while (!dq.empty()) {\n        T ele = dq.front();\n\
    \        dq.pop_front();\n        debug(ele);\n        if (!dq.empty()) {\n  \
    \          std::cerr << ' ';\n        }\n    }\n    std::cerr << ']';\n}\n\nvoid\
    \ debug_many(bool first) {}\ntemplate <typename Head, typename... Tail>\nvoid\
    \ debug_many(bool first, const Head &head, const Tail &... tail) {\n    if (!first)\
    \ {\n        std::cerr << \", \";\n    }\n    debug(head);\n    debug_many(false,\
    \ tail...);\n}\n\n#define DBG(...)                            \\\n    do {   \
    \                                 \\\n        std::cerr << #__VA_ARGS__ << \"\
    \ : \"; \\\n        debug_many(true, __VA_ARGS__);                 \\\n      \
    \  std::cerr << std::endl;             \\\n    } while (false)\n"
  code: "#pragma once\n\n#include <array>\n#include <atcoder/modint>\n#include <deque>\n\
    #include <iostream>\n#include <map>\n#include <queue>\n#include <set>\n#include\
    \ <stack>\n#include <tuple>\n#include <type_traits>\n#include <utility>\n#include\
    \ <vector>\ntemplate <typename T, std::enable_if_t<std::is_integral_v<T>> * =\
    \ nullptr>\nvoid debug(T x) {\n    std::cerr << x;\n}\n\ntemplate <typename T,\
    \ std::enable_if_t<std::is_floating_point_v<T>> * = nullptr>\nvoid debug(T x)\
    \ {\n    std::cerr << x;\n}\n\nvoid debug(bool b) {\n    if (b) {\n        std::cerr\
    \ << \"true\";\n    } else {\n        std::cerr << \"false\";\n    }\n}\n\ntemplate\
    \ <typename T>\nvoid debug(const std::vector<T> &x);\n\ntemplate <int mod>\nvoid\
    \ debug(atcoder::static_modint<mod> v) {\n    std::cerr << v.val();\n}\n\nvoid\
    \ debug(const std::string &s) { std::cerr << '\"' << s << '\"'; }\n\ntemplate\
    \ <typename T, typename U>\nvoid debug(const std::pair<T, U> &p) {\n    std::cerr\
    \ << '(';\n    debug(p.first);\n    std::cerr << \", \";\n    debug(p.second);\n\
    \    std::cerr << ')';\n}\n\ntemplate <std::size_t cur, typename... Args>\nvoid\
    \ tuple_debug_inner(const std::tuple<Args...> &t) {\n    std::cerr << std::get<cur>(t);\n\
    \    if constexpr (cur + 1 != sizeof...(Args)) {\n        std::cerr << \", \"\
    ;\n        tuple_debug_inner<cur + 1, Args...>(t);\n    }\n}\n\ntemplate <typename...\
    \ Args>\nvoid debug(const std::tuple<Args...> &t) {\n    std::cerr << '(';\n \
    \   tuple_debug_inner<0, Args...>(t);\n    std::cerr << ')';\n}\n\ntemplate <typename\
    \ T, std::size_t s>\nvoid debug(const std::array<T, s> &arr) {\n    std::cerr\
    \ << '[';\n    for (std::size_t i = 0; i < s; ++i) {\n        debug(arr[i]);\n\
    \        if (i + 1 != s) {\n            std::cerr << \", \";\n        }\n    }\n\
    \    std::cerr << ']';\n}\n\ntemplate <typename K, typename V>\nvoid debug(const\
    \ std::map<K, V> &mp) {\n    std::cerr << '{';\n    for (const auto [k, v] : mp)\
    \ {\n        std::cerr << ' ';\n        debug(k);\n        std::cerr << ':';\n\
    \        debug(v);\n    }\n    std::cerr << \" }\";\n}\n\ntemplate <typename T>\n\
    void debug(const std::set<T> &st) {\n    std::cerr << '{';\n    for (const T &ele\
    \ : st) {\n        std::cerr << ' ';\n        debug(ele);\n    }\n    std::cerr\
    \ << \" }\";\n}\n\ntemplate <typename T>\nvoid debug(std::queue<T> que) {\n  \
    \  std::cerr << '[';\n    while (!que.empty()) {\n        T ele = que.front();\n\
    \        que.pop();\n        debug(ele);\n        if (!que.empty()) {\n      \
    \      std::cerr << ' ';\n        }\n    }\n    std::cerr << ']';\n}\n\ntemplate\
    \ <typename T>\nvoid debug(const std::vector<T> &v) {\n    std::cerr << '[';\n\
    \    for (std::size_t i = 0; i < v.size(); ++i) {\n        debug(v[i]);\n    \
    \    if (i + 1 != v.size()) {\n            std::cerr << \", \";\n        }\n \
    \   }\n    std::cerr << ']';\n}\n\ntemplate <typename T, typename Container, typename\
    \ Comp>\nvoid debug(std::priority_queue<T, Container, Comp> que) {\n    std::cerr\
    \ << '[';\n    while (!que.empty()) {\n        T ele = que.top();\n        que.pop();\n\
    \        debug(ele);\n        if (!que.empty()) {\n            std::cerr << '\
    \ ';\n        }\n    }\n    std::cerr << ']';\n}\n\ntemplate <typename T>\nvoid\
    \ debug(std::stack<T> sta) {\n    std::cerr << '[';\n    while (!sta.empty())\
    \ {\n        T ele = sta.top();\n        sta.pop();\n        debug(ele);\n   \
    \     if (!sta.empty()) {\n            std::cerr << ' ';\n        }\n    }\n \
    \   std::cerr << ']';\n}\n\ntemplate <typename T>\nvoid debug(std::deque<T> dq)\
    \ {\n    std::cerr << '[';\n    while (!dq.empty()) {\n        T ele = dq.front();\n\
    \        dq.pop_front();\n        debug(ele);\n        if (!dq.empty()) {\n  \
    \          std::cerr << ' ';\n        }\n    }\n    std::cerr << ']';\n}\n\nvoid\
    \ debug_many(bool first) {}\ntemplate <typename Head, typename... Tail>\nvoid\
    \ debug_many(bool first, const Head &head, const Tail &... tail) {\n    if (!first)\
    \ {\n        std::cerr << \", \";\n    }\n    debug(head);\n    debug_many(false,\
    \ tail...);\n}\n\n#define DBG(...)                            \\\n    do {   \
    \                                 \\\n        std::cerr << #__VA_ARGS__ << \"\
    \ : \"; \\\n        debug_many(true, __VA_ARGS__);                 \\\n      \
    \  std::cerr << std::endl;             \\\n    } while (false)"
  dependsOn: []
  isVerificationFile: false
  path: template/debug.hpp
  requiredBy: []
  timestamp: '2024-01-14 15:15:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/debug.hpp
layout: document
redirect_from:
- /library/template/debug.hpp
- /library/template/debug.hpp.html
title: template/debug.hpp
---
