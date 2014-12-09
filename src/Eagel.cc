#include "../inc/Eagel.hh"

namespace eagel {

const std::string Eagel::MAJOR_VERSION = "0";
const std::string Eagel::MINOR_VERSION = "0";
const std::string Eagel::MICRO_VERSION = "0";
const std::string Eagel::QUALIFIER = "DEV";

const std::string Eagel::VERSION = Eagel::MAJOR_VERSION + "."
		+ Eagel::MINOR_VERSION + "." + Eagel::MICRO_VERSION + "."
		+ Eagel::QUALIFIER;

} /* namespace eagel */
