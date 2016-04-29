#ifndef EA_DAEMON_HH_
#define EA_DAEMON_HH_

namespace ea {

class daemon {
public:

	static daemon * create(const char * upstream, const char *downstream);

	virtual ~daemon();
	virtual void startup() = 0;
	virtual bool isStartup() = 0;
	virtual void shutdown() = 0;
	virtual const char * id() = 0;

	/*
	 * release all daemons
	 */
	static void release();
protected:
	daemon() {
	}
private:
	daemon(const daemon&) = delete;
	daemon & operator =(const daemon&) = delete;
};

} /* namespace ea */

#endif /* EA_DAEMON_HH_ */
