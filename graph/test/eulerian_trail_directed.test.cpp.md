---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/eulerian_trail.hpp
    title: graph/eulerian_trail.hpp
  - icon: ':heavy_check_mark:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: template/fastio.hpp
    title: template/fastio.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/eulerian_trail_directed
    links:
    - https://judge.yosupo.jp/problem/eulerian_trail_directed
  bundledCode: "#line 1 \"graph/test/eulerian_trail_directed.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/eulerian_trail_directed\"\n#define FAST_IO\n\
    #line 2 \"graph/eulerian_trail.hpp\"\n#include <algorithm>\n#include <utility>\n\
    #line 2 \"graph/graph.hpp\"\n#include <iostream>\n#include <cassert>\n#include\
    \ <vector>\ntemplate <typename T>\nstruct Edge {\n    using W = T;\n    int from,\
    \ to, id;\n    W weight;\n    Edge<T> rev() const {\n        return Edge<T>{to,\
    \ from, id, weight};\n    }\n};\ntemplate <typename T>\nvoid debug(const Edge<T>\
    \ &e) {\n    std::cerr << e.from << \" -> \" << e.to << \" id = \" << e.id <<\
    \ std::cerr << \" weight = \";\n    debug(e.weight);\n}\ntemplate <typename T\
    \ = int, bool DIR = false>\nclass Graph {\npublic:\n    using E = Edge<T>;\n \
    \   using W = T;\n    static constexpr bool DIRECTED = DIR;\n    struct Adjacency\
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
    \ + sep[v + 1]};\n    }\n};\n#line 5 \"graph/eulerian_trail.hpp\"\n\ntemplate\
    \ <typename T>\nstd::pair<std::vector<int>, std::vector<int>> eulerian_trail_directed(\n\
    \    const Graph<T, true> &g) {\n    assert(g.v() >= 1);\n    std::vector<int>\
    \ vs, es;\n    std::vector<int> itr(g.v(), 0);\n    auto dfs = [&](auto dfs, int\
    \ v) -> void {\n        while (itr[v] < g[v].size()) {\n            const Edge<T>\
    \ &e = g[v][itr[v]++];\n            dfs(dfs, e.to);\n            vs.push_back(e.to);\n\
    \            es.push_back(e.id);\n        }\n    };\n\n    std::vector<int> flux(g.v(),\
    \ 0);\n    for (int i = 0; i < g.v(); ++i) {\n        flux[i] += g[i].size();\n\
    \        for (auto e : g[i]) {\n            --flux[e.to];\n        }\n    }\n\
    \    int st = -1;\n    for (int i = 0; i < g.v(); ++i) {\n        if (flux[i]\
    \ == 1) {\n            if (st != -1) {\n                // no eulerian trail\n\
    \                return std::make_pair(vs, es);\n            }\n            st\
    \ = i;\n        }\n        if (flux[i] >= 2) {\n            // no eulerian trail\n\
    \            return std::make_pair(vs, es);\n        }\n    }\n    if (st == -1)\
    \ {\n        for (int i = 0; i < g.v(); ++i) {\n            if (g[i].size() >\
    \ 0) {\n                st = i;\n            }\n        }\n    }\n    if (st ==\
    \ -1) {\n        // no edge\n        vs.push_back(0);\n        return std::make_pair(vs,\
    \ es);\n    }\n\n    vs.reserve(g.e() + 1);\n    es.reserve(g.e());\n    dfs(dfs,\
    \ st);\n    if ((int)es.size() != g.e()) {\n        return std::make_pair(std::vector<int>(),\
    \ std::vector<int>());\n    }\n    vs.push_back(st);\n    std::reverse(vs.begin(),\
    \ vs.end());\n    std::reverse(es.begin(), es.end());\n    return std::make_pair(vs,\
    \ es);\n}\n\ntemplate <typename T>\nstd::pair<std::vector<int>, std::vector<int>>\
    \ eulerian_trail_undirected(\n    const Graph<T, false> &g) {\n    assert(g.v()\
    \ >= 1);\n    std::vector<int> vs, es;\n\n    int st = -1;\n    int cnt = 0;\n\
    \    for (int i = 0; i < g.v(); ++i) {\n        int deg = g[i].size();\n     \
    \   if (deg % 2 == 1) {\n            ++cnt;\n            st = i;\n        }\n\
    \    }\n    if (cnt >= 3) {\n        // no eulerian trail\n        return std::make_pair(std::vector<int>(),\
    \ std::vector<int>());\n    }\n    if (st == -1) {\n        for (int i = 0; i\
    \ < g.v(); ++i) {\n            if (g[i].size() > 0) {\n                st = i;\n\
    \            }\n        }\n    }\n    if (st == -1) {\n        // no edge\n  \
    \      vs.push_back(0);\n        return std::make_pair(vs, es);\n    }\n\n   \
    \ std::vector<int> itr(g.v(), 0), used(g.e(), 0);\n    auto dfs = [&](auto dfs,\
    \ int v) -> void {\n        while (itr[v] < g[v].size()) {\n            const\
    \ Edge<T> &e = g[v][itr[v]++];\n            if (std::exchange(used[e.id], 1))\
    \ {\n                continue;\n            }\n            dfs(dfs, e.to);\n \
    \           vs.push_back(e.to);\n            es.push_back(e.id);\n        }\n\
    \    };\n\n    vs.reserve(g.e() + 1);\n    es.reserve(g.e());\n    dfs(dfs, st);\n\
    \    if ((int)es.size() != g.e()) {\n        return std::make_pair(std::vector<int>(),\
    \ std::vector<int>());\n    }\n    vs.push_back(st);\n    std::reverse(vs.begin(),\
    \ vs.end());\n    std::reverse(es.begin(), es.end());\n    return std::make_pair(vs,\
    \ es);\n}\n\n// (vs, es)\ntemplate <typename T, bool DIR>\nstd::pair<std::vector<int>,\
    \ std::vector<int>> eulerian_trail(\n    const Graph<T, DIR> &g) {\n    if constexpr\
    \ (DIR) {\n        return eulerian_trail_directed(g);\n    } else {\n        return\
    \ eulerian_trail_undirected(g);\n    }\n}\n#line 2 \"template/template.hpp\"\n\
    #include <bits/stdc++.h>\n#define OVERRIDE(a, b, c, d, ...) d\n#define REP2(i,\
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
    void scan(i64 &x) { cin >> x; }\nvoid scan(f64 &x) { cin >> x; }\nvoid scan(string\
    \ &x) { cin >> x; }\ntemplate <typename T>\nvoid scan(V<T> &x) {\n    for (T &ele\
    \ : x) {\n        scan(ele);\n    }\n}\nvoid read() {}\ntemplate <typename Head,\
    \ typename... Tail>\nvoid read(Head &head, Tail &...tail) {\n    scan(head);\n\
    \    read(tail...);\n}\n#define CHAR(...)     \\\n    char __VA_ARGS__; \\\n \
    \   read(__VA_ARGS__);\n#define U32(...)     \\\n    u32 __VA_ARGS__; \\\n   \
    \ read(__VA_ARGS__);\n#define U64(...)     \\\n    u64 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n\
    #define I32(...)     \\\n    i32 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define\
    \ I64(...)     \\\n    i64 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define F64(...)\
    \     \\\n    f64 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define STR(...)  \
    \      \\\n    string __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define VEC(type,\
    \ name, size) \\\n    V<type> name(size);       \\\n    read(name);\n#define VVEC(type,\
    \ name, size1, size2)    \\\n    VV<type> name(size1, V<type>(size2)); \\\n  \
    \  read(name);\n#line 4 \"template/fastio.hpp\"\n#include <type_traits>\n#line\
    \ 6 \"template/fastio.hpp\"\n\n// unable to read INT_MIN (int), LLONG_MIN (long\
    \ long)\nclass Reader {\n    FILE *fp;\n    static constexpr int BUF = 1 << 18;\n\
    \    char buf[BUF];\n    char *pl, *pr;\n\n    void reread() {\n        int wd\
    \ = pr - pl;\n        std::memcpy(buf, pl, wd);\n        pl = buf;\n        pr\
    \ = buf + wd;\n        pr += std::fread(pr, 1, BUF - wd, fp);\n    }\n\n    char\
    \ skip() {\n        char ch = *pl++;\n        while (ch <= ' ') {\n          \
    \  ch = *pl++;\n        }\n        return ch;\n    }\n\n    template <typename\
    \ T>\n    void read_unsigned(T &x) {\n        if (pr - pl < 64) {\n          \
    \  reread();\n        }\n        x = 0;\n        char ch = skip();\n        while\
    \ ('0' <= ch) {\n            x = 10 * x + (0xf & ch);\n            ch = *pl++;\n\
    \        }\n    }\n    template <typename T>\n    void read_signed(T &x) {\n \
    \       if (pr - pl < 64) {\n            reread();\n        }\n        x = 0;\n\
    \        bool neg = false;\n        char ch = skip();\n        if (ch == '-')\
    \ {\n            ch = *pl++;\n            neg = true;\n        }\n        while\
    \ ('0' <= ch) {\n            x = 10 * x + (0xf & ch);\n            ch = *pl++;\n\
    \        }\n        if (neg) {\n            x = -x;\n        }\n    }\n\n    void\
    \ read_single(int &x) { read_signed(x); }\n    void read_single(unsigned &x) {\
    \ read_unsigned(x); }\n    void read_single(long &x) { read_signed(x); }\n   \
    \ void read_single(unsigned long &x) { read_signed(x); }\n    void read_single(long\
    \ long &x) { read_signed(x); }\n    void read_single(unsigned long long &x) {\
    \ read_unsigned(x); }\n\npublic:\n    Reader(FILE *fp) : fp(fp), pl(buf), pr(buf)\
    \ { reread(); }\n\n    void read() {}\n    template <typename Head, typename...\
    \ Tail>\n    void read(Head &head, Tail &...tail) {\n        read_single(head);\n\
    \        read(tail...);\n    }\n};\n\nstruct NumberToString {\n    char buf[10000][4];\n\
    \    constexpr NumberToString() : buf() {\n        for (int i = 0; i < 10000;\
    \ ++i) {\n            int n = i;\n            for (int j = 3; j >= 0; --j) {\n\
    \                buf[i][j] = '0' + n % 10;\n                n /= 10;\n       \
    \     }\n        }\n    }\n} constexpr number_to_string_precalc;\n\nclass Writer\
    \ {\n    FILE *fp;\n    static constexpr int BUF = 1 << 18;\n    char buf[BUF];\n\
    \    char *ptr;\n\n    void write_u32(unsigned x) {\n        if ((buf + BUF -\
    \ ptr) < 32) {\n            flush();\n        }\n        static char sml[12];\n\
    \        int t = 8;\n        while (x >= 10000) {\n            unsigned n = x\
    \ % 10000;\n            x /= 10000;\n            std::memcpy(sml + t, number_to_string_precalc.buf[n],\
    \ 4);\n            t -= 4;\n        }\n        if (x >= 1000) {\n            std::memcpy(ptr,\
    \ number_to_string_precalc.buf[x], 4);\n            ptr += 4;\n        } else\
    \ if (x >= 100) {\n            std::memcpy(ptr, number_to_string_precalc.buf[x]\
    \ + 1, 3);\n            ptr += 3;\n        } else if (x >= 10) {\n           \
    \ unsigned q = (x * 103) >> 10;\n            *ptr++ = q | '0';\n            *ptr++\
    \ = (x - 10 * q) | '0';\n        } else {\n            *ptr++ = '0' | x;\n   \
    \     }\n        std::memcpy(ptr, sml + (t + 4), 8 - t);\n        ptr += 8 - t;\n\
    \    }\n\n    void write_u64(unsigned long long x) {\n        if ((buf + BUF -\
    \ ptr) < 32) {\n            flush();\n        }\n        if (x >= 10000000000000000)\
    \ {\n            unsigned long long z = x % 100000000;\n            x /= 100000000;\n\
    \            unsigned long long y = x % 100000000;\n            x /= 100000000;\n\
    \            if (x >= 1000) {\n                std::memcpy(ptr, number_to_string_precalc.buf[x],\
    \ 4);\n                ptr += 4;\n            } else if (x >= 100) {\n       \
    \         std::memcpy(ptr, number_to_string_precalc.buf[x] + 1, 3);\n        \
    \        ptr += 3;\n            } else if (x >= 10) {\n                unsigned\
    \ q = (x * 103) >> 10;\n                *ptr++ = q | '0';\n                *ptr++\
    \ = (x - 10 * q) | '0';\n            } else {\n                *ptr++ = '0' |\
    \ x;\n            }\n            std::memcpy(ptr, number_to_string_precalc.buf[y\
    \ / 10000], 4);\n            std::memcpy(ptr + 4, number_to_string_precalc.buf[y\
    \ % 10000], 4);\n            std::memcpy(ptr + 8, number_to_string_precalc.buf[z\
    \ / 10000], 4);\n            std::memcpy(ptr + 12, number_to_string_precalc.buf[z\
    \ % 10000], 4);\n            ptr += 16;\n        } else {\n            static\
    \ char sml[12];\n            int t = 8;\n            while (x >= 10000) {\n  \
    \              unsigned long long n = x % 10000;\n                x /= 10000;\n\
    \                std::memcpy(sml + t, number_to_string_precalc.buf[n], 4);\n \
    \               t -= 4;\n            }\n            if (x >= 1000) {\n       \
    \         std::memcpy(ptr, number_to_string_precalc.buf[x], 4);\n            \
    \    ptr += 4;\n            } else if (x >= 100) {\n                std::memcpy(ptr,\
    \ number_to_string_precalc.buf[x] + 1, 3);\n                ptr += 3;\n      \
    \      } else if (x >= 10) {\n                unsigned q = (x * 103) >> 10;\n\
    \                *ptr++ = q | '0';\n                *ptr++ = (x - 10 * q) | '0';\n\
    \            } else {\n                *ptr++ = '0' | x;\n            }\n    \
    \        std::memcpy(ptr, sml + (t + 4), 8 - t);\n            ptr += 8 - t;\n\
    \        }\n    }\n\n    void write_char(char c) {\n        if (ptr == buf + BUF)\
    \ {\n            flush();\n        }\n        *ptr++ = c;\n    }\n\n    template\
    \ <typename T>\n    void write_unsigned(T x) {\n        if constexpr (std::is_same_v<T,\
    \ unsigned long long> ||\n                      std::is_same_v<T, unsigned long>)\
    \ {\n            write_u64(x);\n        } else {\n            write_u32(x);\n\
    \        }\n    }\n\n    template <typename T>\n    void write_signed(T x) {\n\
    \        std::make_unsigned_t<T> y = x;\n        if (x < 0) {\n            write_char('-');\n\
    \            y = -y;\n        }\n        write_unsigned(y);\n    }\n    \n   \
    \ void write_string(const std::string &s) {\n        for (char c : s) {\n    \
    \        write_char(c);\n        }\n    }\n\n    void write_single(int x) { write_signed(x);\
    \ }\n    void write_single(unsigned x) { write_unsigned(x); }\n    void write_single(long\
    \ x) { write_signed(x); }\n    void write_single(unsigned long x) { write_unsigned(x);\
    \ }\n    void write_single(long long x) { write_signed(x); }\n    void write_single(unsigned\
    \ long long x) { write_unsigned(x); }\n    void write_single(char c) { write_char(c);\
    \ }\n    void write_single(const std::string &s) { write_string(s); }\n\npublic:\n\
    \    Writer(FILE *fp) : fp(fp), ptr(buf) {}\n    ~Writer() { flush(); }\n\n  \
    \  void flush() {\n        std::fwrite(buf, 1, ptr - buf, fp);\n        ptr =\
    \ buf;\n    }\n\n    void write() {}\n    template <typename Head, typename...\
    \ Tail>\n    void write(Head &&head, Tail &&...tail) {\n        write_single(head);\n\
    \        if (sizeof...(Tail)) {\n            write_char(' ');\n        }\n   \
    \     write(std::forward<Tail>(tail)...);\n    }\n\n    template <typename...\
    \ T>\n    void writeln(T &&...t) {\n        write(std::forward<T>(t)...);\n  \
    \      write_char('\\n');\n    }\n};\n\nReader rd(stdin);\nWriter wr(stdout);\n\
    #line 6 \"graph/test/eulerian_trail_directed.test.cpp\"\n\nvoid solve() {\n  \
    \  i32 n, m;\n    rd.read(n, m);\n    Graph<i32, 1> g(n);\n    REP(i, m) {\n \
    \       i32 u, v;\n        rd.read(u, v);\n        g.add_edge(u, v);\n    }\n\
    \    g.build();\n    auto [vs, es] = eulerian_trail(g);\n    if (vs.empty()) {\n\
    \        wr.writeln(\"No\");\n    } else {\n        wr.writeln(\"Yes\");\n   \
    \     REP(i, m + 1) {\n            wr.write(vs[i]);\n            wr.write(\" \\\
    n\"[i == m]);\n        }\n        REP(i, m) {\n            wr.write(es[i]);\n\
    \            wr.write(\" \\n\"[i == m - 1]);\n        }\n        if (m == 0) {\n\
    \            wr.writeln();\n        }\n    }\n}\n\nint main() {\n    i32 t;\n\
    \    rd.read(t);\n    while (t--) {\n        solve();\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/eulerian_trail_directed\"\
    \n#define FAST_IO\n#include \"../../graph/eulerian_trail.hpp\"\n#include \"../../template/template.hpp\"\
    \n#include \"../../template/fastio.hpp\"\n\nvoid solve() {\n    i32 n, m;\n  \
    \  rd.read(n, m);\n    Graph<i32, 1> g(n);\n    REP(i, m) {\n        i32 u, v;\n\
    \        rd.read(u, v);\n        g.add_edge(u, v);\n    }\n    g.build();\n  \
    \  auto [vs, es] = eulerian_trail(g);\n    if (vs.empty()) {\n        wr.writeln(\"\
    No\");\n    } else {\n        wr.writeln(\"Yes\");\n        REP(i, m + 1) {\n\
    \            wr.write(vs[i]);\n            wr.write(\" \\n\"[i == m]);\n     \
    \   }\n        REP(i, m) {\n            wr.write(es[i]);\n            wr.write(\"\
    \ \\n\"[i == m - 1]);\n        }\n        if (m == 0) {\n            wr.writeln();\n\
    \        }\n    }\n}\n\nint main() {\n    i32 t;\n    rd.read(t);\n    while (t--)\
    \ {\n        solve();\n    }\n}\n"
  dependsOn:
  - graph/eulerian_trail.hpp
  - graph/graph.hpp
  - template/template.hpp
  - template/fastio.hpp
  isVerificationFile: true
  path: graph/test/eulerian_trail_directed.test.cpp
  requiredBy: []
  timestamp: '2025-09-14 09:21:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph/test/eulerian_trail_directed.test.cpp
layout: document
redirect_from:
- /verify/graph/test/eulerian_trail_directed.test.cpp
- /verify/graph/test/eulerian_trail_directed.test.cpp.html
title: graph/test/eulerian_trail_directed.test.cpp
---
