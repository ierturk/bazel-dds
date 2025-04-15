#define BOOST_TEST_MODULE SimpleBoostTest
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(testsuite_name)

// A simple test case
BOOST_AUTO_TEST_CASE(simple_test) {
    BOOST_TEST(1 + 1 == 2);  // Check equality
    BOOST_TEST(true);        // Check a boolean condition
}

// Another test case
BOOST_AUTO_TEST_CASE(string_test) {
    std::string str = "Boost.Test";
    BOOST_TEST(str == "Boost.Test");  // Check string equality
    BOOST_TEST(str != "Google Test"); // Check string inequality
}

BOOST_AUTO_TEST_SUITE_END()