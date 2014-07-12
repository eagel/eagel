#include <main.hh>

#include <iostream>

#include <boost/asio.hpp>

using namespace std;
using namespace boost;

int main(int argc, char *argv[]) {
	cout << "hello world" << endl;
	asio::io_service service;

	asio::deadline_timer timer(service,boost::posix_time::seconds(5));

	timer.wait();

	cout << "finish" << endl;

	return 0;
}
