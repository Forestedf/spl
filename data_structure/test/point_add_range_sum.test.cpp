#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#define FAST_IO

#include "../../data_structure/fenwick_tree.hpp"
#include "../../template/template.hpp"

int main() {
    i32 n, q;
    cin >> n >> q;
    FenwickTree<Add<i64>> ft(n);
    REP(i, n) {
        i64 a;
        cin >> a;
        ft.add(i, a);
    }
    REP(qi, q) {
        i32 type;
        cin >> type;
        if (type == 0) {
            i32 p;
            i64 x;
            cin >> p >> x;
            ft.add(p, x);
        } else {
            i32 l, r;
            cin >> l >> r;
            cout << ft.sum(l, r) << '\n';
        }
    }
}