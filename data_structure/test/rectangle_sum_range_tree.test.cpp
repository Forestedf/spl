#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#define FAST_IO

#include "../../data_structure/operations.hpp"
#include "../../data_structure/range_tree.hpp"
#include "../../template/template.hpp"

int main() {
    i32 n, q;
    cin >> n >> q;
    V<tuple<i32, i32, i64>> pts(n);
    for (auto &[x, y, w] : pts) {
        cin >> x >> y >> w;
    }
    RangeTree<i32, Add<i64>> range_tree(pts);
    REP(qi, q) {
        i32 l, d, r, u;
        cin >> l >> d >> r >> u;
        cout << range_tree.sum(l, r, d, u) << '\n';
    }
}
