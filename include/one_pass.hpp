#pragma once
#include <stack>
#include <stdint.h>
#include <vector>

#include "common.h"

std::vector<std::vector<point>>
one_pass(std::vector<std::vector<uint8_t>> data);