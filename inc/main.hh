#ifndef EAGEL_MAIN_HH_
#define EAGEL_MAIN_HH_

#include <string>

namespace eagel {

class main final {
	public:
		static const std::string MAJOR_VERSION;
		static const std::string MINOR_VERSION;
		static const std::string MICRO_VERSION;
		static const std::string QUALIFIER;

		static const std::string VERSION;

	private:
		main();
		main(const main&);
		main & operator =(const main &);
	};

} /* namespace eagel */

#endif /* EAGEL_MAIN_HH_ */
