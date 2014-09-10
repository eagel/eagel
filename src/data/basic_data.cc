#include "data/basic_data.hh"

namespace eagel {
namespace data {

basic_data::basic_data() noexcept {
}

basic_data::basic_data(const basic_data &) noexcept {
}

basic_data::basic_data(const basic_data &&) noexcept {
}

basic_data::basic_data(const script &) throw (data_exception) {
}

basic_data::basic_data(const serialized &) throw (data_exception) {
}

basic_data::~basic_data() noexcept {
}

} /* namespace data */
} /* namespace eagel */
