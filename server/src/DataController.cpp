#include <iostream>
#include <string>
#include <memory>

class DataController
{
	public:
		DataController(std::shared_ptr<Database> databasePtrIn)
		{
			database = databasePtrIn;
		}
	
	
		void open(std::string dataFile, std::string journalFile)
		{
			primaryDS = std::make_shared<Datastore>(datafile);
			primaryJ = std::make_shared<Journal>(journalFile);
		}
	
		void close()
		{
			primaryDS = nullptr;
			primaryJ = nullptr;
		}
	
		std::string processStatement(std::string statement)
		{
			char delimiter = ':'; // Todo: This is currently an arbitrary delimiter
			int index = 0;
			while (statement[index] != ' ')
			{
				index = index + 1; // index will become the location of the first space
			}
			std::string type = statement.substr(0,index);
			std::string key = statement.substr(index + 1, statement.size()); // Move past the ' ' in the string
			
			if (type == "get"){
				return primaryDS.getRecord(key);
			}
			else if (type == "set") {
				//TODO
			}
			else if (type == "move") {
				//TODO
			}
			else if (type == "delete") {
				//TODO
			}
			else
			{
				return "Error: Invalid operation type.\n Valid operation types are {get | set | move | delete}."; // todo
			}
			
		}
		
		bool verify()
		{
			return false;
		}

	private:
		std::shared_ptr<Database> database;
		std::shared_ptr<Datastore> primaryDS;
		std::shared_ptr<Datastore> secondaryDS;
		std::shared_ptr<Journal> primaryJ;
		std::shared_ptr<Journal> secondaryJ;
		
		void rotate()
		{
			rotateJournal();
			rotateDatastores();
		}
					
		void rotateDatastores()	
		{
			return;// Todo
		}
							
		void rotateJournal()
		{
			database.suspendTransactions();			// Suspend the client transactions while swapping the pointers
			std::shared_ptr<Journal> temp = primaryJ; // Keep a pointer to the filled journal
			primaryJ = secondaryJ;					// Move the secondary journal to the location of the primary
			database.resumeTransactions();			// Resume the client transactions now that the pointers have been swapped.
			temp.applyToDatastore(primaryDS)			// Apply the filled journal to the primary datastore
			secondaryJ = nullptr;					// Erase the secondary datastore
		}

};





int main()
{
	std::cout << "Everything is well with the world.";
	return 0;
}