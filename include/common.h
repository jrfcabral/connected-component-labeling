#pragma once
#include <optional>
#define FILENAME "../res/20000x20000.json"
typedef std::pair<unsigned int, unsigned int> point;

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};


template <template <typename, typename, typename...> class M, typename K, typename V, typename ...Args>
inline V find_or_default(M<K,V,Args...> map, K key, V def) {
    auto it = map.find(key);
    if (it == map.end())
        return def;
    return it->second;
}