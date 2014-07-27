#ifndef EAGEL_MESSAGE_BASIC_DATA_HH_
#define EAGEL_MESSAGE_BASIC_DATA_HH_

#include "../main.hh"

namespace eagel {
namespace message {

class basic_data {
public:
	basic_data();
	basic_data(const basic_data &);
	virtual ~basic_data() = 0;

	virtual basic_data & operator=(const basic_data &) = 0;
	virtual operator std::string() const = 0;
};

} /* namespace message */
} /* namespace eagel */

#endif /* EAGEL_MESSAGE_BASIC_DATA_HH_ */
