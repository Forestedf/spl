#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"
#define FAST_IO

#include "../../data_structure/wavelet_matrix.hpp"
#include "../../template/template.hpp"

int main() {
    i32 n, q;
    cin >> n >> q;
    if (n == 0) {
        REP(_q, q) { cout << 0 << '\n'; }
        exit(0);
    }
    V<i32> a(n);
    REP(i, n) { cin >> a[i]; }
    WaveletMatrix<i32> wm(a);
    REP(qi, q) {
        i32 l, r, v;
        cin >> l >> r >> v;
        cout << wm.rank(l, r, v) << '\n';
    }
}