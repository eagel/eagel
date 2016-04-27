#include "daemon.hh"

#include <string>

#include "logger.hh"

namespace {

ea::logger logger("ea::daemon");

class daemon_i: public ea::daemon {
public:
	daemon_i(char * upstream, char *downstream);

	virtual ~daemon_i();
	virtual void startup() override;
	virtual void shutdown() override;
};

daemon_i::daemon_i(char * upstream, char *downstream) {
	// TODO
}

daemon_i::~daemon_i() {
	// TODO
}

void daemon_i::startup() {
	// TODO
}

void daemon_i::shutdown() {
	// TODO
}

}

namespace ea {

daemon::~daemon() {
	// TODO
}

daemon * daemon::create(char * upstream, char *downstream) {
	// TODO
	return new daemon_i(upstream, downstream);
}

} /* namespace ea */
