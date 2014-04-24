#include <string>

class DBContext
{
public:
	DBContext(std::string address);
	~DBContext();
private:
	std::string address;
	bool connected;
	bool error;
};