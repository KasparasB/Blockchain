#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <time.h>
#include <sstream>
#include <chrono>
#include <fstream>
#include <random>
#include <functional>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::stringstream;

class Block {
private:
	uint32_t nIndex;
	int64_t nNonce;
	string sData;
	string sHash;
	time_t timestamp;
	inline string CalculateHash() const;
	vector<string> IDs;
	void MerkleRoot();
	string Merkle;

public:
	Block(uint32_t index, const string& data);
	string GetHash();
	string sPrevHash;
	int64_t getNonce() { return nNonce; }
	void MineBlock(uint32_t nDifficulty);
	void setIDs(vector<string> Id) { IDs = Id; MerkleRoot(); };
	void printBlock();
	
};


class Blockchain {
private:
	uint32_t nDifficulty;
	vector<Block> vChain;
	Block GetLastBlock() const;

public:
	Blockchain();
	void AddBlock(Block bNew);
	void printBlockChain();
	void addMerkle(int Index, vector<string>IDs);
};

class User {
private:
	string name;
	string public_key;
	int kappaCoin;
public:
	User(string dName = "", string dKey = "", int dBalance = 0) : name{ dName }, public_key{ dKey }, kappaCoin{ dBalance } {};

	void setName(string word) { name = word; };
	void setKey(string lock) { public_key = lock; };
	void setKappa(int currency) { kappaCoin = currency; };

	string getName() { return name; };
	string getKey() { return public_key; };
	int getKappa() { return kappaCoin; };

	void addKappa(int add) { kappaCoin += add;};
	void subKappa(int sub) { kappaCoin -= sub;};

};

class Transaction {
public:
	string tID;
	string from;
	string to;
	int amount;

	int fromID;
	int toID;

	string getID() { return tID; };
	int getFromID() { return fromID;};
	int getToID() { return toID; };

	Transaction(string deftID, string dFrom, string dTo, int dAmount, int dFromID, int dToID) : tID{ deftID }, from{ dFrom }, to{ dTo }, amount{ dAmount }, fromID{dFromID}, toID{dToID}
	{
	
	};
};

void readUsers(vector<User>& Kappa, int n);
void createTransaction(int nTransaction, int nUsers, vector<Transaction>& transactions, vector<User> users);