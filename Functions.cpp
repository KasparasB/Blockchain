#include "hash.h"
#include "Header.h"

Block::Block(uint32_t nIndexIn, const string& sDataIn) : nIndex(nIndexIn), sData(sDataIn) {
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

inline string Block::CalculateHash() const {
	stringstream ss;
	ss << nIndex << tTime << sData << nNonce << sPrevHash;

	return sha256(ss.str());
}

Blockchain::Blockchain() {
	vChain.emplace_back(Block(0, "Genesis Block"));
	nDifficulty = 6;
}