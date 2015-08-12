#ifndef EAGEL_STORE_HH_
#define EAGEL_STORE_HH_

#include <string>

#include "Record.hh"

namespace eagel {

class Store {
public:
	Store(const std::string path);
	Store(const Store &) = delete;
	Store & operator =(const Store &) = delete;
	~Store();

	void put(const Record & record);
	Record get(const std::string & key);
};

} /* namespace eagel */

#endif /* EAGEL_STORE_HH_ */
