#include <eagel.hh>

#include <iostream>

int main(int argc, char *argv[]) {
	// initialize the library
	ea::eagel::initialize();

	// print version information
	std::cout << ea::eagel::name() << " " << ea::eagel::version() << std::endl;

	// parse arguments
	ea::arguments args;


	return 0;
}
