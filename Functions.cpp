#include "hash.h"
#include "Header.h"

Block::Block(uint32_t nIndexIn, const string& sDataIn) : nIndex(nIndexIn), sData(sDataIn) {
	nNonce = -1;
	timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

string Block::GetHash()
{
	return sHash;
}

void Block::MineBlock(uint32_t nDifficulty) {
	int requiredNonce = 100000;
	char* cstr = new char[nDifficulty + 1];
	for (uint32_t i = 0; i < nDifficulty; ++i) {
		cstr[i] = '0';
	}
	cstr[nDifficulty] = '\0';

	string str(cstr);

	do {
		nNonce++;
		sHash = CalculateHash();
	} while (sHash.substr(0, nDifficulty) != str && nNonce < requiredNonce); // pridedamas nonce reikalavimas
	if (nNonce < requiredNonce)
	{
		//cout << "Block mined: " << sHash << " " << nNonce << endl; //Spausdinam nonce, kad patikrinti ar maziau uz 100k

		//cout << "sData: " << sData << endl;
	}
	else {
		requiredNonce *= 2;
		sHash = "1"; // priskiriamas 1, reiskia, kad buvo nespeta iskasti bloko
		cout << "Failed to mine a block: " << nNonce << endl;
	}
}

void Block :: printBlock()
{
	cout << "Index: " << nIndex << endl;
	cout << "Nonce: " << nNonce << endl;
	cout << "sHash: " << sHash << endl;
	cout << "Timestamp: " << timestamp << endl;
	cout << "Merkle: " << Merkle << endl;
}

void Blockchain::printBlockChain()
{
	for (int i = 0; i < vChain.size(); i++)
	{
		vChain[i].printBlock();
	}
}



inline string Block::CalculateHash() const {
	string hashable = "";

	hashable = std::to_string(nIndex) + std::to_string(nNonce) + sData + std::to_string(timestamp);

	return sha256(hashable);
}

Block Blockchain::GetLastBlock() const
{
	return vChain.back();
}

Blockchain::Blockchain() {
	vChain.emplace_back(Block(0, "Genesis Block"));
	nDifficulty = 3;
	//Mineblock();
	//vChain[0].
	
}

void Blockchain::AddBlock(Block bNew)
{
	bNew.sPrevHash = GetLastBlock().GetHash();
	bNew.MineBlock(nDifficulty);

		

	vChain.push_back(bNew);
}
void readUsers(vector<User>& Kappa, int n)
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 mt(rd());
	std::uniform_real_distribution<> Skaicius(100, 1000001);

	User temp;

	for (int i = 0; i < n; i++)
	{

		temp.setName("Vardas" + std::to_string(i));
		temp.setKey(sha256(temp.getName()));
		temp.setKappa(Skaicius(mt));

		Kappa.push_back(temp);
	}
}

void createTransaction(int nTransaction, int nUsers, vector<Transaction>& transactions, vector<User> users)
{

	//std::uniform_real_distribution<> rAmount(100, 1000001);

	std::random_device dr;  //Will be used to obtain a seed for the random number engine
	std::mt19937 tm(dr());
	
	string Data = ""; // hashuojama transakcijos informacija

	for (int i = 0; i < nTransaction; i++)
	{
		
		std::uniform_int_distribution<int> rUsersFrom(1, nUsers - 1);
		std::uniform_int_distribution<int> rUsersTo(1, nUsers - 1);


		int from = rUsersFrom(tm);
		int to = rUsersTo(tm);

		std::uniform_int_distribution<int> Coins(1, 1000001);

		int kappa = Coins(tm); // valiuta

		users[from].subKappa(kappa);
		users[to].addKappa(kappa);

		Data = sha256(users[from].getKey() + "," + users[to].getKey() + "," + std::to_string(kappa));

		Transaction temp = Transaction(Data, users[from].getKey(), users[to].getKey(), kappa, from, to);
		transactions.push_back(temp);
	}
}

void Block::MerkleRoot()
{
	while (IDs.size() > 1)
	{
		//cout << "\n\n";

		if (IDs.size() % 2 != 0)
			IDs.push_back(IDs.back());

		std::vector<string> newIDs;

		for (auto it = IDs.begin(); it != IDs.end(); it += 2)
		{
			string concat = (*it) + (*(it + 1));
			string newHash = sha256(concat);
			newIDs.push_back(newHash);
			//cout << newHash << std::endl;
		}

		IDs = newIDs;
	}
	Merkle = IDs[0];
	return;
}

void Blockchain::addMerkle(int Index, vector<string>IDs)
{
	vChain[Index].setIDs(IDs);
}