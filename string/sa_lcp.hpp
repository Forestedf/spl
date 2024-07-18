#pragma once
#include <atcoder/string>
#include "../data_structure/sparse_table.hpp"

template <typename Cont>
struct StringSaLcp {
    Cont s;
    std::vector<int> sa, lcp, rev;
    SparseTable<int> sp;

    StringSaLcp(const Cont &s)
        : s(s),
          sa(atcoder::suffix_array(s)),
          lcp(atcoder::lcp_array(s, sa)),
          rev(s.size()),
          sp(lcp) {
        for (int i = 0; i < (int)s.size(); ++i) {
            rev[sa[i]] = i;
        }
    }

    // lcp(s[i:], s[j:])
    int get_lcp(int i, int j) const {
        assert(0 <= i && i <= (int)s.size());
        assert(0 <= j && j <= (int)s.size());
        if (i == (int)s.size() || j == (int)s.size()) {
            return 0;
        }
        if (i == j) {
            return (int)s.size() - i;
        }
        i = rev[i];
        j = rev[j];
        if (i > j) {
            std::swap(i, j);
        }
        return sp.min(i, j);
    }

    // lcp(s[l0:r0], s[l1:r1])
    int get_lcp(int l0, int r0, int l1, int r1) const {
        assert(0 <= l0 && l0 <= r0 && r0 <= (int)s.size());
        assert(0 <= l1 && l1 <= r1 && r1 <= (int)s.size());
        if (l0 == r0 || l1 == r1) {
            return 0;
        }
        return std::min({get_lcp(l0, l1), r0 - l0, r1 - l1});
    }

    int cmp(int l0, int r0, int l1, int r1) const {
        assert(0 <= l0 && l0 <= r0 && r0 <= (int)s.size());
        assert(0 <= l1 && l1 <= r1 && r1 <= (int)s.size());
        int lc = get_lcp(l0, r0, l1, r1);
        if (lc == r0 - l0 && lc == r1 - l1) {
            return 0;
        }
        if (lc == r0 - l0 || (lc != r1 - l1 && s[l0 + lc] < s[l1 + lc])) {
            return -1;
        } else {
            return 1;
        }
    }
};
