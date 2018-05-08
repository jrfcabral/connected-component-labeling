#include "one_pass.hpp"
using namespace std;

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

std::vector<std::vector<point>> one_pass(std::vector<std::vector<uint8_t>> data)
{
    stack<point> toExplore;
    vector<vector<point>> groups = {vector<point>()};

    vector<vector<int>> labels(data.size(), vector<int>(data[0].size(), 0));
    int currentLabel = 1;

    for (unsigned int i = 0; i < data.size(); i++)
    {
        for (unsigned int j = 0; j < data[i].size(); j++)
        {
            auto value = data[i][j];

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
                auto neighbours = get_neighbours(element.first, element.second, data.size(), data[i].size());
                for(const auto neighbour: neighbours) {
                    if (data[neighbour.first][neighbour.second] == 1 && labels[neighbour.first][neighbour.second] == 0) {
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
    return groups;
}