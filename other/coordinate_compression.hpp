#pragma once

#include <algorithm>
#include <vector>

template <typename T>
class CoordinateCompression {
    std::vector<T> data;

    int size_sum() { return 0; }

    template <typename... Tail>
    int size_sum(const std::vector<T> &head, const Tail &...tail) {
        return (int)head.size() + size_sum(tail...);
    }

    void push() {}

    template <typename... Tail>
    void push(const std::vector<T> &head, const Tail &...tail) {
        for (const T &ele : head) {
            data.emplace_back(ele);
        }
        push(tail...);
    }

    void compress() {}

    template <typename... Tail>
    void compress(std::vector<T> &head, Tail &...tail) {
        for (T &ele : head) {
            ele = (T)(std::lower_bound(data.begin(), data.end(), ele) -
                      data.begin());
        }
        compress(tail...);
    }

public:
    template <typename... V>
    CoordinateCompression(V &...v) {
        data.reserve(size_sum(v...));
        push(v...);
        std::sort(data.begin(), data.end());
        data.erase(std::unique(data.begin(), data.end()), data.end());
        compress(v...);
    }

    const T &operator[](const T &ele) const { return data[ele]; }

    int size() const { return data.size(); }

    bool contains(const T &ele) const {
        auto it = std::lower_bound(data.begin(), data.end(), ele);
        return it != data.end() && *it == ele;
    }

    T cc(const T &ele) const {
        return (T)(std::lower_bound(data.begin(), data.end(), ele) -
                   data.begin());
    }
};