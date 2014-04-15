#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Database
{
	public:
		Database(int externalPortIn, std::string filenameIn)
		{
			initialize(externalPortIn, filenameIn); 
		}
		
		void initialize(int externalPortIn, std::string filenameIn)
		{
			externalPort = externalPortIn;
			filename = filenameIn;
		}
	
		void listen()
		{
			//Hey, listen!
			//TODO
		}
		
		std::vector<std::string> processTransaction(Transaction t)
		{
			//TODO	
			return std::vector<std::string>();
		}
	
		void stop()
		{
			
		}
		
		void suspendTransactions()
		{
			transactionsRunnable = false;
		}
		
		void resumeTransactions()
		{
			transactionsRunnable = true;
		}
		
		bool verify()
		{
			return false;
		}
		
	private:
		std::string filename;
		DataController dc;
		int externalPort;
		bool transactionsRunnable;
	
		void handleClient()
		{
			
		}
};


int main()
{
	std::cout << "Everything is well with the world. ";
	return 0;
}