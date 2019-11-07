#include "Header.h"
#include "hash.h"

int main()
{
	Blockchain bChain = Blockchain();

	Blockchain testChain = Blockchain();

	vector<User> Kappa;
	vector<Transaction> Operations;
	readUsers(Kappa, 1000);
	createTransaction(1000, 1000, Operations, Kappa);
	int count = 0; // Skaiciuojamas tikslus validziu transakciju kiekis
	vector<string> Data; // I si kintamaji dedami validzios transakcijos duomenys
	string DataT = ""; //Test data, kad skirta transakcijos patikrinimui
	int bCount = 0;

	vector<Transaction> OperationsFake = Operations;

	int randomArray[5][100] = { 0 };

	vector<Block> PossibleBlock; //Galimas blokas

	for (int i = 0; Operations.size() > 0; i++)
	{
		for (int y = 0; y < 5; y++) // 5 data blokai
		{
			string temp = ""; // laikina data, kuria desiu i Data vektoriu
			count = 0;
			OperationsFake = Operations;
			while (count != 100) // laukiama, kol kiekvienas prisipildys po 100 validzu transakciju
			{
				DataT = "";
				int random = rand() % OperationsFake.size(); // renkama random transakcija
				int* p;
				p = std::find(&randomArray[y][0], &randomArray[y][count], random);
				if (p != &randomArray[y][count]) continue;
				randomArray[y][count] = random;

				if (OperationsFake[random].amount > Kappa[OperationsFake[random].getFromID()].getKappa()) // Tikrinama, ar transakcija yra galima (balanso tikrinimas)
				{

					OperationsFake.erase(OperationsFake.begin() + random);
					createTransaction(1, Kappa.size(), OperationsFake, Kappa);
					continue;
				}

				count++; // validziu transakciju kiekis
				
				//Data = std::to_string(OperationsFake[random].tID) + "," + OperationsFake[random].from + "," + OperationsFake[random].to + "," + std::to_string(OperationsFake[random].amount);
				temp += OperationsFake[random].from + "," + OperationsFake[random].to + "," + std::to_string(OperationsFake[random].amount);
				DataT = OperationsFake[random].from + "," + OperationsFake[random].to + "," + std::to_string(OperationsFake[random].amount);
				if (sha256(DataT) != OperationsFake[random].tID)
				{
					cout << "Transakcija suklastota!" << endl;
				}
				//OperationsFake.erase(OperationsFake.begin() + random);
			}
			Data.push_back(temp);
			PossibleBlock.push_back(Block(y + 1, Data[y]));
			testChain.AddBlock(PossibleBlock[y]);
			
		}
		int sk = 0;
		bool search = true;
		while (search)
		{
			int randomBlock = rand() % PossibleBlock.size();

			if (PossibleBlock[randomBlock].GetHash() != "1")
			{
				std::sort(&randomArray[randomBlock][0], &randomArray[randomBlock][100]);
				//bChain.AddBlock(Block(bCount + 1, Data[randomBlock]));
				bChain.AddBlock(PossibleBlock[randomBlock]);
				cout << "Block mined: " << PossibleBlock[randomBlock].GetHash() << endl;
				for (int x = 0; x < 100; x++)
				{
					Operations.erase(Operations.begin() + (randomArray[randomBlock][x]-sk));
					sk++;
				}
				search = false;
				Data.clear();
				PossibleBlock.clear();
				//testChain.clear();
			}
			//PossibleBlock.erase(PossibleBlock.begin() + randomBlock);
		}
		

		//Operations.erase(Operations.begin() + random);

		

		/*if ( (count) % 100 == 0)
		{
			bChain.AddBlock(Block(bCount + 1, Data));
			

			Data = "";
			bCount++;
		}*/
	}


	system("PAUSE");
}