#include "ClientTransaction"


class Network
{
public:
	Network(ClientTransaction transaction);
	~Network();

	void send();

	Address address;	
};