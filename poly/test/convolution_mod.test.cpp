#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#define FAST_IO
#include "../../poly/fft.hpp"
#include "../../template/template.hpp"

int main() {
    using M = ModInt<998244353>;
    I32(n, m);
    V<M> a(n), b(m);
    REP(i, n) {
        cin >> a[i];
    }
    REP(i, m) {
        cin >> b[i];
    }
    V<M> c = convolve(a, b);
    REP(i, n + m - 1) {
        cout << c[i] << " \n"[i + 1 == n + m - 1];
    }
}
