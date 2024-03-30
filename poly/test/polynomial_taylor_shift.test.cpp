#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"
#define FAST_IO
#include "../../poly/taylor_shift.hpp"
#include "../../template/template.hpp"

int main() {
    using M = ModInt<998244353>;
    I32(n);
    M c;
    cin >> c;
    V<M> f(n);
    REP(i, n) {
        cin >> f[i];
    }
    V<M> g = taylor_shift(f, c);
    REP(i, n) {
        cout << g[i] << " \n"[i + 1 == n];
    }
}
