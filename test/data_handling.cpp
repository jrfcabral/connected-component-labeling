#define BOOST_TEST_MODULE data_handling_tests
#include <boost/test/included/unit_test.hpp>
#include "data_handling.hpp"
#include <sstream>
BOOST_AUTO_TEST_SUITE(data_handling_suite)

    BOOST_AUTO_TEST_CASE(load_file_test)
    {
        BOOST_CHECK_NO_THROW(load_file("../../res/100x100.json"));
    }

    BOOST_AUTO_TEST_CASE(filter_small_groups) {
        std::stringstream ss;
        format_result({{{1,2}}}, ss);
        BOOST_CHECK_EQUAL(ss.str(), "");
    }

    BOOST_AUTO_TEST_CASE(format_groups) {
        std::stringstream ss;
        format_result({{{1,2}, {3,4}, {5,6}, {7,9}}, {{0,1}, {2,3}},{{100,22}, {100,23}}}, ss);
        int compare = ss.str().compare("[[1,2],[3,4],[5,6],[7,9]]\n[[0,1],[2,3]]\n[[100,22],[100,23]]\n");
        BOOST_CHECK_EQUAL(0, compare);
    }

BOOST_AUTO_TEST_SUITE_END()