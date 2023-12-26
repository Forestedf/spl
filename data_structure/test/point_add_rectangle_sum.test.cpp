#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"
#define FAST_IO

#include "../../data_structure/fenwick_tree.hpp"
#include "../../data_structure/general_range_tree.hpp"
#include "../../template/template.hpp"

int main() {
    i32 n, q;
    cin >> n >> q;
    V<i32> x(n), y(n), w(n);
    REP(i, n) { cin >> x[i] >> y[i] >> w[i]; }
    V<tuple<i32, i32, i32, i32, i32>> queries(q);
    for (auto &[type, a, b, c, d] : queries) {
        cin >> type;
        if (type == 0) {
            cin >> a >> b >> c;
            d = 0;
        } else {
            cin >> a >> b >> c >> d;
        }
    }
    i32 pct = n;
    for (const auto &[type, _a, _b, _c, _d] : queries) {
        if (type == 0) {
            ++pct;
        }
    }
    V<pi> pts;
    pts.reserve(pct);
    REP(i, n) { pts.emplace_back(x[i], y[i]); }
    for (const auto &[type, a, b, c, d] : queries) {
        if (type == 0) {
            pts.emplace_back(a, b);
        }
    }
    GRangeTree rt(pts);
    VV<i32> upd_pct(pct - n);
    REP(i, rt.size()) {
        if (rt[i] >= n) {
            upd_pct[rt[i] - n].push_back(i);
        }
    }
    FenwickTree<Add<i64>> ft(rt.size());
    REP(i, rt.size()) {
        if (rt[i] < n) {
            ft.add(i, w[rt[i]]);
        }
    }
    i32 it = 0;
    for (const auto &[type, a, b, c, d] : queries) {
        if (type == 0) {
            for (i32 upd : upd_pct[it++]) {
                ft.add(upd, c);
            }
        } else {
            i64 ans = 0;
            for (auto [l, r] : rt.rectangle(a, c, b, d)) {
                ans += ft.sum(l, r);
            }
            cout << ans << '\n';
        }
    }
}