#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#define FAST_IO
#define FIX_SEED

#include "../../bit/point_add_subset_sum.hpp"
#include "../../number_theory/mod_int.hpp"
#include "../../data_structure/operations.hpp"
#include "../../template/template.hpp"

using M = ModInt<998244353>;

void test() {
    constexpr i32 ITER = 100;
    REP(_, ITER) {
        i32 l = uniform(0, 15);
        PointAddSubsetSum<Add<M>> ds(l);
        V<M> arr(1 << l);
        i32 q = 1000;
        REP(qi, q) {
            if (uniform(2)) {
                u32 idx = uniform(1 << l);
                M val = M(uniform(M::get_mod()));
                arr[idx] += val;
                ds.add(idx, val);
            } else {
                u32 idx = uniform(1 << l);
                M right = arr[0];
                for (u32 i = idx; i; i = (i - 1) & idx) {
                    right += arr[i];
                }
                assert(right == ds.get(idx));
            }
        }
    }
}

int main() {
    test();
    cout << "Hello World\n";
}
