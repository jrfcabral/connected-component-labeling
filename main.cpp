#include <iostream>
#include <chrono>
#include "data_handling.hpp"
#include "one_pass.hpp"
#include "two_pass.hpp"
using namespace std;
using namespace chrono;

int main()
{
    auto array = load_file(FILENAME);
    cout << "done loading file" << endl;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    two_pass(array);

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout << duration;


}