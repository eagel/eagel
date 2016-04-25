#include "arguments.hh"

#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#include "exception.hh"

using namespace std;

namespace {
class argumentsImpl {
public:
	string _name;
	vector<string> _names;
	map<string, ea::arguments::type_t> _types;
	map<string, string> _aliases;
	map<string, string> _values;
	map<string, string> _defaults;
	vector<string> _errorsNames;
	vector<string> _errorsMessages;

	static argumentsImpl * cast(void *implementation) {
		return static_cast<argumentsImpl *>(implementation);
	}
};

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
				new argumentsImpl(*argumentsImpl::cast(args._implementation))) {
}

arguments::arguments(arguments && args) :
		_implementation(args._implementation) {
	args._implementation = nullptr;
}

arguments::~arguments() {
	if (nullptr != _implementation) {
		delete argumentsImpl::cast(_implementation);
	}
}

arguments & arguments::operator=(const arguments & args) {
	(*argumentsImpl::cast(_implementation)) = *argumentsImpl::cast(
			args._implementation);
	return *this;
}
arguments & arguments::operator=(arguments && args) {
	delete argumentsImpl::cast(_implementation);
	_implementation = args._implementation;
	args._implementation = nullptr;
	return *this;
}

arguments & arguments::configure(const char * name, const char * alias,
		type_t type) {
	switch (type) {
	case TYPE_VALUE:
		return configure(name, alias, type, NONE);
	case TYPE_FLAG:
		return configure(name, alias, type, FALSE);
	case TYPE_CONFIG:
		return configure(name, alias, type, TRUE);
	default:
		return configure(name, alias, type, NONE);
	}
}

arguments & arguments::configure(const char * name, const char * alias,
		type_t type, const char * default_value) {
	if (TYPE_VALUE != type && TYPE_FLAG != type && TYPE_CONFIG != type) {
		throw exception("unknown configuration type");
	}

	for (string s : argumentsImpl::cast(_implementation)->_names) {
		if (s == string(name)) {
			stringstream ss;
			ss << "The name \"";
			ss << name;
			ss << "\" already exist.";
			throw exception(ss.str().c_str());
		}
	}

	argumentsImpl::cast(_implementation)->_names.push_back(name);

	if (argumentsImpl::cast(_implementation)->_aliases[alias] != "") {
		stringstream ss;
		ss << "The alias \"";
		ss << alias;
		ss << "\" already exist.";
		throw exception(ss.str().c_str());
	}

	argumentsImpl::cast(_implementation)->_aliases[alias] = name;
	argumentsImpl::cast(_implementation)->_types[name] = type;
	argumentsImpl::cast(_implementation)->_defaults[name] = default_value;
	return *this;
}

arguments & arguments::parse(int argc, char **argv) {
	// set defaults
	clean();

	// parse
	argumentsImpl::cast(_implementation)->_name = argv[0];
	vector<char *> args(argv + 1, argv + argc);
	int index = 0;
	for (vector<char *>::iterator i = args.begin(); i != args.end(); ++i) {
		string s = *i;
		if (0 == s.find(NAME_PREFIX)) {
			string name = s.substr(2);
			type_t type = argumentsImpl::cast(_implementation)->_types[name];
			if (0 == type) {
				argumentsImpl::cast(_implementation)->_errorsNames.push_back(s);
				argumentsImpl::cast(_implementation)->_errorsMessages.push_back(
						"Unknown argument");
			} else if (TYPE_FLAG == type) {
				argumentsImpl::cast(_implementation)->_values[name] = TRUE;
			} else {
				if (++i != args.end()) {
					argumentsImpl::cast(_implementation)->_values[name] = *i;
				} else {
					argumentsImpl::cast(_implementation)->_values[name] = NONE;
					--i;
				}
			}
		} else if (0 == s.find(ALIAS_PREFIX)) {
			string alias = s.substr(1);
			string name = argumentsImpl::cast(_implementation)->_aliases[alias];
			type_t type = argumentsImpl::cast(_implementation)->_types[name];
			if (0 == type) {
				argumentsImpl::cast(_implementation)->_errorsNames.push_back(s);
				argumentsImpl::cast(_implementation)->_errorsMessages.push_back(
						"Unknown argument");
			} else if (TYPE_FLAG == type) {
				argumentsImpl::cast(_implementation)->_values[name] = TRUE;
			} else {
				if (++i != args.end()) {
					argumentsImpl::cast(_implementation)->_values[name] = *i;
				} else {
					argumentsImpl::cast(_implementation)->_values[name] = NONE;
					--i;
				}
			}
		} else {
			// next index
			for (; index < argumentsImpl::cast(_implementation)->_names.size();
					++index) {
				string name =
						argumentsImpl::cast(_implementation)->_names[index];
				type_t type = argumentsImpl::cast(_implementation)->_types[name];
				if (TYPE_VALUE == type) {
					break;
				}
			}

			if (index >= argumentsImpl::cast(_implementation)->_names.size()) {
				argumentsImpl::cast(_implementation)->_errorsNames.push_back(s);
				argumentsImpl::cast(_implementation)->_errorsMessages.push_back(
						"Unknown argument");
			} else {
				string name =
						argumentsImpl::cast(_implementation)->_names[index];
				argumentsImpl::cast(_implementation)->_values[name] = s;
				++index;
			}
		}
	}
	return *this;
}

arguments & arguments::clean() {
	// set defaults
	argumentsImpl::cast(_implementation)->_name = "";
	for (string name : argumentsImpl::cast(_implementation)->_names) {
		argumentsImpl::cast(_implementation)->_values[name] =
				argumentsImpl::cast(_implementation)->_defaults[name];
	}

	// clean error message
	argumentsImpl::cast(_implementation)->_errorsNames.clear();
	argumentsImpl::cast(_implementation)->_errorsMessages.clear();

	return *this;
}

arguments & arguments::reset() {
	// set defaults
	clean();

	// reset configuration
	argumentsImpl::cast(_implementation)->_names.clear();
	argumentsImpl::cast(_implementation)->_types.clear();
	argumentsImpl::cast(_implementation)->_aliases.clear();
	argumentsImpl::cast(_implementation)->_defaults.clear();

	return *this;
}

const char * arguments::operator[](const char * name) const {
	return value(name);
}

const char * arguments::value(const char * name) const {
	return argumentsImpl::cast(_implementation)->_values[name].c_str();
}

const char * arguments::name() const {
	return argumentsImpl::cast(_implementation)->_name.c_str();
}

int arguments::errorSize() const {
	return argumentsImpl::cast(_implementation)->_errorsNames.size();
}
const char * arguments::errorName(int index) const {
	return argumentsImpl::cast(_implementation)->_errorsNames.at(index).c_str();
}
const char * arguments::errorMessage(int index) const {
	return argumentsImpl::cast(_implementation)->_errorsMessages.at(index).c_str();
}

} /* namespace ea */
