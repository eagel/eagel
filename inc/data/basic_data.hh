#ifndef EAGEL_DATA_BASIC_DATA_HH_
#define EAGEL_DATA_BASIC_DATA_HH_

#include <vector>

#include "data_exception.hh"

namespace eagel {
namespace data {

/*
 * the data have four types of status.
 *
 * 1. script: using string data describe the data structure.
 * 2. serialized: the data store to byte array.
 * 3. basic: using the language basic type to describe the type like "type_i8".
 * 4. normal: using framework defined type to describe the data.
 */
class basic_data {
public:
	/*
	 * the script status data
	 */
	typedef std::string script;
	/*
	 * the serialized status data
	 */
	typedef std::vector<unsigned char> serialized;

	/*
	 * 8 bit integer
	 */
	typedef char type_i8;
	/*
	 * 16 bit integer
	 */
	typedef short type_i16;
	/*
	 * 32 bit integer
	 */
	typedef int type_i32;
	/*
	 * 64 bit integer
	 */
	typedef long int type_i64;

	/*
	 * 8 bit unsigned integer
	 */
	typedef unsigned char type_u8;
	/*
	 * 16 bit unsigned integer
	 */
	typedef unsigned short type_u16;
	/*
	 * 32 bit unsigned integer
	 */
	typedef unsigned int type_u32;
	/*
	 * 64 bit unsigned integer
	 */
	typedef unsigned long long type_u64;

	/*
	 * 32 bit float
	 */
	typedef float type_f32;
	/*
	 * 64 bit float
	 */
	typedef double type_f64;

	/*
	 * string data type
	 */
	typedef char * type_s;
	/*
	 * byte array data type
	 */
	typedef unsigned char * type_a;

	basic_data() noexcept;
	basic_data(const basic_data &) noexcept;
	basic_data(const basic_data &&) noexcept;
	/*
	 * data_exception: means the script have error.
	 */
	basic_data(const script &) throw (data_exception);
	/*
	 * data_exception: means the serialized data is invalid.
	 */
	basic_data(const serialized &) throw (data_exception);
	virtual ~basic_data() noexcept;

	virtual basic_data & operator=(const basic_data &) throw(data_exception) = 0;

	/*
	 * convert data to string(script status)
	 */
	virtual operator script() const noexcept = 0;
	/*
	 * convert data to byte array(serialized status)
	 */
	virtual operator serialized() const noexcept = 0;

	virtual operator type_i8() const throw (data_exception) = 0;
	virtual operator type_i16() const throw (data_exception) = 0;
	virtual operator type_i32() const throw (data_exception) = 0;
	virtual operator type_i64() const throw (data_exception) = 0;

	virtual operator type_u8() const throw (data_exception) = 0;
	virtual operator type_u16() const throw (data_exception) = 0;
	virtual operator type_u32() const throw (data_exception) = 0;
	virtual operator type_u64() const throw (data_exception) = 0;

	virtual operator type_f32() const throw (data_exception) = 0;
	virtual operator type_f64() const throw (data_exception) = 0;

	virtual operator type_s() const throw (data_exception) = 0;
	virtual operator type_a() const throw (data_exception) = 0;
};

} /* namespace data */
} /* namespace eagel */

#endif /* EAGEL_DATA_BASIC_DATA_HH_ */
