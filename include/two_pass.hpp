#pragma once
#include <vector>
#include <unordered_map>
#include <boost/pending/disjoint_sets.hpp>
#include <map>
#include <iostream>
#include <optional>
#include "common.h"

std::vector<std::vector<point>> two_pass(std::vector<std::vector<uint8_t>> data);