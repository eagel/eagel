#ifndef EA_EAGEL_HH_
#define EA_EAGEL_HH_

/*
 *	include the all headers for library.
 */
#include "exception.hh"
#include "arguments.hh"

namespace ea {

class eagel {
public :
	static const char * name();

	static const char * version();
	static int majorVersion();
	static int minorVersion();
	static int microVersion();

	static void initialize();
	static bool isInitialized();
};

} /* namespace ea */

#endif /* EA_EAGEL_HH_ */
