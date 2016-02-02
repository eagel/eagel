#include "exception.hh"

#include <cstring>

using namespace std;

namespace ea {
exception::exception() :
		_message(nullptr) {
}
exception::exception(const char * const &message) :
		_message(strcpy(new char[strlen(message)], message)) {
}
exception::exception(const exception &e) :
		_message(strcpy(new char[strlen(e._message)], e._message)) {
}
exception::exception(const exception &&e) :
		_message(e._message) {
	e._message = nullptr;
}
exception::~exception() {
	if (nullptr != _message) {
		delete _message;
	}
}

const exception & exception::operator =(const exception &e) {
	if (nullptr != _message) {
		delete _message;
	}
	_message = strcpy(new char[strlen(e._message)], e._message);
	return &this;
}
const exception & exception::operator =(const exception &&e) {
	if (nullptr != _message) {
		delete _message;
	}
	_message = e._message;
	e._message = nullptr;
	return &this;
}

char * exception::message() {
	if (nullptr == _message) {
		return "";
	} else {
		return _message;
	}
}
} /* namespace ea */
