---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: algebra/test/inverse_matrix.test.cpp
    title: algebra/test/inverse_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: algebra/test/matrix_det.test.cpp
    title: algebra/test/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: algebra/test/matrix_product.test.cpp
    title: algebra/test/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: algebra/test/matrix_rank.test.cpp
    title: algebra/test/matrix_rank.test.cpp
  - icon: ':heavy_check_mark:'
    path: algebra/test/system_of_linear_equations.test.cpp
    title: algebra/test/system_of_linear_equations.test.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/test/gcd_convolution.test.cpp
    title: convolution/test/gcd_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/test/mul_modp_convolution.test.cpp
    title: convolution/test/mul_modp_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/range_affine_point_get.test.cpp
    title: data_structure/test/range_affine_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/test/enumerate_triangles.test.cpp
    title: graph/test/enumerate_triangles.test.cpp
  - icon: ':heavy_check_mark:'
    path: number_theory/test/factorize.test.cpp
    title: number_theory/test/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: poly/test/exp_of_formal_power_series.test.cpp
    title: poly/test/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: poly/test/exp_of_formal_power_series_sparse.test.cpp
    title: poly/test/exp_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: poly/test/find_linear_recurrence.test.cpp
    title: poly/test/find_linear_recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: poly/test/inv_of_formal_power_series.test.cpp
    title: poly/test/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: poly/test/inv_of_formal_power_series_sparse.test.cpp
    title: poly/test/inv_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: poly/test/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: poly/test/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: poly/test/log_of_formal_power_series.test.cpp
    title: poly/test/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: poly/test/log_of_formal_power_series_sparse.test.cpp
    title: poly/test/log_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: poly/test/pow_of_formal_power_series.test.cpp
    title: poly/test/pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: poly/test/prod_of_polys.test.cpp
    title: poly/test/prod_of_polys.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/fastio.hpp\"\n#include <cstdio>\n#include <cstring>\n\
    #include <type_traits>\n#include <utility>\n\n// unable to read INT_MIN (int),\
    \ LLONG_MIN (long long)\nclass Reader {\n    FILE *fp;\n    static constexpr int\
    \ BUF = 1 << 18;\n    char buf[BUF];\n    char *pl, *pr;\n\n    void reread()\
    \ {\n        int wd = pr - pl;\n        std::memcpy(buf, pl, wd);\n        pl\
    \ = buf;\n        pr = buf + wd;\n        pr += std::fread(pr, 1, BUF - wd, fp);\n\
    \    }\n\n    char skip() {\n        char ch = *pl++;\n        while (ch <= '\
    \ ') {\n            ch = *pl++;\n        }\n        return ch;\n    }\n\n    template\
    \ <typename T>\n    void read_unsigned(T &x) {\n        if (pr - pl < 64) {\n\
    \            reread();\n        }\n        x = 0;\n        char ch = skip();\n\
    \        while ('0' <= ch) {\n            x = 10 * x + (0xf & ch);\n         \
    \   ch = *pl++;\n        }\n    }\n    template <typename T>\n    void read_signed(T\
    \ &x) {\n        if (pr - pl < 64) {\n            reread();\n        }\n     \
    \   x = 0;\n        bool neg = false;\n        char ch = skip();\n        if (ch\
    \ == '-') {\n            ch = *pl++;\n            neg = true;\n        }\n   \
    \     while ('0' <= ch) {\n            x = 10 * x + (0xf & ch);\n            ch\
    \ = *pl++;\n        }\n        if (neg) {\n            x = -x;\n        }\n  \
    \  }\n\n    void read_single(int &x) { read_signed(x); }\n    void read_single(unsigned\
    \ &x) { read_unsigned(x); }\n    void read_single(long &x) { read_signed(x); }\n\
    \    void read_single(unsigned long &x) { read_signed(x); }\n    void read_single(long\
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
    \      write_char('\\n');\n    }\n};\n\nReader rd(stdin);\nWriter wr(stdout);\n"
  code: "#include <cstdio>\n#include <cstring>\n#include <type_traits>\n#include <utility>\n\
    \n// unable to read INT_MIN (int), LLONG_MIN (long long)\nclass Reader {\n   \
    \ FILE *fp;\n    static constexpr int BUF = 1 << 18;\n    char buf[BUF];\n   \
    \ char *pl, *pr;\n\n    void reread() {\n        int wd = pr - pl;\n        std::memcpy(buf,\
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
    \      write_char('\\n');\n    }\n};\n\nReader rd(stdin);\nWriter wr(stdout);\n"
  dependsOn: []
  isVerificationFile: false
  path: template/fastio.hpp
  requiredBy: []
  timestamp: '2024-11-23 22:57:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/test/enumerate_triangles.test.cpp
  - number_theory/test/factorize.test.cpp
  - algebra/test/inverse_matrix.test.cpp
  - algebra/test/system_of_linear_equations.test.cpp
  - algebra/test/matrix_product.test.cpp
  - algebra/test/matrix_det.test.cpp
  - algebra/test/matrix_rank.test.cpp
  - data_structure/test/range_affine_point_get.test.cpp
  - poly/test/log_of_formal_power_series_sparse.test.cpp
  - poly/test/inv_of_formal_power_series.test.cpp
  - poly/test/prod_of_polys.test.cpp
  - poly/test/find_linear_recurrence.test.cpp
  - poly/test/exp_of_formal_power_series.test.cpp
  - poly/test/log_of_formal_power_series.test.cpp
  - poly/test/exp_of_formal_power_series_sparse.test.cpp
  - poly/test/kth_term_of_linearly_recurrent_sequence.test.cpp
  - poly/test/inv_of_formal_power_series_sparse.test.cpp
  - poly/test/pow_of_formal_power_series.test.cpp
  - convolution/test/mul_modp_convolution.test.cpp
  - convolution/test/gcd_convolution.test.cpp
documentation_of: template/fastio.hpp
layout: document
redirect_from:
- /library/template/fastio.hpp
- /library/template/fastio.hpp.html
title: template/fastio.hpp
---
