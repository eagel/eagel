#ifndef EAGEL_MESSAGE_BASIC_MESSAGE_HH_
#define EAGEL_MESSAGE_BASIC_MESSAGE_HH_

#include "../main.hh"

#include "basic_data.hh"

namespace eagel {
namespace message {

class basic_message {
public:
	basic_message();
	basic_message(const basic_message &);
	virtual ~basic_message() = 0;

	virtual basic_message & operator=(const basic_message &) = 0;
	virtual operator std::string() const = 0;
	virtual basic_data & operator[](std::string) = 0;
};

} /* namespace message */
} /* namespace eagel */

#endif /* EAGEL_MESSAGE_BASIC_MESSAGE_HH_ */
