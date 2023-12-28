---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: string/test/zalgorithm.test.cpp
    title: string/test/zalgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/z_algorithm.hpp\"\n#include <vector>\ntemplate <typename\
    \ Cont>\nstd::vector<int> z_algorithm(const Cont &s) {\n    std::vector<int> z(s.size(),\
    \ s.size());\n    int i = 1, j = 0;\n    while (i < (int)s.size()) {\n       \
    \ while (i + j < (int)s.size() && s[i + j] == s[j]) {\n            ++j;\n    \
    \    }\n        z[i] = j;\n        if (j == 0) {\n            ++i;\n         \
    \   continue;\n        }\n        int k = 1;\n        while (k < j && k + z[k]\
    \ < j) {\n            z[i + k] = z[k];\n            ++k;\n        }\n        i\
    \ += k;\n        j -= k;\n    }\n    return z;\n}\n"
  code: "#pragma once\n#include <vector>\ntemplate <typename Cont>\nstd::vector<int>\
    \ z_algorithm(const Cont &s) {\n    std::vector<int> z(s.size(), s.size());\n\
    \    int i = 1, j = 0;\n    while (i < (int)s.size()) {\n        while (i + j\
    \ < (int)s.size() && s[i + j] == s[j]) {\n            ++j;\n        }\n      \
    \  z[i] = j;\n        if (j == 0) {\n            ++i;\n            continue;\n\
    \        }\n        int k = 1;\n        while (k < j && k + z[k] < j) {\n    \
    \        z[i + k] = z[k];\n            ++k;\n        }\n        i += k;\n    \
    \    j -= k;\n    }\n    return z;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/z_algorithm.hpp
  requiredBy: []
  timestamp: '2023-12-28 19:39:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - string/test/zalgorithm.test.cpp
documentation_of: string/z_algorithm.hpp
layout: document
redirect_from:
- /library/string/z_algorithm.hpp
- /library/string/z_algorithm.hpp.html
title: string/z_algorithm.hpp
---
