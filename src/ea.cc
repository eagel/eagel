#include <eagel.hh>

#include <iostream>
#include <string>

using namespace std;

void usage() {
	cout << "Usage: ea [command] [options] [command arguments]" << endl;
	cout << "Command:" << endl;
	cout << "\thelp\t: display the help information" << endl;
	cout << "\tversion\t: display the version information" << endl;
}

void version() {
	cout << ea::eagel::name() << " " << ea::eagel::version() << endl;
}

bool errors(const ea::arguments & args) {
	if (args.errorSize() > 0) {
		cerr << "Errors:" << endl;
	}

	for (int i = 0; i < args.errorSize(); ++i) {
		cerr << "\t" << args.errorName(i) << "\t:" << args.errorMessage(i) << endl;
	}
	if (args.errorSize() > 0) {
		return true;
	} else {
		return false;
	}
}

int main(int argc, char *argv[]) {
	// initialize the library
	ea::eagel::initialize();

	// configure arguments
	ea::arguments args;
	args.configure("command", "c", ea::arguments::TYPE_VALUE, "help");

	// parse arguments
	args.parse(argc, argv);

	if (string(args["command"]) == string("help")) {
		usage();
	} else if (string(args["command"]) == string("version")) {
		if (errors(args)) {
			usage();
		}else{
			version();
		}
	}

	// destroy the library
	ea::eagel::destroy();

	return 0;
}
