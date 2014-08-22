#include "data/data_exception.hh"

namespace eagel {
namespace data {

data_exception::data_exception(std::string message) :
		message("data_exception: " + message) {
}

data_exception::~data_exception() noexcept {
}

const char* data_exception::what() const noexcept {
	return message.c_str();
}
} /* namespace data */
} /* namespace eagel */

