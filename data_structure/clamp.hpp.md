---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/clamp.hpp\"\n#include <algorithm>\n#include\
    \ <numeric>\n#include <utility>\n// x -> clamp(x + a, b, c)\ntemplate <typename\
    \ T>\nstruct Clamp {\n    T a, b, c;\n    Clamp() : a(0), b(-std::numeric_limits<T>::max()\
    \ / 2), c(std::numeric_limits<T>::max() / 2) {}\n    Clamp(T a, T b, T c) : a(a),\
    \ b(b), c(c) {}\n    T operator()(T x) const {\n        return std::clamp(x +\
    \ a, b, c);\n    }\n    std::pair<T, T> slope_range() const {\n        return\
    \ std::pair<T, T>(b - a, c - a);\n    }\n};\ntemplate <typename T>\nClamp<T> composite_clamps(const\
    \ Clamp<T> &f, const Clamp<T> &g) {\n    T a = f.a + g.a;\n    T b = std::clamp(g.b\
    \ + f.a, f.b, f.c);\n    T c = std::clamp(g.c + f.a, f.b, f.c);\n    return Clamp<T>(a,\
    \ b, c);\n}\ntemplate <typename T>\nstruct ClampMonoid {\n    using Value = Clamp<T>;\n\
    \    static Value id() {\n        return Clamp<T>();\n    }\n    static Value\
    \ op(const Value &f, const Value &g) {\n        return composite_clamps(f, g);\n\
    \    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <numeric>\n#include <utility>\n\
    // x -> clamp(x + a, b, c)\ntemplate <typename T>\nstruct Clamp {\n    T a, b,\
    \ c;\n    Clamp() : a(0), b(-std::numeric_limits<T>::max() / 2), c(std::numeric_limits<T>::max()\
    \ / 2) {}\n    Clamp(T a, T b, T c) : a(a), b(b), c(c) {}\n    T operator()(T\
    \ x) const {\n        return std::clamp(x + a, b, c);\n    }\n    std::pair<T,\
    \ T> slope_range() const {\n        return std::pair<T, T>(b - a, c - a);\n  \
    \  }\n};\ntemplate <typename T>\nClamp<T> composite_clamps(const Clamp<T> &f,\
    \ const Clamp<T> &g) {\n    T a = f.a + g.a;\n    T b = std::clamp(g.b + f.a,\
    \ f.b, f.c);\n    T c = std::clamp(g.c + f.a, f.b, f.c);\n    return Clamp<T>(a,\
    \ b, c);\n}\ntemplate <typename T>\nstruct ClampMonoid {\n    using Value = Clamp<T>;\n\
    \    static Value id() {\n        return Clamp<T>();\n    }\n    static Value\
    \ op(const Value &f, const Value &g) {\n        return composite_clamps(f, g);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/clamp.hpp
  requiredBy: []
  timestamp: '2026-04-03 13:29:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/clamp.hpp
layout: document
redirect_from:
- /library/data_structure/clamp.hpp
- /library/data_structure/clamp.hpp.html
title: data_structure/clamp.hpp
---
