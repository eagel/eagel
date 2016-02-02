#ifndef EA_ARGUMENTS_HH_
#define EA_ARGUMENTS_HH_

namespace ea {

class arguments {
	void * _implementation;
public:
	static const char * const TRUE;
	static const char * const FALSE;
	static const char * const NONE;

	arguments();
	arguments(const arguments & args);
	arguments(arguments && args);
	~arguments();

	arguments & operator=(const arguments & args);
	arguments & operator=(arguments && args);

	arguments & configure(const char * name, const char * alias, bool data);

	arguments & parse(int argc, const char **argv);

	const char * operator[](const char * name);
	const char * value(const char * name);
};

} /* namespace ea */

#endif /* EA_ARGUMENTS_HH_ */
