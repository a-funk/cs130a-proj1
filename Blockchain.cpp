#include "Blockchain.h"

Blockchain::Blockchain(){
	this->head=NULL;
}
Blockchain::Blockchain(Transaction *t){
	this->head=t;
}

void Blockchain::addTrans(int amount, string sender, string reciever){
	Transaction *t = new Transaction(amount, sender, reciever);
	if(this->head == NULL){
		this->head=t;
		printBlock(t);
	}
	else{
		Transaction *past = this->head;
		int t_amount = past->getAmount();
		string t_sender = past->getSender();
		string t_reciever = past->getReciever();
		t->setNext(past);
		string nonce = generateNonce();
		string hash_me = to_string(t_amount)+t_sender+t_reciever+nonce;
		string hash=generateHash(hash_me);
		bool verified = verifyHash(hash);
		while(!verified){
			nonce = generateNonce();
			hash_me = to_string(t_amount)+t_sender+t_reciever+nonce;
			hash=generateHash(hash_me);
			verified = verifyHash(hash);
		}		
		t->setNonce(nonce);
		t->setHash(hash);
		printBlock(t);
		this->head=t;
		}
}	

string Blockchain::generateNonce(){
	string nonce="";
	srand(time(NULL));
	for(int i=0; i<4; i++){
		nonce +=char(rand()%26+97);
	}
	return nonce;
}
string Blockchain::generateHash(string h){
	std::string src_str = h;

	std::vector<unsigned char> hash(picosha2::k_digest_size);
	picosha2::hash256(src_str.begin(), src_str.end(), hash.begin(), hash.end());

	std::string hex_str = picosha2::bytes_to_hex_string(hash.begin(), hash.end());
	return hex_str;
}

bool Blockchain::verifyHash(string h){
	bool verifyHash=false;
	char x = h.back();
	if(x=='0'){ return true;}
	else if(x=='1'){ return true;}
	else if(x=='2'){ return true;}
	else if(x=='3'){ return true;}
	else if(x=='4'){ return true;}
	return verifyHash;
}

void Blockchain::printBlock(Transaction *t){
	int amount = t->getAmount();
	string sender = t->getSender();
	string reciever = t->getReciever();
	string nonce = t->getNonce();
	string hash = t->getHash();
	cout << "\n";
	cout << "Amount: \t" << to_string(amount) << "\n";
	cout << "Sender: \t" << sender << "\n";
	cout << "Reciever: \t" << reciever << "\n";
	cout << "Nonce: \t" << nonce << "\n";
	cout << "Hash: \t" << hash << "\n";
	cout << "\n";
}

void Blockchain::findUser(string s){
	bool found=false;
	Transaction *next = this->head;
	while(next){
		if(next->getSender().compare(s)==0){
			printBlock(next);
			found=true;
		}
		else if(next->getReciever().compare(s)==0){
			printBlock(next);
			found=true;
		}
		next=next->getNext();
	}
	if(!found){
		cout << "User not found within chain please try a different user.\n";
	}
}
void Blockchain::printBlockchain(){
		Transaction *tmp = head;
		while(tmp){
			printBlock(tmp);
			tmp = tmp->getNext();
		}
	
}

bool Blockchain::verifyBlockchain(){
	Transaction *curr = this->head;
	Transaction *next = this->head->getNext();
	while(next){
		string amount = to_string(next->getAmount());
		string sender = next->getSender();
		string reciever = next->getReciever();
		string nonce = curr->getNonce();
		string h = amount+sender+reciever+nonce;
		string _hash = generateHash(h);
		
		if(_hash.compare(curr->getHash())!=0){
			cout << "BLOCKCHAIN FAILED VERIFICATION\n" 
					<< "INCORRECT BLOCKS BELOW\n"<< "--------------------\n";
			printBlock(curr);
			printBlock(next);
			return false;
		}
		Transaction *tmp = curr;
		curr=next;
		next=next->getNext();
	}
	cout << "---------------------------------------\n";
	cout << "BLOCKCHAIN VERIFIED\n" << "PRINTING CHAIN:\n";
	printBlockchain();
	return true;
}
