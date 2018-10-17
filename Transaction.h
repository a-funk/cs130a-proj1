#include <string>
using namespace std;
class Transaction{
    public:
		Transaction();
		Transaction(int amount, string sender, string reciever);
		Transaction(Transaction *next, int amount, string sender, string reciever, string hash, string nonce);
		string generateNonce();

		//getters
		int getAmount();
		string getHash();
		string getSender();
		string getReciever();
		string getNonce();
		Transaction* getNext();
		//setters
		void setAmount(int amount);
		void setHash(string hash);
		void setSender(string sender);
		void setReciever(string reciever);
		void setNonce(string nonce);
		void setNext(Transaction* next);
		

    private:
        Transaction *next;
        int amount;
        string sender;
        string reciever;
        string nonce;
        string hash;
};
