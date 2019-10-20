#include "Header.h"
#include "hash.h"

int main()
{
	Blockchain bChain = Blockchain();

	vector<User> Kappa;

	void readUsers(Kappa, 1000);

	cout << "Mining block 1..." << endl;
	bChain.AddBlock(Block(1, "Block 1 Data"));

	cout << "Mining block 2..." << endl;
	bChain.AddBlock(Block(2, "Block 2 Data"));

	cout << "Mining block 3..." << endl;
	bChain.AddBlock(Block(3, "Block 3 Data"));

	system("PAUSE");
}