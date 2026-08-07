---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: number_theory/test/linear_sieve.test.cpp
    title: number_theory/test/linear_sieve.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"number_theory/linear_sieve.hpp\"\n\n#include <cassert>\n\
    #include <numeric>\n#include <vector>\n\nclass LinearSieve {\n    std::vector<int>\
    \ mpf;\n    std::vector<int> ps;\n    \npublic:\n    LinearSieve(int n) : mpf(n\
    \ + 1) {\n        std::iota(mpf.begin(), mpf.end(), 0);\n        for (int i =\
    \ 2; i <= n; ++i) {\n            int m = mpf[i];\n            if (m == i) {\n\
    \                ps.push_back(i);\n            }\n            for (int p : ps)\
    \ {\n                if (p > m || i * p > n) {\n                    break;\n \
    \               }\n                mpf[p * i] = p;\n            }\n        }\n\
    \    }\n    int min_prime_factor(int n) const {\n        assert(n >= 2 && n <\
    \ (int)mpf.size());\n        return mpf[n];\n    }\n    std::vector<int> primes()\
    \ const {\n        return ps;\n    }\n    bool is_prime(int n) const {\n     \
    \   assert(n < (int)mpf.size());\n        return n >= 2 && mpf[n] == n;\n    }\n\
    \    std::vector<std::pair<int, int>> factorize(int n) const {\n        assert(n\
    \ > 0 && n < (int)mpf.size());\n        std::vector<std::pair<int, int>> ret;\n\
    \        while (n > 1) {\n            int p = mpf[n];\n            int ex = 0;\n\
    \            while (n % p == 0) {\n                n /= p;\n                ++ex;\n\
    \            }\n            ret.emplace_back(p, ex);\n        }\n        return\
    \ ret;\n    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <numeric>\n#include <vector>\n\
    \nclass LinearSieve {\n    std::vector<int> mpf;\n    std::vector<int> ps;\n \
    \   \npublic:\n    LinearSieve(int n) : mpf(n + 1) {\n        std::iota(mpf.begin(),\
    \ mpf.end(), 0);\n        for (int i = 2; i <= n; ++i) {\n            int m =\
    \ mpf[i];\n            if (m == i) {\n                ps.push_back(i);\n     \
    \       }\n            for (int p : ps) {\n                if (p > m || i * p\
    \ > n) {\n                    break;\n                }\n                mpf[p\
    \ * i] = p;\n            }\n        }\n    }\n    int min_prime_factor(int n)\
    \ const {\n        assert(n >= 2 && n < (int)mpf.size());\n        return mpf[n];\n\
    \    }\n    std::vector<int> primes() const {\n        return ps;\n    }\n   \
    \ bool is_prime(int n) const {\n        assert(n < (int)mpf.size());\n       \
    \ return n >= 2 && mpf[n] == n;\n    }\n    std::vector<std::pair<int, int>> factorize(int\
    \ n) const {\n        assert(n > 0 && n < (int)mpf.size());\n        std::vector<std::pair<int,\
    \ int>> ret;\n        while (n > 1) {\n            int p = mpf[n];\n         \
    \   int ex = 0;\n            while (n % p == 0) {\n                n /= p;\n \
    \               ++ex;\n            }\n            ret.emplace_back(p, ex);\n \
    \       }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/linear_sieve.hpp
  requiredBy: []
  timestamp: '2026-08-07 18:08:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - number_theory/test/linear_sieve.test.cpp
documentation_of: number_theory/linear_sieve.hpp
layout: document
redirect_from:
- /library/number_theory/linear_sieve.hpp
- /library/number_theory/linear_sieve.hpp.html
title: number_theory/linear_sieve.hpp
---
