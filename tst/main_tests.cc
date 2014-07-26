#include "main.hh"

#define BOOST_AUTO_TEST_MAIN

#include <boost/test/unit_test.hpp>

using namespace std;
using namespace eagel;

BOOST_AUTO_TEST_CASE( eagel_main_version ) {
	BOOST_CHECK(string("0") == main::MAJOR_VERSION);
	BOOST_CHECK(string("0") == main::MINOR_VERSION);
	BOOST_CHECK(string("0") == main::MICRO_VERSION);
	BOOST_CHECK(string("DEV") == main::QUALIFIER);
	BOOST_CHECK(string("0.0.0.DEV") == main::VERSION);
}
