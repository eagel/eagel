#ifndef EAGEL_MESSAGE_BASIC_DATA_HH_
#define EAGEL_MESSAGE_BASIC_DATA_HH_

#include "../main.hh"

#include <vector>

namespace eagel {
namespace message {

class basic_data {
public:
	typedef char type_i8;
	typedef short type_i16;
	typedef int type_i32;
	typedef long int type_i64;

	typedef unsigned char type_u8;
	typedef unsigned short type_u16;
	typedef unsigned int type_u32;
	typedef unsigned long int type_u64;

	typedef float type_f32;
	typedef double type_f64;

	typedef std::string type_s;
	typedef std::vector<unsigned char> type_a;

	basic_data();
	basic_data(const basic_data &);
	virtual ~basic_data() = 0;

	virtual basic_data & operator=(const basic_data &) = 0;
	virtual operator std::string() const = 0;
};

} /* namespace message */
} /* namespace eagel */

#endif /* EAGEL_MESSAGE_BASIC_DATA_HH_ */
