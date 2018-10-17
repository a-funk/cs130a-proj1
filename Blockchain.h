#include <string>
#include <iostream>
#include "picosha2.h"
#include "Transaction.h"
using namespace std;

class Blockchain{
	public:
		Blockchain();
		Blockchain(Transaction *t);
		void addTrans(int amount, string sender, string reciever);
		string generateNonce();
		string generateHash(string h);
		bool verifyHash(string hash);
		void verifyChain();	
		//void printChain();
		void printBlock(Transaction *t);
		void printBlockchain();
		void findUser(string s);
		bool verifyBlockchain();
	private:
		Transaction *head;
};
