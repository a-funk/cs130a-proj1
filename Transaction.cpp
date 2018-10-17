#include "Transaction.h"
#include "picosha2.h"
Transaction *head=NULL;

Transaction::Transaction(){
	next=NULL;	
}
Transaction::Transaction(int amount, string sender, string reciever){
	this->amount=amount;
	this->sender=sender;
	this->reciever=reciever;
}
Transaction::Transaction(Transaction *next, int amount, string sender, string reciever, string hash, string nonce){
	this->next=next;
	this->amount=amount;
	this->sender=sender;
	this->reciever=reciever;
	this->hash=hash;
	this->nonce=nonce;
}

string Transaction::generateNonce(){
	string nonce="";
	srand(time(NULL));
	for(int i=0; i<4; i++){
		nonce +=char(rand()%26+97);
	}
	return nonce;
}


int Transaction::getAmount(){
return amount;
}
string Transaction::getSender(){
return sender;
}
string Transaction::getReciever(){
return reciever;
}
string Transaction::getNonce(){
return nonce;
}
string Transaction::getHash(){
return hash;
}
Transaction *Transaction::getNext(){
return next;
}

void Transaction::setAmount(int amount){
	this->amount=amount; }
void Transaction::setHash(string hash){
	this->hash=hash; }
void Transaction::setSender(string sender){
	this->sender=sender; }
void Transaction::setReciever(string reciever){
	this->reciever=reciever; }
void Transaction::setNonce(string nonce){
	this->nonce=nonce; }
void Transaction::setNext(Transaction* next){
this->next = next;
}
