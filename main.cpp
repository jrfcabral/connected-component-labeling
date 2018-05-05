#include <stdio.h>
#include <fstream>
#include <iostream>
#include <stack>
#include <chrono>
#include "json.hpp"
using namespace std;
using namespace chrono;

#define FILENAME "../res/10000x10000.json"
typedef pair<unsigned int, unsigned int> point;

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

const vector<point> get_neighbours(unsigned int x, unsigned int y, unsigned int xsize, unsigned int ysize)
{
    vector<point> result;
    if (x > 0)
        result.push_back(point(x - 1, y));
    if (y > 0)
        result.push_back(point(x, y - 1));
    if (x < xsize - 1)
        result.push_back(point(x + 1, y));
    if (y < ysize - 1)
        result.push_back(point(x, y + 1));
    return result;
}

int main()
{
    auto array = load_file(FILENAME);
    cout << "done loading file" << endl;
    stack<point> toExplore;
    vector<vector<point>> groups = {vector<point>()};

    vector<vector<int>> labels(array.size(), vector<int>(array[0].size(), 0));
    int currentLabel = 1;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    for (unsigned int i = 0; i < array.size(); i++)
    {
        for (unsigned int j = 0; j < array[i].size(); j++)
        {
            auto value = array[i][j];

            if (value == 1 && labels[i][j] == 0)
            {
                labels[i][j] = currentLabel;
                toExplore.push(point(i, j));
                groups.at(currentLabel-1).push_back(point(i,j));
            }
            while (!toExplore.empty())
            {
                point element = toExplore.top();
                toExplore.pop();
                auto neighbours = get_neighbours(element.first, element.second, array.size(), array[i].size());
                for(const auto neighbour: neighbours) {
                    if (array[neighbour.first][neighbour.second] == 1 && labels[neighbour.first][neighbour.second] == 0) {
                        labels[neighbour.first][neighbour.second] = currentLabel;
                        groups.at(currentLabel-1).push_back(neighbour);
                        toExplore.push(neighbour);
                    }
                }
                if (toExplore.empty()){
                    currentLabel++;
                    groups.push_back(vector<point>());
                }
            }
        }
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    format_result(groups);
    cout << duration;


}