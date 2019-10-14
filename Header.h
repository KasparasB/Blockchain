#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <time.h>

using std::vector;
using std::string;
using std::cout;
using std::endl;

class Block {
private:
	uint32_t nIndex;
	int64_t nNonce;
	string sData;
	string sHash;
	time_t tTime;

public:
	string sPrevHash;
	Block(uint32_t nIndexIn, const string& sDataIn);
	string GetHash();
	void MineBlock(uint32_t nDifficulty);
};

class Blockchain {
private:
	uint32_t nDifficulty;
	vector<Block> vChain;
	Block GetLastBlock() const;

public:
	Blockchain();
	void AddBlock(Block bNew);


};