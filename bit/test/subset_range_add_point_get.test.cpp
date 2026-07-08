#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#define FAST_IO
#define FIX_SEED

#include "../../bit/subset_range_add_point_get.hpp"
#include "../../number_theory/mod_int.hpp"
#include "../../template/template.hpp"

using M = ModInt<998244353>;

void test() {
    constexpr i32 ITER = 100;
    REP(_, ITER) {
        i32 l = uniform(0, 15);
        SubsetRangeAddPointGet<M> ds(l);
        V<M> arr(1 << l);
        i32 q = 1000;
        REP(qi, q) {
            if (uniform(2)) {
                u32 low = 0, high = 0;
                REP(i, l) {
                    i32 ty = uniform(3);
                    if (ty == 1) {
                        high += 1u << i;
                    } else if (ty == 2) {
                        low += 1u << i;
                        high += 1u << i;
                    }
                }
                M v(uniform(M::get_mod()));
                REP(st, 1 << l) {
                    if ((low | st) == st && (st | high) == high) {
                        arr[st] += v;
                    }
                }
                ds.add(low, high, v);
            } else {
                u32 idx = uniform(1 << l);
                assert(arr[idx] == ds.get(idx));
            }
        }
    }
}

int main() {
    test();
    cout << "Hello World\n";
}
