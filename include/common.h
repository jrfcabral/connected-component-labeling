#pragma once
#include <optional>
typedef std::pair<unsigned int, unsigned int> point;

struct pair_hash {
  inline std::size_t operator()(const std::pair<int, int> &v) const {
    return v.first * 31 + v.second;
  }
};
