#define BOOST_TEST_MODULE test module name
#include <boost/test/included/unit_test.hpp>
#include "data_handling.hpp"
#include <sstream>
BOOST_AUTO_TEST_SUITE(data_handling_suite)

    BOOST_AUTO_TEST_CASE(load_file_test)
    {
        BOOST_CHECK_NO_THROW(load_file("../../res/100x100.json"));
    }

    BOOST_AUTO_TEST_CASE(format_output_test) {
        std::stringstream ss;
        format_result({{{1,2}}}, ss);
        std::cout << ss.str();
        BOOST_CHECK_EQUAL(ss.str(), "");
    }

BOOST_AUTO_TEST_SUITE_END()