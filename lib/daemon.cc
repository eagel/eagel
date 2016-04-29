#include "daemon.hh"

#include <string>
#include <vector>
#include <mutex>
#include <algorithm>

#include <uuid/uuid.h>

#include "logger.hh"
#include "address.hh"

namespace {

ea::logger log("ea::daemon");

std::vector<ea::daemon *> daemons;
std::mutex daemon_mutex;

class daemon_i: public ea::daemon {
	std::string _id;
	ea::address _upstream;
	ea::address _downstream;
public:
	daemon_i(const char * upstream, const char *downstream);

	virtual ~daemon_i();
	virtual void startup() override;
	virtual bool isStartup() override;
	virtual void shutdown() override;
	virtual const char * id() override;
};

daemon_i::daemon_i(const char * upstream, const char *downstream) :
		_id(), _upstream(), _downstream() {
	// generate the id
	uuid_t u;
	uuid_string_t us;
	uuid_generate(u);
	uuid_unparse(u, us);
	_id = us;

	log.debug(("create daemon: " + _id).c_str());

	if (nullptr != upstream) {
		// TODO parse address
	}

	if (nullptr != downstream) {
		// TODO parse address
	}

	// TODO
}

daemon_i::~daemon_i() {
	log.debug(("release daemon: " + _id).c_str());
	// TODO
}

void daemon_i::startup() {
	log.debug(("startup daemon: " + _id).c_str());
	// TODO
}

bool daemon_i::isStartup() {
	// TODO
	return false;
}

void daemon_i::shutdown() {
	log.debug(("shutdown daemon: " + _id).c_str());
	// TODO
}

const char * daemon_i::id() {
	// TODO
	return nullptr;
}

}

namespace ea {

daemon::~daemon() {
	std::lock_guard<std::mutex> lock(daemon_mutex);
	std::vector<daemon *>::iterator i = std::find(daemons.begin(),
			daemons.end(), this);
	if (i != daemons.end()) {
		daemons.erase(i);
	}
}

daemon * daemon::create(const char * upstream, const char *downstream) {
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
