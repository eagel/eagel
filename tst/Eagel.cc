#include <Eagel.hh>

#include "main.hh"

using namespace std;
using namespace eagel;

TEST_CASE(EagelTest) {
	TEST_CHECK(string("0") == Eagel::MAJOR_VERSION);
	TEST_CHECK(string("0") == Eagel::MINOR_VERSION);
	TEST_CHECK(string("0") == Eagel::MICRO_VERSION);
	TEST_CHECK(string("DEV") == Eagel::QUALIFIER);
	TEST_CHECK(string("0.0.0.DEV") == Eagel::VERSION);
}
