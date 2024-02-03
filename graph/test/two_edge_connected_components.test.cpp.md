---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: graph/two_edge_connected_components.hpp
    title: graph/two_edge_connected_components.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"graph/test/two_edge_connected_components.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\n\
    #define FAST_IO\n#line 2 \"graph/graph.hpp\"\n#include <iostream>\n#include <cassert>\n\
    #include <vector>\ntemplate <typename T>\nstruct Edge {\n    using W = T;\n  \
    \  int from, to, id;\n    W weight;\n    Edge<T> rev() const {\n        return\
    \ Edge<T>{to, from, id, weight};\n    }\n};\ntemplate <typename T>\nvoid debug(const\
    \ Edge<T> &e) {\n    std::cerr << e.from << \" -> \" << e.to << \" id = \" <<\
    \ e.id << std::cerr << \" weight = \";\n    debug(e.weight);\n}\ntemplate <typename\
    \ T = int, bool DIR = false>\nclass Graph {\npublic:\n    using E = Edge<T>;\n\
    \    using W = T;\n    static constexpr bool DIRECTED = DIR;\n    struct Adjacency\
    \ {\n        using Iter = typename std::vector<E>::iterator;\n        Iter be,\
    \ en;\n        Iter begin() const { return be; }\n        Iter end() const { return\
    \ en; }\n        int size() const { return (int)std::distance(be, en); }\n   \
    \     E &operator[](int idx) const { return be[idx]; }\n    };\n    struct ConstAdjacency\
    \ {\n        using Iter = typename std::vector<E>::const_iterator;\n        Iter\
    \ be, en;\n        Iter begin() const { return be; }\n        Iter end() const\
    \ { return en; }\n        int size() const { return (int)std::distance(be, en);\
    \ }\n        const E &operator[](int idx) const { return be[idx]; }\n    };\n\n\
    private:\n    int n, m;\n    std::vector<E> edges, csr;\n    std::vector<int>\
    \ sep;\n    bool built;\n\npublic:\n    Graph(int n) : n(n), m(0), built(false)\
    \ {}\n    int v() const { return n; }\n    int e() const { return m; }\n    int\
    \ add_vertex() {\n        return n++;\n    }\n    void add_edge(int from, int\
    \ to, W weight = 1) {\n        assert(0 <= from && from < n && 0 <= to && to <\
    \ n);\n        edges.emplace_back(E{from, to, m++, weight});\n    }\n    void\
    \ build() {\n        sep.assign(n + 1, 0);\n        csr.resize(DIRECTED ? m :\
    \ 2 * m);\n        for (const E &e : edges) {\n            ++sep[e.from + 1];\n\
    \            if (!DIRECTED) {\n                ++sep[e.to + 1];\n            }\n\
    \        }\n        for (int i = 0; i < n; ++i) {\n            sep[i + 1] += sep[i];\n\
    \        }\n        std::vector<int> c = sep;\n        for (const E &e : edges)\
    \ {\n            csr[c[e.from]++] = e;\n            if (!DIRECTED) {\n       \
    \         csr[c[e.to]++] = e.rev();\n            }\n        }\n        built =\
    \ true;\n    }\n    Adjacency operator[](int v) {\n        assert(built && 0 <=\
    \ v && v < n);\n        return Adjacency{csr.begin() + sep[v], csr.begin() + sep[v\
    \ + 1]};\n    }\n    ConstAdjacency operator[](int v) const {\n        assert(built\
    \ && 0 <= v && v < n);\n        return ConstAdjacency{csr.begin() + sep[v], csr.begin()\
    \ + sep[v + 1]};\n    }\n};\n#line 3 \"graph/two_edge_connected_components.hpp\"\
    \ntemplate <typename T>\nstd::vector<int> two_edge_connected_components(const\
    \ Graph<T> &g) {\n    std::vector<int> comp(g.v(), -1);\n    int cc = 0;\n   \
    \ std::vector<int> ord(g.v(), -1), low(g.v(), -1), vs;\n    int t = 0;\n    auto\
    \ dfs = [&](auto dfs, int v, int p) -> void {\n        ord[v] = low[v] = t++;\n\
    \        vs.push_back(v);\n        bool pf = false;\n        for (const Edge<T>\
    \ &e : g[v]) {\n            if (ord[e.to] == -1) {\n                dfs(dfs, e.to,\
    \ v);\n                if (low[e.to] < low[v]) {\n                    low[v] =\
    \ low[e.to];\n                }\n            } else if (e.to == p && !pf) {\n\
    \                pf = true;\n            } else {\n                if (ord[e.to]\
    \ < low[v]) {\n                    low[v] = ord[e.to];\n                }\n  \
    \          }\n        }\n        if (ord[v] == low[v]) {\n            while (comp[v]\
    \ == -1) {\n                comp[vs.back()] = cc;\n                vs.pop_back();\n\
    \            }\n            ++cc;\n        }\n    };\n    for (int i = 0; i <\
    \ g.v(); ++i) {\n        if (comp[i] == -1) {\n            dfs(dfs, i, -1);\n\
    \        }\n    }\n    return comp;\n}\n#line 1 \"template/template.hpp\"\n#include\
    \ <bits/stdc++.h>\n#define OVERRIDE(a, b, c, d, ...) d\n#define REP2(i, n) for\
    \ (i32 i = 0; i < (i32)(n); ++i)\n#define REP3(i, m, n) for (i32 i = (i32)(m);\
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
    #line 5 \"graph/test/two_edge_connected_components.test.cpp\"\n\nvoid solve()\
    \ {\n    I32(n, m);\n    Graph<> g(n);\n    REP(i, m) {\n        I32(u, v);\n\
    \        g.add_edge(u, v);\n    }\n    g.build();\n    V<i32> comp = two_edge_connected_components(g);\n\
    \    VV<i32> groups(n);\n    REP(i, n) { groups[comp[i]].push_back(i); }\n   \
    \ while (groups.back().empty()) {\n        groups.pop_back();\n    }\n    cout\
    \ << LEN(groups) << '\\n';\n    for (const V<i32> &gr : groups) {\n        cout\
    \ << LEN(gr);\n        for (i32 v : gr) {\n            cout << ' ' << v;\n   \
    \     }\n        cout << '\\n';\n    }\n}\n\nint main() {\n    i32 t = 1;\n  \
    \  // cin >> t;\n    while (t--) {\n        solve();\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n#define FAST_IO\n#include \"../../graph/two_edge_connected_components.hpp\"\n\
    #include \"../../template/template.hpp\"\n\nvoid solve() {\n    I32(n, m);\n \
    \   Graph<> g(n);\n    REP(i, m) {\n        I32(u, v);\n        g.add_edge(u,\
    \ v);\n    }\n    g.build();\n    V<i32> comp = two_edge_connected_components(g);\n\
    \    VV<i32> groups(n);\n    REP(i, n) { groups[comp[i]].push_back(i); }\n   \
    \ while (groups.back().empty()) {\n        groups.pop_back();\n    }\n    cout\
    \ << LEN(groups) << '\\n';\n    for (const V<i32> &gr : groups) {\n        cout\
    \ << LEN(gr);\n        for (i32 v : gr) {\n            cout << ' ' << v;\n   \
    \     }\n        cout << '\\n';\n    }\n}\n\nint main() {\n    i32 t = 1;\n  \
    \  // cin >> t;\n    while (t--) {\n        solve();\n    }\n}"
  dependsOn:
  - graph/two_edge_connected_components.hpp
  - graph/graph.hpp
  - template/template.hpp
  isVerificationFile: true
  path: graph/test/two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2024-02-03 17:22:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph/test/two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/graph/test/two_edge_connected_components.test.cpp
- /verify/graph/test/two_edge_connected_components.test.cpp.html
title: graph/test/two_edge_connected_components.test.cpp
---
