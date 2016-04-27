#include "daemon.hh"

#include <string>

#include "logger.hh"

namespace {

ea::logger logger("ea::daemon");

class daemonImpl: public ea::daemon {
public:
	daemonImpl(char * upstream, char *downstream);

	virtual ~daemonImpl();
	virtual void startup() override;
	virtual void shutdown() override;
};

daemonImpl::daemonImpl(char * upstream, char *downstream) {
	// TODO
}

daemonImpl::~daemonImpl() {
	// TODO
}

void daemonImpl::startup() {
	// TODO
}

void daemonImpl::shutdown() {
	// TODO
}

}

namespace ea {

daemon::~daemon() {
	// TODO
}

daemon * daemon::create(char * upstream, char *downstream) {
	// TODO
	return new daemonImpl(upstream, downstream);
}

} /* namespace ea */
