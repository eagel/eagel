#include "logger.hh"

#include <string>
#include <mutex>
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <chrono>

using namespace std;

namespace {
class loggerImpl {
public:
	string _name;

	loggerImpl(const char *name) :
			_name(name) {
	}

	static loggerImpl * cast(void *implementation) {
		return static_cast<loggerImpl *>(implementation);
	}
};
}

namespace ea {

logger::level logger::_level = logger::FATAL;

mutex logger_mutex;

logger::logger(const char* name) :
		_implementation(new loggerImpl(name)) {
}

logger::~logger() {
}

void logger::log(level l, const char * message) {
	if (l > _level) {
		cout << "return" << endl;
		return;
	}

	lock_guard<mutex> lock(logger_mutex);
	ostringstream buffer;

	chrono::system_clock::time_point now = chrono::system_clock::now();
	chrono::milliseconds ms = chrono::duration_cast<chrono::milliseconds>(
			now.time_since_epoch());

	time_t t = chrono::system_clock::to_time_t(now);

	tm *m = localtime(&t);

	buffer << put_time(m, "%Y-%m-%d %H:%M:%S %z ") << setw(3) << setfill('0')
			<< ms.count() % 1000;

	switch (l) {
	case FATAL:
		buffer << " [FATAL]\t";
		break;
	case ERROR:
		buffer << " [ERROR]\t";
		break;
	case WARN:
		buffer << " [WARN]\t";
		break;
	case INFO:
		buffer << " [INFO]\t";
		break;
	case DEBUG:
		buffer << " [DEBUG]\t";
		break;
	case TRACE:
		buffer << " [TRACE]\t";
		break;
	}

	buffer << loggerImpl::cast(_implementation)->_name << " : " << message;
	if (l > WARN) {
		cout << buffer.str() << endl;
	}else{
		cerr << buffer.str() << endl;
	}
}

} /* namespace ea */
