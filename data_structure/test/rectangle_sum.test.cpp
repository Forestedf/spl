#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#define FAST_IO

#include "../../data_structure/rectangle_sum.hpp"
#include "../../template/template.hpp"

int main() {
    I32(n, q);
    RectangleSum<i32, i64> rs;
    for (int i = 0; i < n; ++i) {
        I32(x, y, w);
        rs.add_point(x, y, w);
    }
    for (int i = 0; i < q; ++i) {
        I32(l, d, r, u);
        rs.add_query(l, r, d, u);
    }
    V<i64> ret = rs.solve();
    REP(i, q) {
        cout << ret[i] << '\n';
    }
}
