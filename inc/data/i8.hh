#ifndef EAGEL_DATA_I8_HH_
#define EAGEL_DATA_I8_HH_

#include "basic_data.hh"

namespace eagel {
namespace data {

class i8: public basic_data {
public:
	i8() noexcept;
	i8(const i8 &) noexcept;
	i8(const i8 &&) noexcept;
	/*
	 * data_exception: means the script have error.
	 */
	i8(const script &) throw (data_exception);
	/*
	 * data_exception: means the serialized data is invalid.
	 */
	i8(const serialized &) throw (data_exception);
	virtual ~i8() noexcept;

	virtual basic_data & operator=(const basic_data &) throw(data_exception) override;

	/*
	 * convert data to string(script status)
	 */
	virtual operator script() const noexcept override;
	/*
	 * convert data to byte array(serialized status)
	 */
	virtual operator serialized() const noexcept override;

	virtual operator type_i8() const throw (data_exception) override;
	virtual operator type_i16() const throw (data_exception) override;
	virtual operator type_i32() const throw (data_exception) override;
	virtual operator type_i64() const throw (data_exception) override;

	virtual operator type_u8() const throw (data_exception) override;
	virtual operator type_u16() const throw (data_exception) override;
	virtual operator type_u32() const throw (data_exception) override;
	virtual operator type_u64() const throw (data_exception) override;

	virtual operator type_f32() const throw (data_exception) override;
	virtual operator type_f64() const throw (data_exception) override;

	virtual operator type_s() const throw (data_exception) override;
	virtual operator type_a() const throw (data_exception) override;
private:
	type_i8 _value;
};

} /* namespace data */
} /* namespace eagel */

#endif /* EAGEL_DATA_I8_HH_ */
