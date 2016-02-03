#include "arguments.hh"

#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

namespace {
class argumentsImpl {
public:
	string _name;
	vector<string> _names;
	map<string, ea::arguments::type_t> _types;
	map<string, string> _aliases;
	map<string, string> _values;
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
				new argumentsImpl(
						*argumentsImpl::cast(args._implementation))) {
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
	(*argumentsImpl::cast(_implementation)) =
			*argumentsImpl::cast(args._implementation);
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
	argumentsImpl::cast(_implementation)->_names.push_back(name);
	argumentsImpl::cast(_implementation)->_aliases[alias] = name;
	argumentsImpl::cast(_implementation)->_types[name] = type;
	return *this;
}

arguments & arguments::parse(int argc, char **argv) {
	// set defaults
	for (string name : argumentsImpl::cast(_implementation)->_names) {
		if (TYPE_FLAG
				== argumentsImpl::cast(_implementation)->_types[name]) {
			argumentsImpl::cast(_implementation)->_values[name] =
					FALSE;
		} else {
			argumentsImpl::cast(_implementation)->_values[name] = NONE;
		}
	}

	// parse
	argumentsImpl::cast(_implementation)->_name = argv[0];
	vector<char *> args(argv + 1, argv + argc);
	int index = 0;
	for (vector<char *>::iterator i = args.begin(); i != args.end(); ++i) {
		string s = *i;
		if (0 == s.find(NAME_PREFIX)) {
			string name = s.substr(2);
			type_t type =
					argumentsImpl::cast(_implementation)->_types[name];
			if (0 == type) {
				argumentsImpl::cast(_implementation)->_errorsNames.push_back(
						s);
				argumentsImpl::cast(_implementation)->_errorsMessages.push_back(
						"Unknown argument");
			} else if (TYPE_FLAG == type) {
				argumentsImpl::cast(_implementation)->_values[name] =
						TRUE;
			} else {
				if (++i != args.end()) {
					argumentsImpl::cast(_implementation)->_values[name] =
							*i;
				} else {
					argumentsImpl::cast(_implementation)->_values[name] =
							NONE;
				}
			}
		} else if (0 == s.find(ALIAS_PREFIX)) {
			string alias = s.substr(1);
			string name =
					argumentsImpl::cast(_implementation)->_aliases[alias];
			type_t type =
					argumentsImpl::cast(_implementation)->_types[name];
			if (0 == type) {
				argumentsImpl::cast(_implementation)->_errorsNames.push_back(
						s);
				argumentsImpl::cast(_implementation)->_errorsMessages.push_back(
						"Unknown argument");
			} else if (TYPE_FLAG == type) {
				argumentsImpl::cast(_implementation)->_values[name] =
						TRUE;
			} else {
				if (++i != args.end()) {
					argumentsImpl::cast(_implementation)->_values[name] =
							*i;
				} else {
					argumentsImpl::cast(_implementation)->_values[name] =
							NONE;
				}
			}
		} else {
			// next index
			for (;
					index
							< argumentsImpl::cast(_implementation)->_names.size();
					++index) {
				string name =
						argumentsImpl::cast(_implementation)->_names[index];
				type_t type =
						argumentsImpl::cast(_implementation)->_types[name];
				if (TYPE_VALUE == type) {
					if (argumentsImpl::cast(_implementation)->_values[name]
							== string(NONE)) {
						break;
					}
				}
			}

			if (index
					>= argumentsImpl::cast(_implementation)->_names.size()) {
				argumentsImpl::cast(_implementation)->_errorsNames.push_back(
						s);
				argumentsImpl::cast(_implementation)->_errorsMessages.push_back(
						"Unknown argument");
			} else {
				string name =
						argumentsImpl::cast(_implementation)->_names[index];
				argumentsImpl::cast(_implementation)->_values[name] =
						s;
				++index;
			}
		}
	}
	return *this;
}

const char * arguments::operator[](const char * name) {
	return value(name);
}

const char * arguments::value(const char * name) {
	return argumentsImpl::cast(_implementation)->_values[name].c_str();
}

const char * arguments::name() {
	return argumentsImpl::cast(_implementation)->_name.c_str();
}

int arguments::errorSize() {
	return argumentsImpl::cast(_implementation)->_errorsNames.size();
}
const char * arguments::errorName(int index) {
	return argumentsImpl::cast(_implementation)->_errorsNames.at(index).c_str();
}
const char * arguments::errorMessage(int index) {
	return argumentsImpl::cast(_implementation)->_errorsMessages.at(
			index).c_str();
}

} /* namespace ea */
