#ifndef EAGEL_Eagel_HH_
#define EAGEL_Eagel_HH_

#include <string>

namespace eagel {

class Eagel final {
	public:
		static const std::string MAJOR_VERSION;
		static const std::string MINOR_VERSION;
		static const std::string MICRO_VERSION;
		static const std::string QUALIFIER;

		static const std::string VERSION;

	private:
		Eagel();
		Eagel(const Eagel&);
		Eagel & operator =(const Eagel &);
	};

} /* namespace eagel */

#endif /* EAGEL_Eagel_HH_ */
