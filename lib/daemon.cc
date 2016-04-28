#include "daemon.hh"

#include <string>
#include <vector>
#include <mutex>

#include "logger.hh"

namespace {

ea::logger log("ea::daemon");

std::vector<ea::daemon *> daemons;
std::mutex daemon_mutex;

class daemon_i: public ea::daemon {
public:
	daemon_i(char * upstream, char *downstream);

	virtual ~daemon_i();
	virtual void startup() override;
	virtual bool isStartup() override;
	virtual void shutdown() override;
};

daemon_i::daemon_i(char * upstream, char *downstream) {
	// TODO
}

daemon_i::~daemon_i() {
	// TODO
	// TODO remove from daemons
}

void daemon_i::startup() {
	// TODO
}

bool daemon_i::isStartup() {
	// TODO
	return false;
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
	daemon * d = new daemon_i(upstream, downstream);

	{
		std::lock_guard<std::mutex> lock(daemon_mutex);
		daemons.push_back(d);
	}

	return d;
}

void daemon::release() {
	log.debug("release all daemons");
	std::lock_guard<std::mutex> lock(daemon_mutex);
	for (std::vector<daemon *>::iterator i = daemons.begin();
			i != daemons.end(); ++i) {
		delete *i;
	}
}

} /* namespace ea */
