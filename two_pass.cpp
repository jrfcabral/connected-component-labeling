#include "two_pass.hpp"
using namespace std;
inline static const vector<int> get_neighbours(unsigned int x, unsigned int y, vector<vector<int>> &labels)
{
    vector<int> result;
    result.reserve(2);
    if (x > 0)
        result.push_back(labels[x - 1][y]);
    if (y > 0)
        result.push_back(labels[x][y - 1]);

    return result;
}

std::vector<std::vector<point>> two_pass(std::vector<std::vector<uint8_t>> data)
{
    std::vector<std::vector<int>> labels(data.size(), std::vector<int>(data[0].size(), 0));
    unordered_map<int, vector<point>> groups;
    unsigned int *rank = new unsigned int[data.size() * (data[0].size()/2)];
    unsigned int *parent = new unsigned int[data.size() * (data[0].size()/2)];

    boost::disjoint_sets<unsigned int *, unsigned int *> ds(rank, parent);

    unsigned int currentLabel = 1;

    for (unsigned int i = 0; i < data.size(); i++)
    {
        for (unsigned int j = 0; j < data[i].size(); j++)
        {
            if (data[i][j] != 0)
            {
                auto neighbours = get_neighbours(i, j, labels);
                auto limits = std::minmax_element(neighbours.begin(), neighbours.end());
                int min = *limits.first;
                int max = *limits.second;
                if ( (min == 0 && max == 0) || limits.first == neighbours.end())
                {
                    ds.make_set(currentLabel);
                    labels[i][j] = currentLabel++;
                }
                else if (min == 0)
                {
                    labels[i][j] = max;
                }
                else if (!neighbours.empty())
                {
                    labels[i][j] = min;
                    ds.union_set(max, min);
                }
            }
        }
    }

    for(unsigned int i = 0; i < labels.size(); i++) {
        for(unsigned int j = 0; j < labels[i].size(); j++) {
            labels[i][j] = ds.find_set(labels[i][j]);
        }
    }

    delete rank;
    delete parent;
    return {};
}
