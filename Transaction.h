#include <string>
using namespace std;
class Transaction{
    public:
		Transaction();
		Transaction(int amount, string sender, string reciever, string hash, string nonce);
		Transaction(Transaction *next, int amount, string sender, string reciever, string hash, string nonce);
		int lastNum();
		int addTransaction(int amount, string sender, string reciever);
		string findTransaction(string sender);
		int verifyChain();

    private:
        Transaction *next;
        int amount;
        string sender;
        string reciever;
        string nonce;
        string hash;
};
