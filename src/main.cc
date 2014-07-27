#include <main.hh>

namespace eagel {

const std::string main::MAJOR_VERSION = "0";
const std::string main::MINOR_VERSION = "0";
const std::string main::MICRO_VERSION = "0";
const std::string main::QUALIFIER = "DEV";

const std::string main::VERSION = main::MAJOR_VERSION + "."
		+ main::MINOR_VERSION + "." + main::MICRO_VERSION + "."
		+ main::QUALIFIER;

} /* namespace eagel */
