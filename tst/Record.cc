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

	record = *record_pointer;
	delete record_pointer;

	TEST_CHECK(record.key() == "name");
	TEST_CHECK(record.value() == "eagel");

	Record a("a", "a");
	Record b("b", "b");
	Record c = move(a);
	Record d("d", "d");
	d = move(b);

	TEST_CHECK(c.key() == "a");
	TEST_CHECK(c.value() == "a");

	TEST_CHECK(d.key() == "b");
	TEST_CHECK(d.value() == "b");
}
