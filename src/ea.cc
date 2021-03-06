#include <arguments.hh>
#include <daemon.hh>
#include <eagel.hh>
#include <logger.hh>
#include <sys/signal.h>
#include <cstdlib>
#include <future>
#include <iostream>
#include <string>

using namespace std;

void usage() {
	cout << "Usage: ea [command] [options] [command arguments]" << endl;
	cout << "Commands:" << endl;
	cout << "\th, help\t\t: display the help information" << endl;
	cout << "\tv, version\t: display the version information" << endl;
	cout << "\td, daemon\t: startup in daemon mode" << endl;
	cout << "Options:" << endl;
	cout << "\t-u,--upstream\t: the upstream network configuration." << endl;
	cout << "\t-d,--downstream\t: the downstream network configuration."
			<< endl;
	cout << "\t-l,--log\t: the log level 0-5." << endl;
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

std::promise<int> daemon_promise;

void daemon_signal(int i) {
	daemon_promise.set_value(i);
}

void daemon(const char *upstream, const char *downstream) {
	ea::daemon * d = ea::eagel::createDaemon(upstream, downstream);

	std::future<int> f = daemon_promise.get_future();

	signal(SIGHUP, daemon_signal);
	signal(SIGINT, daemon_signal);
	signal(SIGTERM, daemon_signal);

	d->startup();

	int s = f.get();

	d->shutdown();

	delete d;
}

int main(int argc, char *argv[]) {
	// initialize the library
	ea::eagel::initialize();

	// configure arguments
	ea::arguments args;
	args.configure("command", "c", ea::arguments::TYPE_VALUE, "help");
	args.configure("upstream", "u", ea::arguments::TYPE_CONFIG,
			"udp:localhost:44886");
	args.configure("downstream", "d", ea::arguments::TYPE_CONFIG,
			"udp:localhost:44886");
	args.configure("log", "l", ea::arguments::TYPE_CONFIG, "0");
	// TODO add option

	// parse arguments
	args.parse(argc, argv);

	// configure log level
	ea::logger::setLevel(static_cast<ea::logger::level>(atoi(args["log"])));

	if (string(args["command"]) == string("help")
			|| string(args["command"]) == string("h")) {
		if (args.errorSize() > 0) {
			cerr << "Errors:" << endl;
			errors(args);
		}
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
			daemon(args["upstream"], args["downstream"]);
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
