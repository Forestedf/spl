---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: opt/monge_min_cut.hpp
    title: opt/monge_min_cut.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/119
    links:
    - https://yukicoder.me/problems/no/119
  bundledCode: "#line 1 \"opt/test/yuki_119.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/119\"\
    \n#line 2 \"opt/monge_min_cut.hpp\"\n#include <atcoder/maxflow>\ntemplate <typename\
    \ T>\nclass MongeMinCut {\n    int n;\n    std::vector<int> k;\n    std::vector<int>\
    \ offset;\n    int s;\n    int t;\n    T all;\n    atcoder::mf_graph<T> graph;\n\
    \    T big;\n    void add_v(int v, T f0, T f1) {\n        if (f0 <= f1) {\n  \
    \          add_0(f0);\n            graph.add_edge(s, v, f1 - f0);\n        } else\
    \ {\n            add_0(f1);\n            graph.add_edge(v, t, f0 - f1);\n    \
    \    }\n    }\n\npublic:\n    MongeMinCut(const std::vector<int> &k, T big)\n\
    \        : n((int)k.size()),\n          k(k),\n          offset(n, 0),\n     \
    \     s(0),\n          t(0),\n          all(0),\n          graph(0),\n       \
    \   big(big) {\n        for (int i = 0; i < n; ++i) {\n            assert(k[i]\
    \ >= 1);\n        }\n        for (int i = 0; i < n - 1; ++i) {\n            offset[i\
    \ + 1] = offset[i] + k[i] - 1;\n        }\n        s = 0;\n        for (int i\
    \ = 0; i < n; ++i) {\n            s += k[i];\n        }\n        t = s + 1;\n\
    \        graph = atcoder::mf_graph<T>(s + 2);\n        for (int i = 0; i < n;\
    \ ++i) {\n            for (int j = 0; j < k[i] - 2; ++j) {\n                graph.add_edge(offset[i]\
    \ + j + 1, offset[i] + j, big);\n            }\n        }\n    }\n    void add_0(T\
    \ v) { all += v; }\n    void add_1(int i, const std::vector<T> &f) {\n       \
    \ assert(0 <= i && i < n && (int)f.size() == k[i]);\n        add_0(f[0]);\n  \
    \      for (int j = 0; j < k[i] - 1; ++j) {\n            add_v(offset[i] + j,\
    \ f[j + 1] - f[j], 0);\n        }\n    }\n    void add_2(int x, int y, std::vector<std::vector<T>>\
    \ f) {\n        assert(0 <= x && x < n);\n        assert(0 <= y && y < n);\n \
    \       assert((int)f.size() == k[x]);\n        for (int i = 0; i < k[x]; ++i)\
    \ {\n            assert((int)f[i].size() == k[y]);\n        }\n        std::vector<T>\
    \ tmp(k[x]);\n        for (int i = 0; i < k[x]; ++i) {\n            tmp[i] = f[i][0];\n\
    \        }\n        add_1(x, tmp);\n        for (int i = 0; i < k[x]; ++i) {\n\
    \            for (int j = 0; j < k[y]; ++j) {\n                f[i][j] -= tmp[i];\n\
    \            }\n        }\n        tmp = f[0];\n        add_1(y, tmp);\n     \
    \   for (int i = 0; i < k[x]; ++i) {\n            for (int j = 0; j < k[y]; ++j)\
    \ {\n                f[i][j] -= tmp[j];\n            }\n        }\n        for\
    \ (int i = 0; i < k[x] - 1; ++i) {\n            for (int j = 0; j < k[y] - 1;\
    \ ++j) {\n                T val = f[i][j] + f[i + 1][j + 1] - f[i + 1][j] - f[i][j\
    \ + 1];\n                assert(val <= 0);\n                add_0(val);\n    \
    \            graph.add_edge(offset[x] + i, offset[y] + j, -val);\n           \
    \     graph.add_edge(s, offset[x] + i, -val);\n            }\n        }\n    }\n\
    \    std::pair<T, std::vector<int>> solve() {\n        T cost = graph.flow(s,\
    \ t) + all;\n        std::vector<bool> cut = graph.min_cut(s);\n        std::vector<int>\
    \ ans(n, 0);\n        for (int i = 0; i < n; ++i) {\n            for (int j =\
    \ 0; j < k[i] - 1; ++j) {\n                if (cut[offset[i] + j]) {\n       \
    \             ++ans[i];\n                }\n            }\n        }\n       \
    \ return std::pair<T, std::vector<int>>(cost, ans);\n    }\n};\n#line 2 \"template/template.hpp\"\
    \n#include <bits/stdc++.h>\n#define OVERRIDE(a, b, c, d, ...) d\n#define REP2(i,\
    \ n) for (i32 i = 0; i < (i32)(n); ++i)\n#define REP3(i, m, n) for (i32 i = (i32)(m);\
    \ i < (i32)(n); ++i)\n#define REP(...) OVERRIDE(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)\n\
    #define PER2(i, n) for (i32 i = (i32)(n)-1; i >= 0; --i)\n#define PER3(i, m, n)\
    \ for (i32 i = (i32)(n)-1; i >= (i32)(m); --i)\n#define PER(...) OVERRIDE(__VA_ARGS__,\
    \ PER3, PER2)(__VA_ARGS__)\n#define ALL(x) begin(x), end(x)\n#define LEN(x) (i32)(x.size())\n\
    using namespace std;\nusing u32 = unsigned int;\nusing u64 = unsigned long long;\n\
    using i32 = signed int;\nusing i64 = signed long long;\nusing f64 = double;\n\
    using f80 = long double;\nusing pi = pair<i32, i32>;\nusing pl = pair<i64, i64>;\n\
    template <typename T>\nusing V = vector<T>;\ntemplate <typename T>\nusing VV =\
    \ V<V<T>>;\ntemplate <typename T>\nusing VVV = V<V<V<T>>>;\ntemplate <typename\
    \ T>\nusing VVVV = V<V<V<V<T>>>>;\ntemplate <typename T>\nusing PQR = priority_queue<T,\
    \ V<T>, greater<T>>;\ntemplate <typename T>\nbool chmin(T &x, const T &y) {\n\
    \    if (x > y) {\n        x = y;\n        return true;\n    }\n    return false;\n\
    }\ntemplate <typename T>\nbool chmax(T &x, const T &y) {\n    if (x < y) {\n \
    \       x = y;\n        return true;\n    }\n    return false;\n}\ntemplate <typename\
    \ T>\ni32 lob(const V<T> &arr, const T &v) {\n    return (i32)(lower_bound(ALL(arr),\
    \ v) - arr.begin());\n}\ntemplate <typename T>\ni32 upb(const V<T> &arr, const\
    \ T &v) {\n    return (i32)(upper_bound(ALL(arr), v) - arr.begin());\n}\ntemplate\
    \ <typename T>\nV<i32> argsort(const V<T> &arr) {\n    V<i32> ret(arr.size());\n\
    \    iota(ALL(ret), 0);\n    sort(ALL(ret), [&](i32 i, i32 j) -> bool {\n    \
    \    if (arr[i] == arr[j]) {\n            return i < j;\n        } else {\n  \
    \          return arr[i] < arr[j];\n        }\n    });\n    return ret;\n}\n#ifdef\
    \ INT128\nusing u128 = __uint128_t;\nusing i128 = __int128_t;\n#endif\n[[maybe_unused]]\
    \ constexpr i32 INF = 1000000100;\n[[maybe_unused]] constexpr i64 INF64 = 3000000000000000100;\n\
    struct SetUpIO {\n    SetUpIO() {\n#ifdef FAST_IO\n        ios::sync_with_stdio(false);\n\
    \        cin.tie(nullptr);\n#endif\n        cout << fixed << setprecision(15);\n\
    \    }\n} set_up_io;\nvoid scan(char &x) { cin >> x; }\nvoid scan(u32 &x) { cin\
    \ >> x; }\nvoid scan(u64 &x) { cin >> x; }\nvoid scan(i32 &x) { cin >> x; }\n\
    void scan(i64 &x) { cin >> x; }\nvoid scan(string &x) { cin >> x; }\ntemplate\
    \ <typename T>\nvoid scan(V<T> &x) {\n    for (T &ele : x) {\n        scan(ele);\n\
    \    }\n}\nvoid read() {}\ntemplate <typename Head, typename... Tail>\nvoid read(Head\
    \ &head, Tail &...tail) {\n    scan(head);\n    read(tail...);\n}\n#define CHAR(...)\
    \     \\\n    char __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define U32(...) \
    \    \\\n    u32 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define U64(...)   \
    \  \\\n    u64 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define I32(...)     \\\
    \n    i32 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define I64(...)     \\\n \
    \   i64 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define STR(...)        \\\n\
    \    string __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define VEC(type, name, size)\
    \ \\\n    V<type> name(size);       \\\n    read(name);\n#define VVEC(type, name,\
    \ size1, size2)    \\\n    VV<type> name(size1, V<type>(size2)); \\\n    read(name);\n\
    #line 4 \"opt/test/yuki_119.test.cpp\"\n\nint main() {\n    I32(n);\n    V<i32>\
    \ b(n), c(n);\n    REP(i, n) {\n        read(b[i], c[i]);\n    }\n    I32(m)\n\
    \    V<pi> edge(m);\n    for (auto &[u, v] : edge) {\n        read(u, v);\n  \
    \  }\n    MongeMinCut<i32> mincut(V<i32>(n, 3), INF);\n    REP(i, n) {\n     \
    \   V<i32> f(3, 0);\n        f[0] = -b[i];\n        f[2] = -c[i];\n        mincut.add_1(i,\
    \ f);\n    }\n    for (auto [u, v] : edge) {\n        VV<i32> f(3, V<i32>(3, 0));\n\
    \        f[0][2] = INF / m;\n        mincut.add_2(u, v, f);\n    }\n    cout <<\
    \ -mincut.solve().first << '\\n';\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/119\"\n#include \"../../opt/monge_min_cut.hpp\"\
    \n#include \"../../template/template.hpp\"\n\nint main() {\n    I32(n);\n    V<i32>\
    \ b(n), c(n);\n    REP(i, n) {\n        read(b[i], c[i]);\n    }\n    I32(m)\n\
    \    V<pi> edge(m);\n    for (auto &[u, v] : edge) {\n        read(u, v);\n  \
    \  }\n    MongeMinCut<i32> mincut(V<i32>(n, 3), INF);\n    REP(i, n) {\n     \
    \   V<i32> f(3, 0);\n        f[0] = -b[i];\n        f[2] = -c[i];\n        mincut.add_1(i,\
    \ f);\n    }\n    for (auto [u, v] : edge) {\n        VV<i32> f(3, V<i32>(3, 0));\n\
    \        f[0][2] = INF / m;\n        mincut.add_2(u, v, f);\n    }\n    cout <<\
    \ -mincut.solve().first << '\\n';\n}"
  dependsOn:
  - opt/monge_min_cut.hpp
  - template/template.hpp
  isVerificationFile: true
  path: opt/test/yuki_119.test.cpp
  requiredBy: []
  timestamp: '2025-05-17 23:14:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: opt/test/yuki_119.test.cpp
layout: document
redirect_from:
- /verify/opt/test/yuki_119.test.cpp
- /verify/opt/test/yuki_119.test.cpp.html
title: opt/test/yuki_119.test.cpp
---
