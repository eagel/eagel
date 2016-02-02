#ifndef EA_EXCEPTION_HH_
#define EA_EXCEPTION_HH_

namespace ea {

class exception {
	char * _message;
public:
	exception();
	exception(const char * const &message);
	exception(const exception &e);
	exception(exception &&e);
	~exception();

	const exception & operator =(const exception &e);
	const exception & operator =(exception &&e);
	const char * message();
};

} /* namespace ea */

#endif /* EA_EXCEPTION_HH_ */
