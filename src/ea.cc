#include <eagel.hh>

#include <iostream>

int main(int argc, char *argv[]) {
	// initialize the library
	ea::eagel::initialize();

	// print version information
	std::cout << ea::eagel::name() << " " << ea::eagel::version() << std::endl;

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
			std::cout << args.errorName(i) << ": " << args.errorMessage(i)
					<< std::endl;
		}
	} else {
		// show arguments
		std::cout << args.value("name") << std::endl;
	}
	return 0;
}
