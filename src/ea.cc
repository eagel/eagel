#include <eagel.hh>

#include <string>

ea::logger logger("ea");

int main(int argc, char *argv[]) {
	// initialize the library
	ea::eagel::initialize();

	// parse arguments
	ea::arguments args;

	// configure
	args.configure("name", "n", args.TYPE_VALUE);
	args.configure("daemon", "d", args.TYPE_FLAG);
	args.configure("port", "p", args.TYPE_CONFIG);

	// parse
	args.parse(argc, argv);

	// show result
	if (0 != args.errorSize()) {
		// show errors
		for (int i = 0; i < args.errorSize(); ++i) {
			logger.fatal(
					(std::string(args.errorName(i)) + ": "
							+ std::string(args.errorMessage(i))).c_str());
		}
	} else {
		// show arguments
		logger.fatal("TODO");
	}

	return 0;
}
