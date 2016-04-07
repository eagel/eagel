#include "eagel.hh"

#include <cstdlib>
#include <string>

#include <config.h>

using namespace std;

namespace {

bool _intialized = false;

const char *_name = nullptr;
const char *_version = nullptr;
int _majorVersion = -1;
int _minorVersion = -1;
int _microVersion = -1;

}

namespace ea {

void eagel::initialize() {
	if (_intialized) {
		throw exception("already initialized.");
	} else {
		// name
		_name = PACKAGE_NAME;

		// version
		_version = VERSION;

		// major version
		string v = _version;
		_majorVersion = atoi(v.substr(0, v.find('.')).c_str());

		// minor version
		v = v.substr(v.find('.') + 1);
		_minorVersion = atoi(v.substr(0, v.find('.')).c_str());

		// micro version
		v = v.substr(v.find('.') + 1);
		_microVersion = atoi(v.c_str());
	}
	_intialized = true;
}

void eagel::destroy(){
	if(_intialized){
		_name = nullptr;
		_version = nullptr;
		_majorVersion = -1;
		_minorVersion = -1;
		_microVersion = -1;
	}else{
		throw exception("not initialized.");
	}
	_intialized = false;
}

bool eagel::isInitialized() {
	return _intialized;
}

const char * eagel::name() {
	return _name;
}

const char * eagel::version() {
	return _version;
}

int eagel::majorVersion() {
	return _majorVersion;
}

int eagel::minorVersion() {
	return _minorVersion;
}

int eagel::microVersion() {
	return _microVersion;
}

} /* namespace ea */
