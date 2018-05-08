#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "common.h"


const std::vector<std::vector<uint8_t>> load_file(std::string filename);