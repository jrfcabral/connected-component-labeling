#pragma once
#include "common.h"
#include "json.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

const std::vector<std::vector<uint8_t>> load_file(std::string filename);
void format_result(std::vector<std::vector<point>> result, std::ostream &os);
