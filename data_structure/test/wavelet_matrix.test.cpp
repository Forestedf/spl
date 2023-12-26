#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#define FAST_IO
#define FIX_SEED

#include "../../data_structure/wavelet_matrix.hpp"
#include "../../template/random.hpp"
#include "../../template/template.hpp"

constexpr i32 ITER = 100;
constexpr i32 LEN = 100;
constexpr i32 SIGMA = 100;

void test(const V<i32> &a) {
    WaveletMatrix<i32> wm(a);

    i32 n = (i32)a.size();

    // access
    REP(i, n) { assert(wm.access(i) == a[i]); }

    // kth_smallest
    REP(_iter, ITER) {
        i32 l = uniform(n);
        i32 r = uniform(l + 1, n + 1);
        i32 k = uniform(r - l);

        V<i32> b(a.begin() + l, a.begin() + r);
        sort(ALL(b));
        assert(wm.kth_smallest(l, r, k) == b[k]);
    }

    // rank
    REP(_iter, ITER) {
        i32 l = uniform(n);
        i32 r = uniform(l + 1, n + 1);
        i32 v = uniform(SIGMA + 10);

        assert(wm.rank(l, r, v) == count(a.begin() + l, a.begin() + r, v));
    }

    // range_freq
    REP(_iter, ITER) {
        i32 l = uniform(n);
        i32 r = uniform(l + 1, n + 1);
        i32 lower = uniform(SIGMA);
        i32 upper = uniform(lower + 1, SIGMA + 10);

        i32 cnt = 0;
        REP(i, l, r) {
            if (lower <= a[i] && a[i] < upper) {
                ++cnt;
            }
        }
        assert(wm.range_freq(l, r, lower, upper) == cnt);
    }

    // prev
    REP(_iter, ITER) {
        i32 l = uniform(n);
        i32 r = uniform(l + 1, n + 1);
        i32 upper = uniform(SIGMA + 10);

        i32 mx = -1;
        REP(i, l, r) {
            if (a[i] < upper) {
                chmax(mx, a[i]);
            }
        }
        assert(wm.prev(l, r, upper) == mx);
    }

    // next
    REP(_iter, ITER) {
        i32 l = uniform(n);
        i32 r = uniform(l + 1, n + 1);
        i32 lower = uniform(SIGMA + 10);

        i32 mn = INF;
        REP(i, l, r) {
            if (a[i] >= lower) {
                chmin(mn, a[i]);
            }
        }
        if (mn == INF) {
            assert(wm.next(l, r, lower) == -1);
        } else {
            assert(wm.next(l, r, lower) == mn);
        }
    }

    assert(wm.rank(0, n, 128) == 0);
    assert(wm.range_freq(0, n, 128) == n);
    assert(wm.prev(0, n, 128) == *max_element(ALL(a)));
}

V<i32> gen_random() {
    V<i32> a(LEN);
    for (i32 &ele : a) {
        ele = uniform(SIGMA);
    }
    return a;
}

int main() {
    REP(_, 10) { test(gen_random()); }

    cout << "Hello World\n";
}