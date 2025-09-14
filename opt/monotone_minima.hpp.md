---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/min_plus_convolution.hpp
    title: convolution/min_plus_convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: convolution/test/min_plus_convolution_convex_arbitrary.test.cpp
    title: convolution/test/min_plus_convolution_convex_arbitrary.test.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/test/min_plus_convolution_convex_convex.test.cpp
    title: convolution/test/min_plus_convolution_convex_convex.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ argmin;\n}\n"
  code: "#pragma once\n#include <vector>\n\n// f(i, j, k) = true <=> (i, j) -> (i,\
    \ k)\n// j < k.\ntemplate <typename F>\nstd::vector<int> monotone_minima(int h,\
    \ int w, F f) {\n    std::vector<int> argmin(h);\n    auto rec = [&](auto rec,\
    \ int xl, int xr, int yl, int yr) -> void {\n        if (xl == xr) {\n       \
    \     return;\n        }\n        int xm = (xl + xr) / 2;\n        argmin[xm]\
    \ = yl;\n        for (int i = yl + 1; i < yr; ++i) {\n            if (f(xm, argmin[xm],\
    \ i)) {\n                argmin[xm] = i;\n            }\n        }\n        rec(rec,\
    \ xl, xm, yl, argmin[xm] + 1);\n        rec(rec, xm + 1, xr, argmin[xm], yr);\n\
    \    };\n    rec(rec, 0, h, 0, w);\n    return argmin;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: opt/monotone_minima.hpp
  requiredBy:
  - convolution/min_plus_convolution.hpp
  timestamp: '2025-08-27 11:36:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - convolution/test/min_plus_convolution_convex_arbitrary.test.cpp
  - convolution/test/min_plus_convolution_convex_convex.test.cpp
documentation_of: opt/monotone_minima.hpp
layout: document
redirect_from:
- /library/opt/monotone_minima.hpp
- /library/opt/monotone_minima.hpp.html
title: opt/monotone_minima.hpp
---
