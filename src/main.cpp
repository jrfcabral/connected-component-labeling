#include <boost/program_options.hpp>
#include <iostream>

#include "data_handling.hpp"
#include "one_pass.hpp"
#include "two_pass.hpp"

using namespace std;
namespace options = boost::program_options;

int main(int argc, char **argv) {
  string algorithm;
  string filename;
  options::options_description dc("Usage: adjacent_cells_challenge [--algorithm] input-file");
  dc.add_options()(
      "algorithm",
      options::value<string>(&algorithm)->default_value("one-pass"),
      "one of \"one-pass\" which will use a breadth-first-search "
      "strategy or \"two-pass\" which will use the Rosenfeld algorithm")(
      "input-file", options::value<string>(&filename), "file to be analyzed");

  options::positional_options_description positional;
  positional.add("input-file", -1);

  options::variables_map vm;
  options::store(options::command_line_parser(argc, argv)
                     .options(dc)
                     .positional(positional)
                     .run(),
                 vm);
  options::notify(vm);
  if (vm.count("input-file")) {
    auto array = load_file(argv[1]);
    vector<vector<point>> result;
    if (algorithm == "one-pass") {
      result = one_pass(array);
    } else if (algorithm == "two-pass") {
      result = two_pass(array);
    } else {
      cout << dc;
      exit(-2);
    }

    format_result(result, cout);
  } else {
    cout << dc;
    exit(-1);
  }
}