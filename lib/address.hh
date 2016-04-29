#ifndef EA_ADDRESS_HH_
#define EA_ADDRESS_HH_

namespace ea {

class address {
public:
	enum protocol_t {
		UDP, TCP
	};
	static constexpr const char * const PROTOCOL_UDP = "udp";
	static constexpr const char * const PROTOCOL_TCP = "tcp";
private:
	void * _implementation;
public:
	address();
	address(protocol_t protocol);
	address(protocol_t protocol, const char * host);
	address(protocol_t protocol, const char * host, unsigned short port);
	address(const char *description);
	address(const address & address);
	address(const address && address);
	virtual ~address();

	address & operator=(const address & address);
	address & operator=(const address && address);

	protocol_t getProtocol();
	const char * getHost();
	unsigned short getPort();

	void setProtocol(protocol_t protocol);
	void setHost(const char *);
	void setPort(unsigned short port);

	const char * toString();
};

} /* namespace ea */

#endif /* EA_ADDRESS_HH_ */
