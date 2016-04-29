#include "address.hh"

#include <string>
#include <sstream>
#include <algorithm>

#include "exception.hh"

namespace {

class address_i {
public:
	ea::address::protocol_t _protocol;
	std::string _host;
	unsigned short _port;
	std::string _description;

	address_i();

	void parse(const char * description);

	void refresh();

	static address_i * cast(void *implementation) {
		return static_cast<address_i *>(implementation);
	}
};

address_i::address_i() :
		_protocol(ea::address::UDP), _host("localhost"), _port(0), _description(
				"udp:localhost:0") {
}

void address_i::parse(const char * description) {
	ea::address::protocol_t protocol = ea::address::UDP;
	std::string host = "localhost";
	unsigned short port = 0;
	std::string d = description;

	// protocol
	std::string p = d.substr(0, 4);
	std::transform(p.begin(), p.end(), p.begin(), tolower);

	if (std::string("udp:") == p) {
		protocol = ea::address::UDP;
		d = d.substr(4, d.size());
	}
	if (std::string("tcp:") == p) {
		protocol = ea::address::TCP;
		d = d.substr(4, d.size());
	}

	// port
	std::size_t pi = std::distance(d.begin(),
			std::find(d.begin(), d.end(), ':'));
	if (pi != d.size()) {
		port = std::atoi(d.substr(pi + 1, d.size()).c_str());
		d = d.substr(0, pi);
	}

	// host
	host = d;

	// set
	_protocol = protocol;
	_host = host;
	_port = port;

	// refresh
	refresh();
}

void address_i::refresh() {
	// render
	std::stringstream s;
	switch (_protocol) {
	case ea::address::UDP:
		s << ea::address::PROTOCOL_UDP;
		break;
	case ea::address::TCP:
		s << ea::address::PROTOCOL_TCP;
		break;
	default:
		throw ea::exception("unknown address protocol");
	}

	s << ":" + _host + ":";
	s << _port;

	// set
	_description = s.str();
}

}

namespace ea {

address::address() :
		_implementation(new address_i) {
}

address::address(const char* description) :
		_implementation(new address_i) {
	address_i::cast(_implementation)->parse(description);
}

address::address(protocol_t protocol) :
		_implementation(new address_i) {
	address_i::cast(_implementation)->_protocol = protocol;
	address_i::cast(_implementation)->refresh();
}

address::address(protocol_t protocol, const char * host) :
		_implementation(new address_i) {
	address_i::cast(_implementation)->_protocol = protocol;
	address_i::cast(_implementation)->_host = host;
	address_i::cast(_implementation)->refresh();
}

address::address(protocol_t protocol, const char * host, unsigned short port) :
		_implementation(new address_i) {
	address_i::cast(_implementation)->_protocol = protocol;
	address_i::cast(_implementation)->_host = host;
	address_i::cast(_implementation)->_port = port;
	address_i::cast(_implementation)->refresh();
}

address::address(const address & addr) :
		_implementation(new address_i(*address_i::cast(addr._implementation))) {
}

address::address(address && addr) :
		_implementation(addr._implementation) {
	addr._implementation = nullptr;
}

address::~address() {
	if (nullptr != _implementation) {
		delete address_i::cast(_implementation);
	}
}

address & address::operator=(const address & addr) {
	*address_i::cast(_implementation) = *address_i::cast(addr._implementation);
	return *this;
}

address & address::operator=(address && addr) {
	delete address_i::cast(_implementation);
	_implementation = addr._implementation;
	addr._implementation = nullptr;
	return *this;
}

address::protocol_t address::getProtocol() {
	return address_i::cast(_implementation)->_protocol;
}

const char * address::getHost() {
	return address_i::cast(_implementation)->_host.c_str();
}

unsigned short address::getPort() {
	return address_i::cast(_implementation)->_port;
}

void address::setProtocol(protocol_t protocol) {
	address_i::cast(_implementation)->_protocol = protocol;
	address_i::cast(_implementation)->refresh();
}

void address::setHost(const char *host) {
	address_i::cast(_implementation)->_host = host;
	address_i::cast(_implementation)->refresh();

}

void address::setPort(unsigned short port) {
	address_i::cast(_implementation)->_port = port;
	address_i::cast(_implementation)->refresh();
}

const char * address::toString() {
	return address_i::cast(_implementation)->_description.c_str();
}

} /* namespace ea */
