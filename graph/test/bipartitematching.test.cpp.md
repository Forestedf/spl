---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bipartite_matching.hpp
    title: graph/bipartite_matching.hpp
  - icon: ':question:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: template/random.hpp
    title: template/random.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"graph/test/bipartitematching.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/bipartitematching\"\n#define FAST_IO\n#line\
    \ 2 \"graph/bipartite_matching.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n#line 2 \"template/random.hpp\"\
    \n#include <chrono>\n#include <random>\n\n#if defined(LOCAL) || defined(FIX_SEED)\n\
    std::mt19937_64 mt(123456789);\n#else\nstd::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    #endif\n\ntemplate <typename T>\nT uniform(T l, T r) {\n    return std::uniform_int_distribution<T>(l,\
    \ r - 1)(mt);\n}\ntemplate <typename T>\nT uniform(T n) {\n    return std::uniform_int_distribution<T>(0,\
    \ n - 1)(mt);\n}\n#line 8 \"graph/bipartite_matching.hpp\"\n\nstd::pair<std::vector<int>,\
    \ std::vector<int>> bipartite_matching(\n    int l, int r, std::vector<std::pair<int,\
    \ int>> &es) {\n    std::shuffle(es.begin(), es.end(), mt);\n    std::vector<int>\
    \ rank(l + 1, 0);\n    for (auto [u, v] : es) {\n        ++rank[u];\n    }\n \
    \   for (int i = 0; i < l; ++i) {\n        rank[i + 1] += rank[i];\n    }\n  \
    \  std::vector<int> to(es.size(), 0);\n    for (auto [u, v] : es) {\n        to[--rank[u]]\
    \ = v;\n    }\n\n    std::vector<int> ml(l, -1), mr(r, -1);\n    std::vector<int>\
    \ que(l);\n    std::vector<int> dist(l, -1), vis(l, -1);\n    int stamp = 0;\n\
    \n    auto bfs = [&]() -> bool {\n        std::fill(dist.begin(), dist.end(),\
    \ -1);\n        bool ret = false;\n        int ql = 0, qr = 0;\n        for (int\
    \ i = 0; i < l; ++i) {\n            if (ml[i] == -1) {\n                que[qr++]\
    \ = i;\n                dist[i] = 0;\n            }\n        }\n        while\
    \ (ql < qr) {\n            int u = que[ql++];\n            for (int i = rank[u];\
    \ i < rank[u + 1]; ++i) {\n                int v = to[i];\n                if\
    \ (mr[v] == -1) {\n                    ret = true;\n                } else {\n\
    \                    int w = mr[v];\n                    if (dist[w] == -1) {\n\
    \                        que[qr++] = w;\n                        dist[w] = dist[u]\
    \ + 1;\n                    }\n                }\n            }\n        }\n \
    \       return ret;\n    };\n\n    auto dfs = [&](auto dfs, int u) -> bool {\n\
    \        vis[u] = stamp;\n        for (int i = rank[u]; i < rank[u + 1]; ++i)\
    \ {\n            int v = to[i];\n            int w = mr[v];\n            if (w\
    \ == -1 ||\n                (vis[w] != stamp && dist[w] == dist[u] + 1 && dfs(dfs,\
    \ w))) {\n                ml[u] = v;\n                mr[v] = u;\n           \
    \     return true;\n            }\n        }\n        return false;\n    };\n\n\
    \    for (;; ++stamp) {\n        if (!bfs()) {\n            break;\n        }\n\
    \        for (int i = 0; i < l; ++i) {\n            if (ml[i] == -1) {\n     \
    \           dfs(dfs, i);\n            }\n        }\n    }\n\n    return std::make_pair(ml,\
    \ mr);\n}\n#line 1 \"template/fastio.hpp\"\n#include <cstdio>\n#include <cstring>\n\
    #include <string>\n#include <type_traits>\n#line 6 \"template/fastio.hpp\"\n\n\
    // unable to read INT_MIN (int), LLONG_MIN (long long)\nclass Reader {\n    FILE\
    \ *fp;\n    static constexpr int BUF = 1 << 18;\n    char buf[BUF];\n    char\
    \ *pl, *pr;\n\n    void reread() {\n        int wd = pr - pl;\n        std::memcpy(buf,\
    \ pl, wd);\n        pl = buf;\n        pr = buf + wd;\n        pr += std::fread(pr,\
    \ 1, BUF - wd, fp);\n    }\n\n    char skip() {\n        char ch = *pl++;\n  \
    \      while (ch <= ' ') {\n            ch = *pl++;\n        }\n        return\
    \ ch;\n    }\n\n    template <typename T>\n    void read_unsigned(T &x) {\n  \
    \      if (pr - pl < 64) {\n            reread();\n        }\n        x = 0;\n\
    \        char ch = skip();\n        while ('0' <= ch) {\n            x = 10 *\
    \ x + (0xf & ch);\n            ch = *pl++;\n        }\n    }\n    template <typename\
    \ T>\n    void read_signed(T &x) {\n        if (pr - pl < 64) {\n            reread();\n\
    \        }\n        x = 0;\n        bool neg = false;\n        char ch = skip();\n\
    \        if (ch == '-') {\n            ch = *pl++;\n            neg = true;\n\
    \        }\n        while ('0' <= ch) {\n            x = 10 * x + (0xf & ch);\n\
    \            ch = *pl++;\n        }\n        if (neg) {\n            x = -x;\n\
    \        }\n    }\n\n    void read_single(int &x) { read_signed(x); }\n    void\
    \ read_single(unsigned &x) { read_unsigned(x); }\n    void read_single(long &x)\
    \ { read_signed(x); }\n    void read_single(unsigned long &x) { read_signed(x);\
    \ }\n    void read_single(long long &x) { read_signed(x); }\n    void read_single(unsigned\
    \ long long &x) { read_unsigned(x); }\n\npublic:\n    Reader(FILE *fp) : fp(fp),\
    \ pl(buf), pr(buf) { reread(); }\n\n    void read() {}\n    template <typename\
    \ Head, typename... Tail>\n    void read(Head &head, Tail &...tail) {\n      \
    \  read_single(head);\n        read(tail...);\n    }\n};\n\nstruct NumberToString\
    \ {\n    char buf[10000][4];\n    constexpr NumberToString() : buf() {\n     \
    \   for (int i = 0; i < 10000; ++i) {\n            int n = i;\n            for\
    \ (int j = 3; j >= 0; --j) {\n                buf[i][j] = '0' + n % 10;\n    \
    \            n /= 10;\n            }\n        }\n    }\n} constexpr number_to_string_precalc;\n\
    \nclass Writer {\n    FILE *fp;\n    static constexpr int BUF = 1 << 18;\n   \
    \ char buf[BUF];\n    char *ptr;\n\n    void write_u32(unsigned x) {\n       \
    \ if ((buf + BUF - ptr) < 32) {\n            flush();\n        }\n        static\
    \ char sml[12];\n        int t = 8;\n        while (x >= 10000) {\n          \
    \  unsigned n = x % 10000;\n            x /= 10000;\n            std::memcpy(sml\
    \ + t, number_to_string_precalc.buf[n], 4);\n            t -= 4;\n        }\n\
    \        if (x >= 1000) {\n            std::memcpy(ptr, number_to_string_precalc.buf[x],\
    \ 4);\n            ptr += 4;\n        } else if (x >= 100) {\n            std::memcpy(ptr,\
    \ number_to_string_precalc.buf[x] + 1, 3);\n            ptr += 3;\n        } else\
    \ if (x >= 10) {\n            unsigned q = (x * 103) >> 10;\n            *ptr++\
    \ = q | '0';\n            *ptr++ = (x - 10 * q) | '0';\n        } else {\n   \
    \         *ptr++ = '0' | x;\n        }\n        std::memcpy(ptr, sml + (t + 4),\
    \ 8 - t);\n        ptr += 8 - t;\n    }\n\n    void write_u64(unsigned long long\
    \ x) {\n        if ((buf + BUF - ptr) < 32) {\n            flush();\n        }\n\
    \        if (x >= 10000000000000000) {\n            unsigned long long z = x %\
    \ 100000000;\n            x /= 100000000;\n            unsigned long long y =\
    \ x % 100000000;\n            x /= 100000000;\n            if (x >= 1000) {\n\
    \                std::memcpy(ptr, number_to_string_precalc.buf[x], 4);\n     \
    \           ptr += 4;\n            } else if (x >= 100) {\n                std::memcpy(ptr,\
    \ number_to_string_precalc.buf[x] + 1, 3);\n                ptr += 3;\n      \
    \      } else if (x >= 10) {\n                unsigned q = (x * 103) >> 10;\n\
    \                *ptr++ = q | '0';\n                *ptr++ = (x - 10 * q) | '0';\n\
    \            } else {\n                *ptr++ = '0' | x;\n            }\n    \
    \        std::memcpy(ptr, number_to_string_precalc.buf[y / 10000], 4);\n     \
    \       std::memcpy(ptr + 4, number_to_string_precalc.buf[y % 10000], 4);\n  \
    \          std::memcpy(ptr + 8, number_to_string_precalc.buf[z / 10000], 4);\n\
    \            std::memcpy(ptr + 12, number_to_string_precalc.buf[z % 10000], 4);\n\
    \            ptr += 16;\n        } else {\n            static char sml[12];\n\
    \            int t = 8;\n            while (x >= 10000) {\n                unsigned\
    \ long long n = x % 10000;\n                x /= 10000;\n                std::memcpy(sml\
    \ + t, number_to_string_precalc.buf[n], 4);\n                t -= 4;\n       \
    \     }\n            if (x >= 1000) {\n                std::memcpy(ptr, number_to_string_precalc.buf[x],\
    \ 4);\n                ptr += 4;\n            } else if (x >= 100) {\n       \
    \         std::memcpy(ptr, number_to_string_precalc.buf[x] + 1, 3);\n        \
    \        ptr += 3;\n            } else if (x >= 10) {\n                unsigned\
    \ q = (x * 103) >> 10;\n                *ptr++ = q | '0';\n                *ptr++\
    \ = (x - 10 * q) | '0';\n            } else {\n                *ptr++ = '0' |\
    \ x;\n            }\n            std::memcpy(ptr, sml + (t + 4), 8 - t);\n   \
    \         ptr += 8 - t;\n        }\n    }\n\n    void write_char(char c) {\n \
    \       if (ptr == buf + BUF) {\n            flush();\n        }\n        *ptr++\
    \ = c;\n    }\n\n    template <typename T>\n    void write_unsigned(T x) {\n \
    \       if constexpr (std::is_same_v<T, unsigned long long> ||\n             \
    \         std::is_same_v<T, unsigned long>) {\n            write_u64(x);\n   \
    \     } else {\n            write_u32(x);\n        }\n    }\n\n    template <typename\
    \ T>\n    void write_signed(T x) {\n        std::make_unsigned_t<T> y = x;\n \
    \       if (x < 0) {\n            write_char('-');\n            y = -y;\n    \
    \    }\n        write_unsigned(y);\n    }\n    \n    void write_string(const std::string\
    \ &s) {\n        for (char c : s) {\n            write_char(c);\n        }\n \
    \   }\n\n    void write_single(int x) { write_signed(x); }\n    void write_single(unsigned\
    \ x) { write_unsigned(x); }\n    void write_single(long x) { write_signed(x);\
    \ }\n    void write_single(unsigned long x) { write_unsigned(x); }\n    void write_single(long\
    \ long x) { write_signed(x); }\n    void write_single(unsigned long long x) {\
    \ write_unsigned(x); }\n    void write_single(char c) { write_char(c); }\n   \
    \ void write_single(const std::string &s) { write_string(s); }\n\npublic:\n  \
    \  Writer(FILE *fp) : fp(fp), ptr(buf) {}\n    ~Writer() { flush(); }\n\n    void\
    \ flush() {\n        std::fwrite(buf, 1, ptr - buf, fp);\n        ptr = buf;\n\
    \    }\n\n    void write() {}\n    template <typename Head, typename... Tail>\n\
    \    void write(Head &&head, Tail &&...tail) {\n        write_single(head);\n\
    \        if (sizeof...(Tail)) {\n            write_char(' ');\n        }\n   \
    \     write(std::forward<Tail>(tail)...);\n    }\n\n    template <typename...\
    \ T>\n    void writeln(T &&...t) {\n        write(std::forward<T>(t)...);\n  \
    \      write_char('\\n');\n    }\n};\n\nReader rd(stdin);\nWriter wr(stdout);\n\
    #line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#define OVERRIDE(a,\
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
    void scan(f64 &x) { cin >> x; }\nvoid scan(string &x) { cin >> x; }\ntemplate\
    \ <typename T>\nvoid scan(V<T> &x) {\n    for (T &ele : x) {\n        scan(ele);\n\
    \    }\n}\nvoid read() {}\ntemplate <typename Head, typename... Tail>\nvoid read(Head\
    \ &head, Tail &...tail) {\n    scan(head);\n    read(tail...);\n}\n#define CHAR(...)\
    \     \\\n    char __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define U32(...) \
    \    \\\n    u32 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define U64(...)   \
    \  \\\n    u64 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define I32(...)     \\\
    \n    i32 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define I64(...)     \\\n \
    \   i64 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define F64(...)     \\\n   \
    \ f64 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define STR(...)        \\\n  \
    \  string __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define VEC(type, name, size)\
    \ \\\n    V<type> name(size);       \\\n    read(name);\n#define VVEC(type, name,\
    \ size1, size2)    \\\n    VV<type> name(size1, V<type>(size2)); \\\n    read(name);\n\
    #line 6 \"graph/test/bipartitematching.test.cpp\"\n\nvoid solve() {\n    i32 l,\
    \ r, m;\n    rd.read(l, r, m);\n    V<pi> es(m);\n    for (auto &[a, b] : es)\
    \ {\n        rd.read(a, b);\n    }\n    V<i32> ml = bipartite_matching(l, r, es).first;\n\
    \    i32 k = l - count(ALL(ml), -1);\n    wr.writeln(k);\n    REP(i, l) {\n  \
    \      if (ml[i] != -1) {\n            wr.writeln(i, ml[i]);\n        }\n    }\n\
    }\n\nint main() {\n    i32 t = 1;\n    // cin >> t;\n    while (t--) {\n     \
    \   solve();\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#define\
    \ FAST_IO\n#include \"../../graph/bipartite_matching.hpp\"\n#include \"../../template/fastio.hpp\"\
    \n#include \"../../template/template.hpp\"\n\nvoid solve() {\n    i32 l, r, m;\n\
    \    rd.read(l, r, m);\n    V<pi> es(m);\n    for (auto &[a, b] : es) {\n    \
    \    rd.read(a, b);\n    }\n    V<i32> ml = bipartite_matching(l, r, es).first;\n\
    \    i32 k = l - count(ALL(ml), -1);\n    wr.writeln(k);\n    REP(i, l) {\n  \
    \      if (ml[i] != -1) {\n            wr.writeln(i, ml[i]);\n        }\n    }\n\
    }\n\nint main() {\n    i32 t = 1;\n    // cin >> t;\n    while (t--) {\n     \
    \   solve();\n    }\n}\n"
  dependsOn:
  - graph/bipartite_matching.hpp
  - template/random.hpp
  - template/fastio.hpp
  - template/template.hpp
  isVerificationFile: true
  path: graph/test/bipartitematching.test.cpp
  requiredBy: []
  timestamp: '2025-09-14 09:21:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph/test/bipartitematching.test.cpp
layout: document
redirect_from:
- /verify/graph/test/bipartitematching.test.cpp
- /verify/graph/test/bipartitematching.test.cpp.html
title: graph/test/bipartitematching.test.cpp
---
