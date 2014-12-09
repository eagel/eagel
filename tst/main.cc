#include <Eagel.hh>

#define BOOST_AUTO_TEST_MAIN

#include <boost/test/unit_test.hpp>

using namespace std;
using namespace eagel;

/*
 * check the version is corrected.
 */
BOOST_AUTO_TEST_CASE( eagel_Main_version ) {
	BOOST_CHECK(string("0") == Eagel::MAJOR_VERSION);
	BOOST_CHECK(string("0") == Eagel::MINOR_VERSION);
	BOOST_CHECK(string("0") == Eagel::MICRO_VERSION);
	BOOST_CHECK(string("DEV") == Eagel::QUALIFIER);
	BOOST_CHECK(string("0.0.0.DEV") == Eagel::VERSION);
}

