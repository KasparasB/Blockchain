#include "hash.h"
#include "Header.h"

Block::Block(uint32_t nIndexIn, const string& sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) {
	nNonce = -1;
	tTime = time(nullptr);
}

string Block::GetHash()
{
	return sHash;
}

void Block::MineBlock(uint32_t nDifficulty) {
	char cstr[nDifficulty + 1];
	for (uint32_t i = 0; i < nDifficulty; ++i) {
		cstr[i] = '0';
	}
	cstr[nDifficulty] = '\0';

	string str(cstr);

	do {
		nNonce++;
		sHash = CalculateHash();
	} while (sHash.substr(0, nDifficulty) != str);

	cout << "Block mined: " << sHash << endl;
}