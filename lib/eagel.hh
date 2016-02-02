#ifndef EA_EAGEL_HH_
#define EA_EAGEL_HH_

/*
 *	include the all headers for library.
 */
#include "exception.hh"

namespace ea {

class eagel {
public :
	static char * version();
	static int majorVersion();
	static int minorVersion();
	static int microVersion();

	static void initialize();
};

} /* namespace ea */

#endif /* EA_EAGEL_HH_ */
