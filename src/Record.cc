#include "Record.hh"

namespace eagel {

using namespace std;

Record::Record(const string &key, const string &value) :
		_key(key), _value(value) {
}

Record::~Record() {
}

std::string Record::key() {
	return _key;
}

std::string Record::value() {
	return _value;
}

} /* namespace eagel */
