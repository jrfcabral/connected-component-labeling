#define BOOST_TEST_MODULE one_pass_tests
#include <boost/test/included/unit_test.hpp>
#include <functional>
#include "common.h"
#include "one_pass.hpp"
#include "two_pass.hpp"

BOOST_AUTO_TEST_SUITE(algorithms)
    BOOST_AUTO_TEST_CASE(small_input) {

        std::vector<std::vector<uint8_t>> dataset_1 = {
            {1, 1, 0, 1},
            {1, 1, 0, 1},
            {1, 1, 0, 1},
            {1, 0, 0, 1}
        };

        auto one_pass_result = one_pass(dataset_1);
        auto two_pass_result = two_pass(dataset_1);

        BOOST_CHECK_EQUAL(one_pass_result.size(), 2);
        BOOST_CHECK_EQUAL(one_pass_result[0].size(), 7);
        BOOST_CHECK_EQUAL(one_pass_result[1].size(), 4);

        BOOST_CHECK_EQUAL(two_pass_result.size(), 2);
        BOOST_CHECK_EQUAL(two_pass_result[0].size(), 7);
        BOOST_CHECK_EQUAL(two_pass_result[1].size(), 4);

    }

    BOOST_AUTO_TEST_CASE(empty_input) {

        std::vector<std::vector<uint8_t>> dataset_1 = {{}};

        auto one_pass_result = one_pass(dataset_1);
        auto two_pass_result = two_pass(dataset_1);

        BOOST_CHECK_EQUAL(one_pass_result.size(), 0);
        BOOST_CHECK_EQUAL(two_pass_result.size(), 0);
    }

BOOST_AUTO_TEST_SUITE_END()