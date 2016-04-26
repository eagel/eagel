#include <daemon.hh>

using namespace ea;

namespace {

class daemonImpl: public daemon {
public:
	daemonImpl(char * upstream, char *downstream);

	virtual ~daemonImpl();
	virtual void startup() override;
	virtual void shutdown() override;
};

daemonImpl::daemonImpl(char * upstream, char *downstream) {

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

daemon::~daemon(){

}

daemon * daemon::create(char * upstream, char *downstream) {
	return new daemonImpl(upstream, downstream);
}


} /* namespace ea */
