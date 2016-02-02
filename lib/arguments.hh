#ifndef EA_ARGUMENTS_HH_
#define EA_ARGUMENTS_HH_

namespace ea {

class arguments {
	void * _implementation;
public:
	typedef int type_t;

	static constexpr const type_t TYPE_VALUE = 1;
	static constexpr const type_t TYPE_FLAG = 2;
	static constexpr const type_t TYPE_CONFIG = 3;

	static constexpr const char * const NAME_PREFIX = "--";
	static constexpr const char * const ALIAS_PREFIX = "-";

	static const char * const TRUE;
	static const char * const FALSE;
	static const char * const NONE;

	arguments();
	arguments(const arguments & args);
	arguments(arguments && args);
	~arguments();

	arguments & operator=(const arguments & args);
	arguments & operator=(arguments && args);

	arguments & configure(const char * name, const char * alias, type_t type);

	arguments & parse(int argc, char **argv);

	const char * operator[](const char * name);
	const char * value(const char * name);
	const char * name();

	int errorSize();
	const char * errorName(int index);
	const char * errorMessage(int index);
};

} /* namespace ea */

#endif /* EA_ARGUMENTS_HH_ */