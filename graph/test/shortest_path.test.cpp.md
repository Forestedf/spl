---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: graph/graph.hpp
    title: graph/graph.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"graph/test/shortest_path.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/shortest_path\"\n#define FAST_IO\n#line 2 \"graph/dijkstra.hpp\"\
    \n#include <limits>\n#include <queue>\n#line 2 \"graph/graph.hpp\"\n#include <iostream>\n\
    #include <cassert>\n#include <vector>\ntemplate <typename T>\nstruct Edge {\n\
    \    using W = T;\n    int from, to, id;\n    W weight;\n};\ntemplate <typename\
    \ T>\nvoid debug(const Edge<T> &e) {\n    std::cerr << e.from << \" -> \" << e.to\
    \ << \" id = \" << e.id << \" weight = \";\n    debug(e.weight);\n}\ntemplate\
    \ <typename T = int, bool DIR = false>\nclass Graph {\npublic:\n    using E =\
    \ Edge<T>;\n    using W = T;\n    static constexpr bool DIRECTED = DIR;\n    struct\
    \ Adjacency {\n        using Iter = typename std::vector<E>::iterator;\n     \
    \   Iter be, en;\n        Iter begin() const { return be; }\n        Iter end()\
    \ const { return en; }\n        int size() const { return (int)std::distance(be,\
    \ en); }\n        E &operator[](int idx) const { return be[idx]; }\n    };\n \
    \   struct ConstAdjacency {\n        using Iter = typename std::vector<E>::const_iterator;\n\
    \        Iter be, en;\n        Iter begin() const { return be; }\n        Iter\
    \ end() const { return en; }\n        int size() const { return (int)std::distance(be,\
    \ en); }\n        const E &operator[](int idx) const { return be[idx]; }\n   \
    \ };\n\nprivate:\n    int n, m;\n    std::vector<E> edges, csr;\n    std::vector<int>\
    \ sep;\n    bool built;\n\npublic:\n    Graph(int n) : n(n), m(0), built(false)\
    \ {}\n    int v() const { return n; }\n    int e() const { return m; }\n    void\
    \ add_edge(int from, int to, W weight = 1) {\n        assert(0 <= from && from\
    \ < n && 0 <= to && to < n);\n        edges.emplace_back(E{from, to, m++, weight});\n\
    \    }\n    void build() {\n        sep.assign(n + 1, 0);\n        csr.resize(DIRECTED\
    \ ? m : 2 * m);\n        for (const E &e : edges) {\n            ++sep[e.from\
    \ + 1];\n            if (!DIRECTED) {\n                ++sep[e.to + 1];\n    \
    \        }\n        }\n        for (int i = 0; i < n; ++i) {\n            sep[i\
    \ + 1] += sep[i];\n        }\n        std::vector<int> c = sep;\n        for (const\
    \ E &e : edges) {\n            csr[c[e.from]++] = e;\n            if (!DIRECTED)\
    \ {\n                csr[c[e.to]++] = E{e.to, e.from, e.id, e.weight};\n     \
    \       }\n        }\n        built = true;\n    }\n    Adjacency operator[](int\
    \ v) {\n        assert(built && 0 <= v && v < n);\n        return Adjacency{csr.begin()\
    \ + sep[v], csr.begin() + sep[v + 1]};\n    }\n    ConstAdjacency operator[](int\
    \ v) const {\n        assert(built && 0 <= v && v < n);\n        return ConstAdjacency{csr.begin()\
    \ + sep[v], csr.begin() + sep[v + 1]};\n    }\n};\n#line 5 \"graph/dijkstra.hpp\"\
    \n// (dist, from)\ntemplate <typename T, bool DIR>\nstd::pair<std::vector<T>,\
    \ std::vector<int>> dijkstra(\n    const Graph<T, DIR> &g, int s, T inf = std::numeric_limits<T>::max())\
    \ {\n    assert(0 <= s && s < g.v());\n    std::vector<T> dist(g.v(), inf);\n\
    \    std::vector<int> par(g.v(), -1);\n    std::priority_queue<std::pair<T, int>,\
    \ std::vector<std::pair<T, int>>,\n                        std::greater<>>\n \
    \       pq;\n    dist[s] = 0;\n    pq.emplace(0, s);\n    while (!pq.empty())\
    \ {\n        auto [d, v] = pq.top();\n        pq.pop();\n        if (d > dist[v])\
    \ {\n            continue;\n        }\n        for (const Edge<T> &e : g[v]) {\n\
    \            if (d + e.weight < dist[e.to]) {\n                dist[e.to] = d\
    \ + e.weight;\n                par[e.to] = v;\n                pq.emplace(dist[e.to],\
    \ e.to);\n            }\n        }\n    }\n    return std::make_pair(dist, par);\n\
    }\n#line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#define OVERRIDE(a,\
    \ b, c, d, ...) d\n#define REP2(i, n) for (i32 i = 0; i < (i32)(n); ++i)\n#define\
    \ REP3(i, m, n) for (i32 i = (i32)(m); i < (i32)(n); ++i)\n#define REP(...) OVERRIDE(__VA_ARGS__,\
    \ REP3, REP2)(__VA_ARGS__)\n#define PER2(i, n) for (i32 i = (i32)(n)-1; i >= 0;\
    \ --i)\n#define PER3(i, m, n) for (i32 i = (i32)(n)-1; i >= (i32)(m); --i)\n#define\
    \ PER(...) OVERRIDE(__VA_ARGS__, PER3, PER2)(__VA_ARGS__)\n#define ALL(x) begin(x),\
    \ end(x)\n#define LEN(x) (i32)(x.size())\nusing namespace std;\nusing u32 = unsigned\
    \ int;\nusing u64 = unsigned long long;\nusing i32 = signed int;\nusing i64 =\
    \ signed long long;\nusing f64 = double;\nusing f80 = long double;\nusing pi =\
    \ pair<i32, i32>;\nusing pl = pair<i64, i64>;\ntemplate <typename T>\nusing V\
    \ = vector<T>;\ntemplate <typename T>\nusing VV = V<V<T>>;\ntemplate <typename\
    \ T>\nusing VVV = V<V<V<T>>>;\ntemplate <typename T>\nusing VVVV = V<V<V<V<T>>>>;\n\
    template <typename T>\nusing PQR = priority_queue<T, V<T>, greater<T>>;\ntemplate\
    \ <typename T>\nbool chmin(T &x, const T &y) {\n    if (x > y) {\n        x =\
    \ y;\n        return true;\n    }\n    return false;\n}\ntemplate <typename T>\n\
    bool chmax(T &x, const T &y) {\n    if (x < y) {\n        x = y;\n        return\
    \ true;\n    }\n    return false;\n}\ntemplate <typename T>\ni32 lob(const V<T>\
    \ &arr, const T &v) {\n    return (i32)(lower_bound(ALL(arr), v) - arr.begin());\n\
    }\ntemplate <typename T>\ni32 upb(const V<T> &arr, const T &v) {\n    return (i32)(upper_bound(ALL(arr),\
    \ v) - arr.begin());\n}\ntemplate <typename T>\nV<i32> argsort(const V<T> &arr)\
    \ {\n    V<i32> ret(arr.size());\n    iota(ALL(ret), 0);\n    sort(ALL(ret), [&](i32\
    \ i, i32 j) -> bool {\n        if (arr[i] == arr[j]) {\n            return i <\
    \ j;\n        } else {\n            return arr[i] < arr[j];\n        }\n    });\n\
    \    return ret;\n}\n#ifdef INT128\nusing u128 = __uint128_t;\nusing i128 = __int128_t;\n\
    #endif\n[[maybe_unused]] constexpr i32 INF = 1000000100;\n[[maybe_unused]] constexpr\
    \ i64 INF64 = 3000000000000000100;\nstruct SetUpIO {\n    SetUpIO() {\n#ifdef\
    \ FAST_IO\n        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n#endif\n\
    \        cout << fixed << setprecision(15);\n    }\n} set_up_io;\nvoid scan(char\
    \ &x) { cin >> x; }\nvoid scan(u32 &x) { cin >> x; }\nvoid scan(u64 &x) { cin\
    \ >> x; }\nvoid scan(i32 &x) { cin >> x; }\nvoid scan(i64 &x) { cin >> x; }\n\
    void scan(string &x) { cin >> x; }\ntemplate <typename T>\nvoid scan(V<T> &x)\
    \ {\n    for (T &ele : x) {\n        scan(ele);\n    }\n}\nvoid read() {}\ntemplate\
    \ <typename Head, typename... Tail>\nvoid read(Head &head, Tail &...tail) {\n\
    \    scan(head);\n    read(tail...);\n}\n#define CHAR(...)     \\\n    char __VA_ARGS__;\
    \ \\\n    read(__VA_ARGS__);\n#define U32(...)     \\\n    u32 __VA_ARGS__; \\\
    \n    read(__VA_ARGS__);\n#define U64(...)     \\\n    u64 __VA_ARGS__; \\\n \
    \   read(__VA_ARGS__);\n#define I32(...)     \\\n    i32 __VA_ARGS__; \\\n   \
    \ read(__VA_ARGS__);\n#define I64(...)     \\\n    i64 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n\
    #define STR(...)        \\\n    string __VA_ARGS__; \\\n    read(__VA_ARGS__);\n\
    #define VEC(type, name, size) \\\n    V<type> name(size);       \\\n    read(name);\n\
    #define VVEC(type, name, size1, size2)    \\\n    VV<type> name(size1, V<type>(size2));\
    \ \\\n    read(name);\n#line 5 \"graph/test/shortest_path.test.cpp\"\n\nvoid solve()\
    \ {\n    I32(n, m, s, t);\n    Graph<i64, true> g(n);\n    REP(i, m) {\n     \
    \   I32(a, b, c);\n        g.add_edge(a, b, c);\n    }\n    g.build();\n    auto\
    \ [dist, par] = dijkstra(g, s, INF64);\n    if (dist[t] == INF64) {\n        cout\
    \ << -1 << '\\n';\n    } else {\n        i64 x = dist[t];\n        V<i32> route;\n\
    \        i32 cur = t;\n        while (cur != s) {\n            route.push_back(cur);\n\
    \            cur = par[cur];\n        }\n        route.push_back(s);\n       \
    \ reverse(ALL(route));\n        i32 y = LEN(route) - 1;\n        cout << x <<\
    \ ' ' << y << '\\n';\n        REP(i, LEN(route) - 1) {\n            cout << route[i]\
    \ << ' ' << route[i + 1] << '\\n';\n        }\n    }\n}\n\nint main() {\n    i32\
    \ t = 1;\n    // cin >> t;\n    while (t--) {\n        solve();\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#define\
    \ FAST_IO\n#include \"../../graph/dijkstra.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nvoid solve() {\n    I32(n, m, s, t);\n    Graph<i64, true> g(n);\n    REP(i,\
    \ m) {\n        I32(a, b, c);\n        g.add_edge(a, b, c);\n    }\n    g.build();\n\
    \    auto [dist, par] = dijkstra(g, s, INF64);\n    if (dist[t] == INF64) {\n\
    \        cout << -1 << '\\n';\n    } else {\n        i64 x = dist[t];\n      \
    \  V<i32> route;\n        i32 cur = t;\n        while (cur != s) {\n         \
    \   route.push_back(cur);\n            cur = par[cur];\n        }\n        route.push_back(s);\n\
    \        reverse(ALL(route));\n        i32 y = LEN(route) - 1;\n        cout <<\
    \ x << ' ' << y << '\\n';\n        REP(i, LEN(route) - 1) {\n            cout\
    \ << route[i] << ' ' << route[i + 1] << '\\n';\n        }\n    }\n}\n\nint main()\
    \ {\n    i32 t = 1;\n    // cin >> t;\n    while (t--) {\n        solve();\n \
    \   }\n}\n"
  dependsOn:
  - graph/dijkstra.hpp
  - graph/graph.hpp
  - template/template.hpp
  isVerificationFile: true
  path: graph/test/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2024-01-13 18:43:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph/test/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/graph/test/shortest_path.test.cpp
- /verify/graph/test/shortest_path.test.cpp.html
title: graph/test/shortest_path.test.cpp
---