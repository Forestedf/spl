#pragma once
#include <cassert>
#include <limits>
#include <queue>
#include <type_traits>

template <typename T>
class SlopeTrick {
public:
    static constexpr T MIN = std::numeric_limits<T>::min() / 2;
    static constexpr T MAX = std::numeric_limits<T>::max() / 2;

private:
    template <bool REV>
    class PriorityQueue {
        std::priority_queue<
            T, std::vector<T>,
            typename std::conditional<REV, std::greater<T>, std::less<T>>::type>
            pq;
        T added;

    public:
        PriorityQueue() : pq(), added(0) {
            if constexpr (REV)
                pq.push(MAX);
            else
                pq.push(MIN);
        }

        void push(const T &x) { pq.push(x - added); }

        void add(const T &x) { added += x; }

        T top() const { return pq.top() + added; }

        T pop() {
            T ret = pq.top();
            pq.pop();
            return ret += added;
        }

        void clear() {
            while (pq.size() > 1) pq.pop();
        }
    };

    PriorityQueue<false> l;
    PriorityQueue<true> r;
    T minimum;

public:
    SlopeTrick() : l(), r(), minimum(T(0)) {}

    T min() const { return minimum; }

    std::pair<T, T> min_arg() const {
        return std::pair<T, T>(l.top(), r.top());
    }

    void add_constant(const T &a) { minimum += a; }

    void add_plus(const T &a) {
        if (l.top() > a) {
            minimum += l.top() - a;
            l.push(a);
            r.push(l.pop());
        } else {
            r.push(a);
        }
    }

    void add_minus(const T &a) {
        if (r.top() < a) {
            minimum += a - r.top();
            r.push(a);
            l.push(r.pop());
        } else {
            l.push(a);
        }
    }

    void add_abs(const T &a) {
        add_plus(a);
        add_minus(a);
    }

    void clear_left() { l.clear(); }

    void clear_right() { r.clear(); }

    void slide_min(const T &a, const T &b) {
        assert(a <= b);
        l.add(a);
        r.add(b);
    }

    void slide(const T &a) {
        l.add(a);
        r.add(a);
    }
};
