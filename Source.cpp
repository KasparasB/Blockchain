#include "Header.h"
#include "hash.h"

int main()
{
	Blockchain bChain = Blockchain();

	vector<User> Kappa;
	vector<Transaction> Operations;
	readUsers(Kappa, 1000);
	createTransaction(1000, 1000, Operations, Kappa);

	string Data = "";
	int bCount = 0;
	for (int i = 0; Operations.size() > 0; i++)
	{
		int random = rand() % Operations.size();

		Data += std::to_string(Operations[random].tID) + "," + Operations[random].from + "," + Operations[random].to + "," + std::to_string(Operations[random].amount);
		Operations.erase(Operations.begin() + random);

		if ( (i+1) % 100 == 0)
		{
			bChain.AddBlock(Block(bCount + 1, Data));
			Data = "";
			bCount++;
		}
	}

	system("PAUSE");
}