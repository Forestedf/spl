---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: data_structure/fenwick_tree.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/operations.hpp
    title: data_structure/operations.hpp
  - icon: ':heavy_check_mark:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: graph/heavy_light_decomposition.hpp
    title: graph/heavy_light_decomposition.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"graph/test/vertex_add_path_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n#define FAST_IO\n#line\
    \ 2 \"data_structure/fenwick_tree.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    #line 2 \"data_structure/operations.hpp\"\n\n#include <algorithm>\n#include <limits>\n\
    #include <utility>\n\ntemplate <typename T>\nstruct Add {\n    using Value = T;\n\
    \    static Value id() { return T(0); }\n    static Value op(const Value &lhs,\
    \ const Value &rhs) { return lhs + rhs; }\n    static Value inv(const Value &x)\
    \ { return -x; }\n};\n\ntemplate <typename T>\nstruct Mul {\n    using Value =\
    \ T;\n    static Value id() { return Value(1); }\n    static Value op(const Value\
    \ &lhs, const Value &rhs) { return lhs * rhs; }\n    static Value inv(const Value\
    \ &x) { return Value(1) / x; }\n};\n\ntemplate <typename T>\nstruct Min {\n  \
    \  static_assert(std::numeric_limits<T>::is_specialized);\n    using Value = T;\n\
    \    static Value id() { return std::numeric_limits<T>::max(); }\n    static Value\
    \ op(const Value &lhs, const Value &rhs) {\n        return std::min(lhs, rhs);\n\
    \    }\n};\n\ntemplate <typename T>\nstruct Max {\n    static_assert(std::numeric_limits<T>::is_specialized);\n\
    \    using Value = T;\n    static Value id() { return std::numeric_limits<Value>::min();\
    \ }\n    static Value op(const Value &lhs, const Value &rhs) {\n        return\
    \ std::max(lhs, rhs);\n    }\n};\n\ntemplate <typename T>\nstruct Xor {\n    using\
    \ Value = T;\n    static Value id() { return T(0); }\n    static Value op(const\
    \ Value &lhs, const Value &rhs) { return lhs ^ rhs; }\n    static Value inv(const\
    \ Value &x) { return x; }\n};\n\ntemplate <typename Monoid>\nstruct Reversible\
    \ {\n    using Value = std::pair<typename Monoid::Value, typename Monoid::Value>;\n\
    \    static Value id() { return Value(Monoid::id(), Monoid::id()); }\n    static\
    \ Value op(const Value &v1, const Value &v2) {\n        return Value(Monoid::op(v1.first,\
    \ v2.first),\n                     Monoid::op(v2.second, v1.second));\n    }\n\
    };\n#line 6 \"data_structure/fenwick_tree.hpp\"\n\ntemplate <typename CommutativeGroup>\n\
    class FenwickTree {\npublic:\n    using Value = typename CommutativeGroup::Value;\n\
    \nprivate:\n    std::vector<Value> data;\n\npublic:\n    FenwickTree(int n) :\
    \ data(n, CommutativeGroup::id()) {}\n\n    void add(int idx, const Value &x)\
    \ {\n        assert(idx >= 0 && idx < (int)data.size());\n        for (; idx <\
    \ (int)data.size(); idx |= idx + 1) {\n            data[idx] = CommutativeGroup::op(data[idx],\
    \ x);\n        }\n    }\n\n    Value sum(int r) const {\n        assert(r >= 0\
    \ && r <= (int)data.size());\n        Value ret = CommutativeGroup::id();\n  \
    \      for (; r > 0; r &= r - 1) {\n            ret = CommutativeGroup::op(ret,\
    \ data[r - 1]);\n        }\n        return ret;\n    }\n\n    Value sum(int l,\
    \ int r) const {\n        assert(l >= 0 && l <= r && r <= (int)data.size());\n\
    \        return CommutativeGroup::op(sum(r), CommutativeGroup::inv(sum(l)));\n\
    \    }\n};\n\ntemplate <typename T>\nusing FenwickTreeAdd = FenwickTree<Add<T>>;\n\
    #line 2 \"graph/graph.hpp\"\n#include <iostream>\n#line 5 \"graph/graph.hpp\"\n\
    template <typename T>\nstruct Edge {\n    using W = T;\n    int from, to, id;\n\
    \    W weight;\n};\ntemplate <typename T>\nvoid debug(const Edge<T> &e) {\n  \
    \  std::cerr << e.from << \" -> \" << e.to << \" id = \" << e.id << \" weight\
    \ = \";\n    debug(e.weight);\n}\ntemplate <typename T = int, bool DIR = false>\n\
    class Graph {\npublic:\n    using E = Edge<T>;\n    using W = T;\n    static constexpr\
    \ bool DIRECTED = DIR;\n    struct Adjacency {\n        using Iter = typename\
    \ std::vector<E>::iterator;\n        Iter be, en;\n        Iter begin() const\
    \ { return be; }\n        Iter end() const { return en; }\n        int size()\
    \ const { return (int)std::distance(be, en); }\n        E &operator[](int idx)\
    \ const { return be[idx]; }\n    };\n    struct ConstAdjacency {\n        using\
    \ Iter = typename std::vector<E>::const_iterator;\n        Iter be, en;\n    \
    \    Iter begin() const { return be; }\n        Iter end() const { return en;\
    \ }\n        int size() const { return (int)std::distance(be, en); }\n       \
    \ const E &operator[](int idx) const { return be[idx]; }\n    };\n\nprivate:\n\
    \    int n, m;\n    std::vector<E> edges, csr;\n    std::vector<int> sep;\n  \
    \  bool built;\n\npublic:\n    Graph(int n) : n(n), m(0), built(false) {}\n  \
    \  int v() const { return n; }\n    int e() const { return m; }\n    void add_edge(int\
    \ from, int to, W weight = 1) {\n        assert(0 <= from && from < n && 0 <=\
    \ to && to < n);\n        edges.emplace_back(E{from, to, m++, weight});\n    }\n\
    \    void build() {\n        sep.assign(n + 1, 0);\n        csr.resize(DIRECTED\
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
    \ + sep[v], csr.begin() + sep[v + 1]};\n    }\n};\n#line 5 \"graph/heavy_light_decomposition.hpp\"\
    \nclass HeavyLightDecomposition {\npublic:\n    std::vector<int> siz, par, hea,\
    \ in, out, dep, rev;\n\nprivate:\n    template <typename T, bool DIR>\n    void\
    \ dfs1(Graph<T, DIR> &g, int v) {\n        if (g[v].size() >= 1 && g[v][0].to\
    \ == par[v]) {\n            std::swap(g[v][0], g[v][g[v].size() - 1]);\n     \
    \   }\n        for (Edge<T> &e : g[v]) {\n            if (e.to != par[v]) {\n\
    \                par[e.to] = v;\n                dfs1(g, e.to);\n            \
    \    siz[v] += siz[e.to];\n                if (siz[e.to] > siz[g[v][0].to]) {\n\
    \                    std::swap(g[v][0], e);\n                }\n            }\n\
    \        }\n    }\n    template <typename T, bool DIR>\n    void dfs2(const Graph<T,\
    \ DIR> &g, int v, int &t) {\n        in[v] = t;\n        rev[t++] = v;\n     \
    \   for (const Edge<T> &e : g[v]) {\n            if (e.to == par[v]) {\n     \
    \           continue;\n            }\n            if (e.to == g[v][0].to) {\n\
    \                hea[e.to] = hea[v];\n            } else {\n                hea[e.to]\
    \ = e.to;\n            }\n            dep[e.to] = dep[v] + 1;\n            dfs2(g,\
    \ e.to, t);\n        }\n        out[v] = t;\n    }\n\npublic:\n    template <typename\
    \ T, bool DIR>\n    HeavyLightDecomposition(Graph<T, DIR> &g, int root = 0)\n\
    \        : siz(g.v(), 1),\n          par(g.v(), root),\n          hea(g.v(), root),\n\
    \          in(g.v(), 0),\n          out(g.v(), 0),\n          dep(g.v(), 0),\n\
    \          rev(g.v(), 0) {\n        assert(0 <= root && root < g.v());\n     \
    \   dfs1(g, root);\n        int t = 0;\n        dfs2(g, root, t);\n    }\n   \
    \ // par^k\n    int la(int v, int k) const {\n        assert(0 <= v && v < (int)dep.size());\n\
    \        assert(k >= 0);\n        if (k > dep[v]) {\n            return -1;\n\
    \        }\n        while (true) {\n            int u = hea[v];\n            if\
    \ (in[u] + k <= in[v]) {\n                return rev[in[v] - k];\n           \
    \ }\n            k -= in[v] - in[u] + 1;\n            v = par[u];\n        }\n\
    \        return 0;\n    }\n    int lca(int u, int v) const {\n        assert(0\
    \ <= u && u < (int)dep.size());\n        assert(0 <= v && v < (int)dep.size());\n\
    \        while (u != v) {\n            if (in[u] > in[v]) {\n                std::swap(u,\
    \ v);\n            }\n            if (hea[u] == hea[v]) {\n                v =\
    \ u;\n            } else {\n                v = par[hea[v]];\n            }\n\
    \        }\n        return u;\n    }\n    int dist(int u, int v) const {\n   \
    \     assert(0 <= u && u < (int)dep.size());\n        assert(0 <= v && v < (int)dep.size());\n\
    \        return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n    }\n    int jump(int\
    \ u, int v, int k) const {\n        assert(0 <= u && u < (int)dep.size());\n \
    \       assert(0 <= v && v < (int)dep.size());\n        assert(k >= 0);\n    \
    \    int l = lca(u, v);\n        int dis = dep[u] + dep[v] - 2 * dep[l];\n   \
    \     if (k > dis) {\n            return -1;\n        }\n        if (k <= dep[u]\
    \ - dep[l]) {\n            return la(u, k);\n        } else {\n            return\
    \ la(v, dis - k);\n        }\n    }\n    int meet(int u, int v, int w) const {\n\
    \        return lca(u, v) ^ lca(v, w) ^ lca(w, u);\n    }\n    std::vector<std::pair<int,\
    \ int>> path(int u, int v, bool edge) const {\n        assert(0 <= u && u < (int)dep.size());\n\
    \        assert(0 <= v && v < (int)dep.size());\n        std::vector<std::pair<int,\
    \ int>> fromu, fromv;\n        bool rev = false;\n        while (true) {\n   \
    \         if (u == v && edge) {\n                break;\n            }\n     \
    \       if (in[u] > in[v]) {\n                std::swap(u, v);\n             \
    \   std::swap(fromu, fromv);\n                rev ^= true;\n            }\n  \
    \          if (hea[u] == hea[v]) {\n                fromv.emplace_back(in[v],\
    \ in[u] + (int)edge);\n                v = u;\n                break;\n      \
    \      } else {\n                fromv.emplace_back(in[v], in[hea[v]]);\n    \
    \            v = par[hea[v]];\n            }\n        }\n        if (rev) {\n\
    \            std::swap(fromu, fromv);\n        }\n        std::reverse(fromv.begin(),\
    \ fromv.end());\n        fromu.reserve(fromv.size());\n        for (auto [x, y]\
    \ : fromv) {\n            fromu.emplace_back(y, x);\n        }\n        return\
    \ fromu;\n    }\n};\n#line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\n\
    #define OVERRIDE(a, b, c, d, ...) d\n#define REP2(i, n) for (i32 i = 0; i < (i32)(n);\
    \ ++i)\n#define REP3(i, m, n) for (i32 i = (i32)(m); i < (i32)(n); ++i)\n#define\
    \ REP(...) OVERRIDE(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)\n#define PER2(i, n)\
    \ for (i32 i = (i32)(n)-1; i >= 0; --i)\n#define PER3(i, m, n) for (i32 i = (i32)(n)-1;\
    \ i >= (i32)(m); --i)\n#define PER(...) OVERRIDE(__VA_ARGS__, PER3, PER2)(__VA_ARGS__)\n\
    #define ALL(x) begin(x), end(x)\n#define LEN(x) (i32)(x.size())\nusing namespace\
    \ std;\nusing u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i32\
    \ = signed int;\nusing i64 = signed long long;\nusing f64 = double;\nusing f80\
    \ = long double;\nusing pi = pair<i32, i32>;\nusing pl = pair<i64, i64>;\ntemplate\
    \ <typename T>\nusing V = vector<T>;\ntemplate <typename T>\nusing VV = V<V<T>>;\n\
    template <typename T>\nusing VVV = V<V<V<T>>>;\ntemplate <typename T>\nusing VVVV\
    \ = V<V<V<V<T>>>>;\ntemplate <typename T>\nusing PQR = priority_queue<T, V<T>,\
    \ greater<T>>;\ntemplate <typename T>\nbool chmin(T &x, const T &y) {\n    if\
    \ (x > y) {\n        x = y;\n        return true;\n    }\n    return false;\n\
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
    #line 6 \"graph/test/vertex_add_path_sum.test.cpp\"\n\nvoid solve() {\n    I32(n,\
    \ q);\n    VEC(i32, a, n);\n    Graph<> g(n);\n    REP(i, n - 1) {\n        I32(u,\
    \ v);\n        g.add_edge(u, v);\n    }\n    g.build();\n    HeavyLightDecomposition\
    \ hld(g);\n    FenwickTreeAdd<i64> fw(n);\n    REP(i, n) {\n        fw.add(hld.in[i],\
    \ a[i]);\n    }\n    REP(qi, q) {\n        I32(type);\n        if (type == 0)\
    \ {\n            I32(p, x);\n            fw.add(hld.in[p], x);\n        } else\
    \ {\n            I32(u, v);\n            i64 ans = 0;\n            for (auto [x,\
    \ y] : hld.path(u, v, false)) {\n                if (x > y) {\n              \
    \      swap(x, y);\n                }\n                ans += fw.sum(x, y + 1);\n\
    \            }\n            cout << ans << '\\n';\n        }\n    }\n}\n\nint\
    \ main() {\n    i32 t = 1;\n    // cin >> t;\n    while (t--) {\n        solve();\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    #define FAST_IO\n#include \"../../data_structure/fenwick_tree.hpp\"\n#include\
    \ \"../../graph/heavy_light_decomposition.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nvoid solve() {\n    I32(n, q);\n    VEC(i32, a, n);\n    Graph<> g(n);\n \
    \   REP(i, n - 1) {\n        I32(u, v);\n        g.add_edge(u, v);\n    }\n  \
    \  g.build();\n    HeavyLightDecomposition hld(g);\n    FenwickTreeAdd<i64> fw(n);\n\
    \    REP(i, n) {\n        fw.add(hld.in[i], a[i]);\n    }\n    REP(qi, q) {\n\
    \        I32(type);\n        if (type == 0) {\n            I32(p, x);\n      \
    \      fw.add(hld.in[p], x);\n        } else {\n            I32(u, v);\n     \
    \       i64 ans = 0;\n            for (auto [x, y] : hld.path(u, v, false)) {\n\
    \                if (x > y) {\n                    swap(x, y);\n             \
    \   }\n                ans += fw.sum(x, y + 1);\n            }\n            cout\
    \ << ans << '\\n';\n        }\n    }\n}\n\nint main() {\n    i32 t = 1;\n    //\
    \ cin >> t;\n    while (t--) {\n        solve();\n    }\n}"
  dependsOn:
  - data_structure/fenwick_tree.hpp
  - data_structure/operations.hpp
  - graph/heavy_light_decomposition.hpp
  - graph/graph.hpp
  - template/template.hpp
  isVerificationFile: true
  path: graph/test/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-13 18:43:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph/test/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/graph/test/vertex_add_path_sum.test.cpp
- /verify/graph/test/vertex_add_path_sum.test.cpp.html
title: graph/test/vertex_add_path_sum.test.cpp
---
