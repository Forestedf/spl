#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind"
#define FAST_IO
#include "../../poly/stirling1.hpp"
#include "../../template/template.hpp"

int main() {
    using M = ModInt<998244353>;
    I32(n);
    V<M> ans = stirling_1_signed<M>(n);
    REP(i, n + 1) {
        cout << ans[i] << " \n"[i == n];
    }
}
