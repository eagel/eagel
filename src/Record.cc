#include <Record.hh>

#include <type_traits>

namespace eagel {

using namespace std;

Record::Record(const string &key, const string &value) :
		_key(key), _value(value) {
}

Record::Record(const Record & record) :
		_key(record._key), _value(record._value) {
}

Record::Record(const Record && record) :
		_key(move(record._key)), _value(move(record._value)) {
}

Record::~Record() {
}

Record & Record::operator=(const Record & record) {
	_key = record._key;
	_value = record._value;
	return *this;
}

Record & Record::operator=(const Record && record) {
	_key = move(record._key);
	_value = move(record._value);
	return *this;
}

std::string Record::key() {
	return _key;
}

std::string Record::value() {
	return _value;
}

} /* namespace eagel */
