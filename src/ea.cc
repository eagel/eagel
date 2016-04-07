#include <eagel.hh>

#include <iostream>
#include <string>

using namespace std;

void usage() {
	cout << "Usage: ea [command] [options] [command arguments]" << endl;
	cout << "Commands:" << endl;
	cout << "\th, help\t\t: display the help information" << endl;
	cout << "\tv, version\t: display the version information" << endl;
	cout << "\td, daemon\t: display the version information" << endl;
}

void version() {
	cout << ea::eagel::name() << " " << ea::eagel::version() << endl;
}

void errors(const ea::arguments & args) {
	for (int i = 0; i < args.errorSize(); ++i) {
		cerr << "\t" << args.errorName(i) << "\t:" << args.errorMessage(i)
				<< endl;
	}
}

int main(int argc, char *argv[]) {
	// initialize the library
	ea::eagel::initialize();

	// configure arguments
	ea::arguments args;
	args.configure("command", "c", ea::arguments::TYPE_VALUE, "help");
	// TODO add option

	// parse arguments
	args.parse(argc, argv);

	if (string(args["command"]) == string("help")
			|| string(args["command"]) == string("h")) {
		usage();
	} else if (string(args["command"]) == string("version")
			|| string(args["command"]) == string("v")) {
		if (args.errorSize() > 0) {
			cerr << "Errors:" << endl;
			errors(args);
			usage();
		} else {
			version();
		}
	} else if (string(args["command"]) == string("daemon")
			|| string(args["command"]) == string("d")) {
		if (args.errorSize() > 0) {
			cerr << "Errors:" << endl;
			errors(args);
			usage();
		} else {
			// TODO start daemon
		}
	}

	// TODO add command

	else {
		cerr << "Errors:" << endl;
		cerr << "\t" << args["command"] << "\t:" << "Unknown command" << endl;
		errors(args);
		usage();
	}

	// destroy the library
	ea::eagel::destroy();

	return 0;
}
