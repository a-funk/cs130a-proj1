#include "Transaction.h"
Transaction *head;

Transaction::Transaction(){
	next=NULL;	
}
Transaction::Transaction(int amount, string sender, string reciever, string hash, string nonce){
	amount=amount;
	sender=sender;
	reciever=reciever;
	hash=hash;
	nonce=nonce;
}
Transaction::Transaction(Transaction *next, int amount, string sender, string reciever, string hash, string nonce){
	next=next;
	amount=amount;
	sender=sender;
	reciever=reciever;
	hash=hash;
	nonce=nonce;
}

int Transaction::addTransaction(int amount, string sender, string reciever){
	Transaction *t = new Transaction();
}

string findTransaction(string sender);
int verifyChain();


int Transaction::lastNum(){
	srand (time (NULL)) ;
	char end = char(rand() % 5);
return end;
}
