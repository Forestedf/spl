#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"
#define FAST_IO

#include "../../data_structure/range_add_range_sum.hpp"
#include "../../template/template.hpp"

int main() {
    i32 n, q;
    cin >> n >> q;
    RangeAddRangeSum<i64> rr(n);
    REP(i, q) {
        i32 type;
        cin >> type;
        if (type == 0) {
            i32 s, t;
            i64 x;
            cin >> s >> t >> x;
            --s;
            rr.add(s, t, x);
        } else {
            i32 s, t;
            cin >> s >> t;
            --s;
            cout << rr.sum(s, t) << '\n';
        }
    }
}