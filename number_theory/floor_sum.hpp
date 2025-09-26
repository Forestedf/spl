#pragma once
#include <cassert>
#include <utility>
// Be careful about overflow
template <typename I, typename O>
O floor_sum(I l, I r, I a, I b, I m) {
    assert(l <= r && 1 <= m);
    O ans = 0;
    b += l * a;
    I n = r - l;
    if (a < 0) {
        I a2 = a % m + m;
        ans += ((n & 1) ? O((n - 1) / 2) * O(n) : O(n / 2) * O(n - 1)) * ((O(a) - O(a2)) / O(m));
        a = a2;
    }
    if (b < 0) {
        I b2 = b % m + m;
        ans += (O(b) - O(b2)) / O(m) * O(n);
        b = b2;
    }
    while (n) {
        if (a >= m) {
            ans += ((n & 1) ? O((n - 1) / 2) * O(n) : O(n / 2) * O(n - 1)) * (O(a) / O(m));
            a %= m;
        }
        if (b >= m) {
            ans += O(b) / O(m) * O(n);
            b %= m;
        }
        I mx = a * n + b;
        if (mx < m) {
            break;
        }
        n = mx / m;
        b = mx % m;
        std::swap(a, m);
    }
    return ans;
}
