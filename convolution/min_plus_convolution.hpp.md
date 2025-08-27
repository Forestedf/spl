---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: opt/monotone_minima.hpp
    title: opt/monotone_minima.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: convolution/test/min_plus_convolution_convex_arbitrary.test.cpp
    title: convolution/test/min_plus_convolution_convex_arbitrary.test.cpp
  - icon: ':x:'
    path: convolution/test/min_plus_convolution_convex_convex.test.cpp
    title: convolution/test/min_plus_convolution_convex_convex.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"opt/monotone_minima.hpp\"\n#include <vector>\n\n// f(i,\
    \ j, k) = true <=> (i, j) -> (i, k)\n// j < k.\ntemplate <typename F>\nstd::vector<int>\
    \ monotone_minima(int h, int w, F f) {\n    std::vector<int> argmin(h);\n    auto\
    \ rec = [&](auto rec, int xl, int xr, int yl, int yr) -> void {\n        if (xl\
    \ == xr) {\n            return;\n        }\n        int xm = (xl + xr) / 2;\n\
    \        argmin[xm] = yl;\n        for (int i = yl + 1; i < yr; ++i) {\n     \
    \       if (f(xm, argmin[xm], i)) {\n                argmin[xm] = i;\n       \
    \     }\n        }\n        rec(rec, xl, xm, yl, argmin[xm] + 1);\n        rec(rec,\
    \ xm + 1, xr, argmin[xm], yr);\n    };\n    rec(rec, 0, h, 0, w);\n    return\
    \ argmin;\n}\n#line 3 \"convolution/min_plus_convolution.hpp\"\n#include <cassert>\n\
    \ntemplate <typename T>\nstd::vector<T> min_plus_convolution_convex_convex(const\
    \ std::vector<T> &a, const std::vector<T> &b) {\n    if (a.empty() || b.empty())\
    \ {\n        return std::vector<T>(0);\n    }\n    int n = (int)a.size();\n  \
    \  int m = (int)b.size();\n    std::vector<T> c(n + m - 1);\n    c[0] = a[0] +\
    \ b[0];\n    int ita = 0, itb = 0;\n    for (int i = 0; i < n + m - 2; ++i) {\n\
    \        if (itb == m - 1 || (ita != n - 1 && a[ita + 1] - a[ita] < b[itb + 1]\
    \ - b[itb])) {\n            c[i + 1] = c[i] + (a[ita + 1] - a[ita]);\n       \
    \     ++ita;\n        } else {\n            c[i + 1] = c[i] + (b[itb + 1] - b[itb]);\n\
    \            ++itb;\n        }\n    }\n    return c;\n}\n\ntemplate <typename\
    \ T>\nstd::vector<T> min_plus_convolution_convex_arbitrary(const std::vector<T>\
    \ &a, const std::vector<T> &b) {\n    if (a.empty() || b.empty()) {\n        return\
    \ std::vector<T>(0);\n    }\n    int n = (int)a.size();\n    int m = (int)b.size();\n\
    \    auto select = [&](int i, int j, int k) -> bool {\n        if (i < k) {\n\
    \            return false;\n        }\n        if (i - j >= n) {\n           \
    \ return true;\n        }\n        return a[i - j] + b[j] > a[i - k] + b[k];\n\
    \    };\n    std::vector<T> argmin = monotone_minima(n + m - 1, m, select);\n\
    \    std::vector<T> c(n + m - 1);\n    for (int i = 0; i < n + m - 1; ++i) {\n\
    \        c[i] = a[i - argmin[i]] + b[argmin[i]];\n    }\n    return c;\n}\n\n\
    template <typename T>\nbool is_convex(const std::vector<T> &a) {\n    int n =\
    \ (int)a.size();\n    for (int i = 0; i < n - 2; ++i) {\n        if (a[i + 1]\
    \ - a[i] > a[i + 2] - a[i + 1]) {\n            return false;\n        }\n    }\n\
    \    return true;\n}\n\n// is_convex(a) || is_convex(b)\ntemplate <typename T>\n\
    std::vector<T> min_plus_convolution(const std::vector<T> &a, const std::vector<T>\
    \ &b) {\n    bool ica = is_convex(a);\n    bool icb = is_convex(b);\n    if (ica\
    \ && icb) {\n        return min_plus_convolution_convex_convex(a, b);\n    } else\
    \ if (ica) {\n        return min_plus_convolution_convex_arbitrary(a, b);\n  \
    \  } else if (icb) {\n        return min_plus_convolution_convex_arbitrary(b,\
    \ a);\n    } else {\n        assert(false);\n    }\n}\n"
  code: "#pragma once\n#include \"../opt/monotone_minima.hpp\"\n#include <cassert>\n\
    \ntemplate <typename T>\nstd::vector<T> min_plus_convolution_convex_convex(const\
    \ std::vector<T> &a, const std::vector<T> &b) {\n    if (a.empty() || b.empty())\
    \ {\n        return std::vector<T>(0);\n    }\n    int n = (int)a.size();\n  \
    \  int m = (int)b.size();\n    std::vector<T> c(n + m - 1);\n    c[0] = a[0] +\
    \ b[0];\n    int ita = 0, itb = 0;\n    for (int i = 0; i < n + m - 2; ++i) {\n\
    \        if (itb == m - 1 || (ita != n - 1 && a[ita + 1] - a[ita] < b[itb + 1]\
    \ - b[itb])) {\n            c[i + 1] = c[i] + (a[ita + 1] - a[ita]);\n       \
    \     ++ita;\n        } else {\n            c[i + 1] = c[i] + (b[itb + 1] - b[itb]);\n\
    \            ++itb;\n        }\n    }\n    return c;\n}\n\ntemplate <typename\
    \ T>\nstd::vector<T> min_plus_convolution_convex_arbitrary(const std::vector<T>\
    \ &a, const std::vector<T> &b) {\n    if (a.empty() || b.empty()) {\n        return\
    \ std::vector<T>(0);\n    }\n    int n = (int)a.size();\n    int m = (int)b.size();\n\
    \    auto select = [&](int i, int j, int k) -> bool {\n        if (i < k) {\n\
    \            return false;\n        }\n        if (i - j >= n) {\n           \
    \ return true;\n        }\n        return a[i - j] + b[j] > a[i - k] + b[k];\n\
    \    };\n    std::vector<T> argmin = monotone_minima(n + m - 1, m, select);\n\
    \    std::vector<T> c(n + m - 1);\n    for (int i = 0; i < n + m - 1; ++i) {\n\
    \        c[i] = a[i - argmin[i]] + b[argmin[i]];\n    }\n    return c;\n}\n\n\
    template <typename T>\nbool is_convex(const std::vector<T> &a) {\n    int n =\
    \ (int)a.size();\n    for (int i = 0; i < n - 2; ++i) {\n        if (a[i + 1]\
    \ - a[i] > a[i + 2] - a[i + 1]) {\n            return false;\n        }\n    }\n\
    \    return true;\n}\n\n// is_convex(a) || is_convex(b)\ntemplate <typename T>\n\
    std::vector<T> min_plus_convolution(const std::vector<T> &a, const std::vector<T>\
    \ &b) {\n    bool ica = is_convex(a);\n    bool icb = is_convex(b);\n    if (ica\
    \ && icb) {\n        return min_plus_convolution_convex_convex(a, b);\n    } else\
    \ if (ica) {\n        return min_plus_convolution_convex_arbitrary(a, b);\n  \
    \  } else if (icb) {\n        return min_plus_convolution_convex_arbitrary(b,\
    \ a);\n    } else {\n        assert(false);\n    }\n}\n"
  dependsOn:
  - opt/monotone_minima.hpp
  isVerificationFile: false
  path: convolution/min_plus_convolution.hpp
  requiredBy: []
  timestamp: '2025-08-27 11:36:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - convolution/test/min_plus_convolution_convex_convex.test.cpp
  - convolution/test/min_plus_convolution_convex_arbitrary.test.cpp
documentation_of: convolution/min_plus_convolution.hpp
layout: document
redirect_from:
- /library/convolution/min_plus_convolution.hpp
- /library/convolution/min_plus_convolution.hpp.html
title: convolution/min_plus_convolution.hpp
---
