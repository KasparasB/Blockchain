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

public:
	Block(uint32_t index, const string& data);
	string GetHash();
	string sPrevHash;
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

	int addKappa(int add) { kappaCoin += add; };
	int subKappa(int sub) { kappaCoin -= sub; };

};

class Transaction {
public:
	int tID;
	string from;
	string to;
	int amount;

	Transaction(int deftID, string dFrom, string dTo, int dAmount) : tID{ deftID }, from{ dFrom }, to{ dTo }, amount{ dAmount }{};
};

void readUsers(vector<User>& Kappa, int n);
void createTransaction(int nTransaction, int nUsers, vector<Transaction>& transactions, vector<User> users);