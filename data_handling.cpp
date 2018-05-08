#include "data_handling.hpp"

using namespace std;


const vector<vector<uint8_t>> load_file(std::string filename)
{
    nlohmann::json j;
    ifstream file(filename);
    file >> j;
    return j;
}

const string format_result(vector<vector<point>> result) {
    for (auto line: result){
        nlohmann::json value(line);
        cout << value << endl;
    }
    return("lol");
}