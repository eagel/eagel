#include <Record.hh>

#include "main.hh"

using namespace std;
using namespace eagel;

TEST_CASE(RecordTest) {
	Record record("key", "value");

	TEST_CHECK(record.key() == "key");
	TEST_CHECK(record.value() == "value");

	Record *record_pointer = new Record("name", "eagel");
	TEST_CHECK(record_pointer->key() == "name");
	TEST_CHECK(record_pointer->value() == "eagel");
	delete record_pointer;

	record = *record_pointer;

	TEST_CHECK(record.key() == "name");
	TEST_CHECK(record.value() == "eagel");
}
