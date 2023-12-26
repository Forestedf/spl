#pragma once
#include <vector>
#include "../template/bitop.hpp"

class BitVector {
    static constexpr int WIDTH = 64;

    int n;
    std::vector<unsigned long long> bits;
    std::vector<unsigned long long> sum;
    int zeros;

public:
    BitVector(int _n)
        : n(_n), bits(n / WIDTH + 1, 0), sum(n / WIDTH + 1, 0), zeros(0) {}

    void rev(int idx) { bits[idx / WIDTH] ^= 1ULL << (idx % WIDTH); }

    bool operator[](int idx) const {
        return (bits[idx / WIDTH] & (1ULL << (idx % WIDTH))) != 0;
    }

    void build() {
        for (int i = 1; i < (int)sum.size(); ++i) {
            sum[i] = sum[i - 1] + popcount(bits[i - 1]);
        }
        zeros = rank0(n);
    }

    int rank0(int n) const { return n - rank1(n); }
    int rank1(int n) const {
        return sum[n / WIDTH] +
               popcount(
                   mask_n(bits[n / WIDTH], (unsigned long long)(n % WIDTH)));
    }
    int all_zeros() const { return zeros; }
};