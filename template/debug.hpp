#pragma once

#include <algorithm>
#include <array>
#include <atcoder/modint>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

std::ostream &operator<<(std::ostream &os, __int128_t x) {
    std::string s;
    if (x < 0) {
        x = -x;
        os << '-';
    }
    if (x == 0) {
        s.push_back('0');
    } else {
        while (x > 0) {
            s.push_back('0' + x % 10);
            x /= 10;
        }
        std::reverse(s.begin(), s.end());
    }
    os << s;
    return os;
}
std::ostream &operator<<(std::ostream &os, __uint128_t x) {
    std::string s;
    if (x == 0) {
        s.push_back('0');
    } else {
        while (x > 0) {
            s.push_back('0' + x % 10);
            x /= 10;
        }
        std::reverse(s.begin(), s.end());
    }
    os << s;
    return os;
}

template <typename T, std::enable_if_t<std::is_integral_v<T>> * = nullptr>
void debug(T x) {
    std::cerr << x;
}

template <typename T, std::enable_if_t<std::is_floating_point_v<T>> * = nullptr>
void debug(T x) {
    std::cerr << x;
}

void debug(bool b) {
    if (b) {
        std::cerr << "true";
    } else {
        std::cerr << "false";
    }
}

template <typename T>
void debug(const std::vector<T> &x);

template <int mod>
void debug(atcoder::static_modint<mod> v) {
    std::cerr << v.val();
}

void debug(const std::string &s) { std::cerr << '"' << s << '"'; }

template <typename T, typename U>
void debug(const std::pair<T, U> &p) {
    std::cerr << '(';
    debug(p.first);
    std::cerr << ", ";
    debug(p.second);
    std::cerr << ')';
}

template <std::size_t cur, typename... Args>
void tuple_debug_inner(const std::tuple<Args...> &t) {
    std::cerr << std::get<cur>(t);
    if constexpr (cur + 1 != sizeof...(Args)) {
        std::cerr << ", ";
        tuple_debug_inner<cur + 1, Args...>(t);
    }
}

template <typename... Args>
void debug(const std::tuple<Args...> &t) {
    std::cerr << '(';
    tuple_debug_inner<0, Args...>(t);
    std::cerr << ')';
}

template <typename T, std::size_t s>
void debug(const std::array<T, s> &arr) {
    std::cerr << '[';
    for (std::size_t i = 0; i < s; ++i) {
        debug(arr[i]);
        if (i + 1 != s) {
            std::cerr << ", ";
        }
    }
    std::cerr << ']';
}

template <typename K, typename V>
void debug(const std::map<K, V> &mp) {
    std::cerr << '{';
    for (const auto [k, v] : mp) {
        std::cerr << ' ';
        debug(k);
        std::cerr << ':';
        debug(v);
    }
    std::cerr << " }";
}

template <typename T>
void debug(const std::set<T> &st) {
    std::cerr << '{';
    for (const T &ele : st) {
        std::cerr << ' ';
        debug(ele);
    }
    std::cerr << " }";
}
template <typename T>
void debug(const std::multiset<T> &st) {
    std::cerr << '{';
    for (const T &ele : st) {
        std::cerr << ' ';
        debug(ele);
    }
    std::cerr << " }";
}

template <typename T>
void debug(std::queue<T> que) {
    std::cerr << '[';
    while (!que.empty()) {
        T ele = que.front();
        que.pop();
        debug(ele);
        if (!que.empty()) {
            std::cerr << ' ';
        }
    }
    std::cerr << ']';
}

template <typename T>
void debug(const std::vector<T> &v) {
    std::cerr << '[';
    for (std::size_t i = 0; i < v.size(); ++i) {
        debug(v[i]);
        if (i + 1 != v.size()) {
            std::cerr << ", ";
        }
    }
    std::cerr << ']';
}

template <typename T, typename Container, typename Comp>
void debug(std::priority_queue<T, Container, Comp> que) {
    std::cerr << '[';
    while (!que.empty()) {
        T ele = que.top();
        que.pop();
        debug(ele);
        if (!que.empty()) {
            std::cerr << ' ';
        }
    }
    std::cerr << ']';
}

template <typename T>
void debug(std::stack<T> sta) {
    std::cerr << '[';
    while (!sta.empty()) {
        T ele = sta.top();
        sta.pop();
        debug(ele);
        if (!sta.empty()) {
            std::cerr << ' ';
        }
    }
    std::cerr << ']';
}

template <typename T>
void debug(std::deque<T> dq) {
    std::cerr << '[';
    while (!dq.empty()) {
        T ele = dq.front();
        dq.pop_front();
        debug(ele);
        if (!dq.empty()) {
            std::cerr << ' ';
        }
    }
    std::cerr << ']';
}

void debug_many(bool first) {}
template <typename Head, typename... Tail>
void debug_many(bool first, const Head &head, const Tail &...tail) {
    if (!first) {
        std::cerr << ", ";
    }
    debug(head);
    debug_many(false, tail...);
}

#define DBG(...)                            \
    do {                                    \
        std::cerr << #__VA_ARGS__ << " : "; \
        debug_many(true, __VA_ARGS__);      \
        std::cerr << std::endl;             \
    } while (false)
