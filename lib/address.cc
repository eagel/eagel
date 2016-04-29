#include "address.hh"

#include <string>

namespace {
class address_i: public ea::address {
public:
	protocol_t _protocol;
	std::string _host;
	unsigned short _port;
	std::string _description;

	address_i();

	static address_i * cast(void *implementation) {
		return static_cast<address_i *>(implementation);
	}
};

address_i::address_i() :
		_protocol(UDP), _host(""), _port(0), _description("udp::0") {
}

}

namespace ea {

address::address() :
		_implementation(new address_i) {
}


//	address(protocol_t protocol);
//	address(protocol_t protocol, const char * host);
//	address(protocol_t protocol, const char * host, unsigned short port);
//	address(const char *description);
//	address(const address & address);
//	address(const address && address);
//	virtual ~address();
//
//	address & operator=(const address & address);
//	address & operator=(const address && address);
//
//	protocol_t getProtocol();
//	const char * getHost();
//	unsigned short getPort();
//
//	void setProtocol(protocol_t protocol);
//	void setHost(const char *);
//	void setPort(unsigned short port);
//
//	const char * toString();

} /* namespace ea */
