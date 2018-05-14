#include "data_handling.hpp"

using namespace std;

const vector<vector<uint8_t>> load_file(std::string filename) {
  nlohmann::json j;
  ifstream file(filename);
  file >> j;
  return j;
}

void format_result(vector<vector<point>> result, ostream &os) {
  for (auto line : result) {
    nlohmann::json value(line);
    os << value << endl;
  }
}