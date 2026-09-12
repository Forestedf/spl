#pragma once
#include <vector>
template <typename M, int BUCKET = 200>
class BinomialPrefixSum {
    static constexpr unsigned B = BUCKET;
    static constexpr M INV2 = M(2).inv();
    std::vector<M> a, b, c;
    std::vector<std::vector<M>> sums;
    M _get(unsigned n, unsigned k) const {
        unsigned x = n / B;
        unsigned y = k / B;
        M ans = sums[y][x];
        y *= B;
        x *= B;
        M sub;
        while (x < n) {
            sub += a[x] * b[x - y];
            ++x;
        }
        ans -= sub * b[y] * INV2;
        sub = M();
        while (y < k) {
            ++y;
            sub += b[y] * b[n - y];
        }
        ans += sub * a[n];
        return ans;
    }
public:
    BinomialPrefixSum(int n) : a(n + 1), b(n + 1), c(n + 1), sums(n / (2 * B) + 1) {
        M pr = M::raw(1);
        for (int i = 0; i <= n; ++i) {
            a[i] = pr;
            pr *= M::raw(i + 1) * INV2;
        }
        pr = M::raw(1);
        for (int i = 1; i <= n; ++i) {
            pr *= M::raw(i);
        }
        pr = pr.inv();
        b[n] = pr;
        for (int i = n - 1; i >= 0; --i) {
            pr *= M::raw(i + 1);
            b[i] = pr;
        }
        c[0] = M::raw(1);
        for (int i = 0; i < n; ++i) {
            c[i + 1] = c[i] + c[i];
        }
        for (int i = 0; 2 * B * i <= n; ++i) {
            sums[i].resize(n / B + 1);
            M s = (M::raw(1) + a[2 * i * B] * b[i * B] * b[i * B]) * INV2;
            sums[i][2 * i] = s;
            int k = 2 * i * B;
            for (int j = 2 * i + 1; B * j <= n; ++j) {
                M sub;
                for (int iter = 0; iter < B; ++iter) {
                    sub += a[k] * b[k - i * B];
                    ++k;
                }
                s -= sub * b[i * B] * INV2;
                sums[i][j] = s;
            }
        }
    }
    M get(int n, int k) const {
        if (2 * k > n) {
            M ans = M::raw(1);
            if (k < n) {
                ans -= _get(n, n - k - 1);
            }
            return ans * c[n];
        }
        return _get(n, k) * c[n];
    }
};
