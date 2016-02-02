#include "arguments.hh"

#include <iostream>

namespace {
class argumentsImpl {
public:
	argumentsImpl();
	argumentsImpl(const argumentsImpl &args);
	~argumentsImpl();

	argumentsImpl & operator=(const argumentsImpl &args);
};

argumentsImpl::argumentsImpl() {
	// TODO
}

argumentsImpl::argumentsImpl(const argumentsImpl &args) {
	// TODO
}

argumentsImpl::~argumentsImpl() {
	// TODO
}

argumentsImpl & argumentsImpl::operator=(const argumentsImpl &args) {
	// TODO
	return *this;
}

}

namespace ea {

const char * const arguments::TRUE = "true";
const char * const arguments::FALSE = "false";
const char * const arguments::NONE = "";

arguments::arguments() :
		_implementation(new argumentsImpl()) {
}

arguments::arguments(const arguments & args) :
		_implementation(
				new argumentsImpl(
						*static_cast<argumentsImpl *>(args._implementation))) {
}

arguments::arguments(arguments && args) :
		_implementation(args._implementation) {
	args._implementation = nullptr;
}

arguments::~arguments() {
	if (nullptr != _implementation) {
		delete static_cast<argumentsImpl *>(_implementation);
	}
}

arguments & arguments::operator=(const arguments & args) {
	(*static_cast<argumentsImpl *>(_implementation)) =
			*static_cast<argumentsImpl *>(args._implementation);
	return *this;
}
arguments & arguments::operator=(arguments && args) {
	delete static_cast<argumentsImpl *>(_implementation);
	_implementation = args._implementation;
	args._implementation = nullptr;
	return *this;
}

arguments & arguments::configure(const char * name, const char * alias,
		bool data) {
	// TODO
	return *this;
}

arguments & arguments::parse(int argc, const char **argv) {
	// TODO
	return *this;
}

const char * arguments::operator[](const char * name) {
	return value(name);
}

const char * arguments::value(const char * name) {
	// TODO
	return "";
}

} /* namespace ea */
