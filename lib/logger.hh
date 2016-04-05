#ifndef EA_LOGGER_HH_
#define EA_LOGGER_HH_

namespace ea {

class logger {
public:
	enum level {
		FATAL, ERROR, WARN, INFO, DEBUG, TRACE
	};

private:
	static level _level;
	void * _implementation;
public:
	logger(const char *name);
	~logger();

	static void setLevel(level l) {
		_level = l;
	}

	void log(level l, const char *message);

	void fatal(const char *message) {
		log(FATAL, message);
	}

	void error(const char *message) {
		log(ERROR, message);
	}

	void warn(const char *message) {
		log(WARN, message);
	}

	void info(const char *message) {
		log(INFO, message);
	}

	void debug(const char *message) {
		log(DEBUG, message);
	}

	void trace(const char *message) {
		log(TRACE, message);
	}
};

} /* namespace ea */

#endif /* EA_LOGGER_HH_ */
