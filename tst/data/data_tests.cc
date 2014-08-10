#include <type_traits>

#include <boost/test/unit_test.hpp>

#include "data/basic_data.hh"

using namespace std;
using namespace eagel;
using namespace data;

/*
 * check all data type is corrected.
 */
BOOST_AUTO_TEST_CASE( eagel_data_types ) {
	BOOST_REQUIRE(1 == sizeof(basic_data::type_i8));
	BOOST_REQUIRE(is_signed<basic_data::type_i8>::value);

	BOOST_REQUIRE(2 == sizeof(basic_data::type_i16));
	BOOST_REQUIRE(is_signed<basic_data::type_i16>::value);

	BOOST_REQUIRE(4 == sizeof(basic_data::type_i32));
	BOOST_REQUIRE(is_signed<basic_data::type_i32>::value);

	BOOST_REQUIRE(8 == sizeof(basic_data::type_i64));
	BOOST_REQUIRE(is_signed<basic_data::type_i64>::value);

	BOOST_REQUIRE(1 == sizeof(basic_data::type_u8));
	BOOST_REQUIRE(is_unsigned<basic_data::type_u8>::value);

	BOOST_REQUIRE(2 == sizeof(basic_data::type_u16));
	BOOST_REQUIRE(is_unsigned<basic_data::type_u16>::value);

	BOOST_REQUIRE(4 == sizeof(basic_data::type_u32));
	BOOST_REQUIRE(is_unsigned<basic_data::type_u32>::value);

	BOOST_REQUIRE(8 == sizeof(basic_data::type_u64));
	BOOST_REQUIRE(is_unsigned<basic_data::type_u64>::value);

	BOOST_REQUIRE(4 == sizeof(basic_data::type_f32));
	BOOST_REQUIRE(is_signed<basic_data::type_f32>::value);

	BOOST_REQUIRE(8 == sizeof(basic_data::type_f64));
	BOOST_REQUIRE(is_signed<basic_data::type_f64>::value);
}
