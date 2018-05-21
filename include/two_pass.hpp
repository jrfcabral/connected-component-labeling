#pragma once
#include "common.h"
#include <boost/pending/disjoint_sets.hpp>
#include <vector>

std::vector<std::vector<point>>
two_pass(std::vector<std::vector<uint8_t>> data);