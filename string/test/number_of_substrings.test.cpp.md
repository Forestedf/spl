---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/suffix_automaton.hpp
    title: string/suffix_automaton.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "#line 1 \"string/test/number_of_substrings.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/number_of_substrings\"\n#define FAST_IO\n\n\
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
    #line 2 \"string/suffix_automaton.hpp\"\n\n#line 6 \"string/suffix_automaton.hpp\"\
    \n\nstruct SuffixAutomaton {\n    struct Node {\n        std::unordered_map<char,\
    \ int> next;\n        int link;\n        int len;\n    };\n    std::vector<Node>\
    \ nodes;\n    int last;\n\n    SuffixAutomaton() : nodes(1, Node{{}, -1, 0}),\
    \ last(0) {}\n\n    void push(char c) {\n        int nn = (int)nodes.size();\n\
    \        nodes.emplace_back(Node{{}, 0, nodes[last].len + 1});\n        int p\
    \ = std::exchange(last, nn);\n        while (p != -1 && !nodes[p].next.count(c))\
    \ {\n            nodes[p].next[c] = nn;\n            p = nodes[p].link;\n    \
    \    }\n        if (p == -1) {\n            return;\n        }\n        int q\
    \ = nodes[p].next[c];\n        if (nodes[p].len + 1 == nodes[q].len) {\n     \
    \       nodes[nn].link = q;\n        } else {\n            int nq = (int)nodes.size();\n\
    \            nodes.emplace_back(\n                Node{nodes[q].next, nodes[q].link,\
    \ nodes[p].len + 1});\n            nodes[q].link = nq;\n            nodes[nn].link\
    \ = nq;\n            while (p != -1 && nodes[p].next[c] == q) {\n            \
    \    nodes[p].next[c] = nq;\n                p = nodes[p].link;\n            }\n\
    \        }\n    }\n};\n#line 6 \"string/test/number_of_substrings.test.cpp\"\n\
    \nvoid solve() {\n    STR(s);\n    SuffixAutomaton sa;\n    REP(i, LEN(s)) {\n\
    \        sa.push(s[i]);\n    }\n    i64 ans = 0;\n    REP(i, 1, LEN(sa.nodes))\
    \ {\n        ans += sa.nodes[i].len - sa.nodes[sa.nodes[i].link].len;\n    }\n\
    \    cout << ans << '\\n';\n}\n\nint main() {\n    i32 t = 1;\n    // cin >> t;\n\
    \    while (t--) {\n        solve();\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\
    #define FAST_IO\n\n#include \"../../template/template.hpp\"\n#include \"../../string/suffix_automaton.hpp\"\
    \n\nvoid solve() {\n    STR(s);\n    SuffixAutomaton sa;\n    REP(i, LEN(s)) {\n\
    \        sa.push(s[i]);\n    }\n    i64 ans = 0;\n    REP(i, 1, LEN(sa.nodes))\
    \ {\n        ans += sa.nodes[i].len - sa.nodes[sa.nodes[i].link].len;\n    }\n\
    \    cout << ans << '\\n';\n}\n\nint main() {\n    i32 t = 1;\n    // cin >> t;\n\
    \    while (t--) {\n        solve();\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - string/suffix_automaton.hpp
  isVerificationFile: true
  path: string/test/number_of_substrings.test.cpp
  requiredBy: []
  timestamp: '2025-12-02 11:14:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: string/test/number_of_substrings.test.cpp
layout: document
redirect_from:
- /verify/string/test/number_of_substrings.test.cpp
- /verify/string/test/number_of_substrings.test.cpp.html
title: string/test/number_of_substrings.test.cpp
---
