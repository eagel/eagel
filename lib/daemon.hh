#ifndef EA_DAEMON_HH_
#define EA_DAEMON_HH_

namespace ea {

class daemon {
public:

	static daemon * create(char * upstream, char *downstream);

	virtual ~daemon();
	virtual void startup();
	virtual void shutdown();
};

} /* namespace ea */

#endif /* EA_DAEMON_HH_ */
