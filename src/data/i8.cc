#include <data/i8.hh>

namespace eagel {
namespace data {

using namespace std;

i8::i8() noexcept:basic_data(),_value(0) {
}

i8::i8(const i8 & value) noexcept:basic_data(value),_value(value) {
}

i8::i8(const i8 && value) noexcept:basic_data(value),_value(value) {
}

i8::i8(const script &script) throw (data_exception) :basic_data(script),
		_value(0) {
	// TODO implement the i8 create by script
	throw data_exception("not support create i8 by script");
}

i8::i8(const serialized &serialized) throw (data_exception) :
		basic_data(serialized), _value(0) {
	// TODO implement the i8 create by serialized data
	throw data_exception("not support create i8 by serialized data");
}

i8::~i8() noexcept {
}

basic_data & i8::operator=(const basic_data & data) throw (data_exception) {
	const i8 * c = dynamic_cast<const i8 *>(&data);
	if (c) {
		this->_value = c->_value;
	} else {
		// TODO it should support ix, ux.
		throw data_exception(
				"can't assign " + string(typeid(data).name())
						+ " value to i8.");
	}
	return *this;
}

i8::operator i8::script() const noexcept {
	// TODO to support i8 to script data
	throw data_exception("not support i8 to script data");
}

i8::operator i8::serialized() const noexcept {
	// TODO to support i8 to serialized data.
	throw data_exception("not support i8 to serialized data");
}

i8::operator i8::type_i8() const throw (data_exception) {
	return _value;
}

i8::operator i8::type_i16() const throw (data_exception) {
	return _value;
}

i8::operator i8::type_i32() const throw (data_exception) {
	return _value;
}

i8::operator i8::type_i64() const throw (data_exception) {
	return _value;
}

i8::operator i8::type_u8() const throw (data_exception) {
	throw data_exception("can not from i8 to type_u8");
}

i8::operator i8::type_u16() const throw (data_exception) {
	throw data_exception("can not from i8 to type_u16");
}

i8::operator i8::type_u32() const throw (data_exception) {
	throw data_exception("can not from i8 to type_u32");
}

i8::operator i8::type_u64() const throw (data_exception) {
	throw data_exception("can not from i8 to type_u64");
}

i8::operator i8::type_f32() const throw (data_exception) {
	return _value;
}

i8::operator i8::type_f64() const throw (data_exception) {
	return _value;
}

i8::operator i8::type_b() const throw (data_exception) {
	throw data_exception("can not from i8 to type_b");
}

i8::operator i8::type_s() const throw (data_exception) {
	throw data_exception("can not from i8 to type_s");
}

i8::operator i8::type_a() const throw (data_exception) {
	throw data_exception("can not from i8 to type_a");
}

}
/* namespace data */
} /* namespace eagel */
