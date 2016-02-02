#ifndef EA_EAGEL_HH_
#define EA_EAGEL_HH_

namespace ea {

class eagel {
public :
	static char * version();
	static int majorVersion();
	static int minorVersion();
	static int microVersion();
	static char * qualifierVersion();

	static void initalize();
};

} /* namespace ea */

#endif /* EA_EAGEL_HH_ */
