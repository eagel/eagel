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
		type_t type) {
	static_cast<argumentsImpl *>(_implementation)->_names.push_back(name);
	static_cast<argumentsImpl *>(_implementation)->_aliases[alias] = name;
	static_cast<argumentsImpl *>(_implementation)->_types[name] = type;
	return *this;
}

arguments & arguments::parse(int argc, char **argv) {
	// set defaults
	for (string name : static_cast<argumentsImpl *>(_implementation)->_names) {
		if (TYPE_FLAG
				== static_cast<argumentsImpl *>(_implementation)->_types[name]) {
			static_cast<argumentsImpl *>(_implementation)->_values[name] =
					FALSE;
		} else {
			static_cast<argumentsImpl *>(_implementation)->_values[name] = NONE;
		}
	}

	// parse
	static_cast<argumentsImpl *>(_implementation)->_name = argv[0];
	vector<char *> args(argv + 1, argv + argc);
	int index = 0;
	for (vector<char *>::iterator i = args.begin(); i != args.end(); ++i) {
		string s = *i;
		if (0 == s.find(NAME_PREFIX)) {
			string name = s.substr(2);
			type_t type =
					static_cast<argumentsImpl *>(_implementation)->_types[name];
			if (0 == type) {
				static_cast<argumentsImpl *>(_implementation)->_errorsNames.push_back(
						s);
				static_cast<argumentsImpl *>(_implementation)->_errorsMessages.push_back(
						"Unknown argument");
			} else if (TYPE_FLAG == type) {
				static_cast<argumentsImpl *>(_implementation)->_values[name] =
						TRUE;
			} else {
				if (++i != args.end()) {
					static_cast<argumentsImpl *>(_implementation)->_values[name] =
							*i;
				} else {
					static_cast<argumentsImpl *>(_implementation)->_values[name] =
							NONE;
				}
			}
		} else if (0 == s.find(ALIAS_PREFIX)) {
			string alias = s.substr(1);
			string name =
					static_cast<argumentsImpl *>(_implementation)->_aliases[alias];
			type_t type =
					static_cast<argumentsImpl *>(_implementation)->_types[name];
			if (0 == type) {
				static_cast<argumentsImpl *>(_implementation)->_errorsNames.push_back(
						s);
				static_cast<argumentsImpl *>(_implementation)->_errorsMessages.push_back(
						"Unknown argument");
			} else if (TYPE_FLAG == type) {
				static_cast<argumentsImpl *>(_implementation)->_values[name] =
						TRUE;
			} else {
				if (++i != args.end()) {
					static_cast<argumentsImpl *>(_implementation)->_values[name] =
							*i;
				} else {
					static_cast<argumentsImpl *>(_implementation)->_values[name] =
							NONE;
				}
			}
		} else {
			// next index
			for (;
					index
							< static_cast<argumentsImpl *>(_implementation)->_names.size();
					++index) {
				string name =
						static_cast<argumentsImpl *>(_implementation)->_names[index];
				type_t type =
						static_cast<argumentsImpl *>(_implementation)->_types[name];
				if (TYPE_VALUE == type) {
					if (static_cast<argumentsImpl *>(_implementation)->_values[name]
							== string(NONE)) {
						break;
					}
				}
			}

			if (index
					>= static_cast<argumentsImpl *>(_implementation)->_names.size()) {
				static_cast<argumentsImpl *>(_implementation)->_errorsNames.push_back(
						s);
				static_cast<argumentsImpl *>(_implementation)->_errorsMessages.push_back(
						"Unknown argument");
			} else {
				string name =
						static_cast<argumentsImpl *>(_implementation)->_names[index];
				static_cast<argumentsImpl *>(_implementation)->_values[name] =
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
	return static_cast<argumentsImpl *>(_implementation)->_values[name].c_str();
}

const char * arguments::name() {
	return static_cast<argumentsImpl *>(_implementation)->_name.c_str();
}

int arguments::errorSize() {
	return static_cast<argumentsImpl *>(_implementation)->_errorsNames.size();
}
const char * arguments::errorName(int index) {
	return static_cast<argumentsImpl *>(_implementation)->_errorsNames.at(index).c_str();
}
const char * arguments::errorMessage(int index) {
	return static_cast<argumentsImpl *>(_implementation)->_errorsMessages.at(
			index).c_str();
}

} /* namespace ea */
