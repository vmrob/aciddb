#include "DBContext.h"
#include "Result.h"

class ClientTransaction
{
public:
	ClientTransaction(DBContext context);
	~ClientTransaction();

	std::shared_ptr<Result> commit();
		
	void abort();

	void add(char** client_statements);		
};