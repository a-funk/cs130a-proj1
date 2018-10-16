#include <cstdlib>
#include <string>
#include <iostream>
#include "Transaction.h"

using namespace std;

int main(){
	cout << "Welcome to the transaction-chain application..." << "\n"
		 << "1) Add a transaction to the chain." << "\n"
		 << "2) Find a transaction with the name of receiver or  sender." << "\n"
		 << "3) Verify and print the chain." << "\n";

	int var=0;
	cin >> var;

	Transaction t;
	// Executes Add Transaction
	if(var == 1){
		int amount=0;
		cout << "Amount: ";
		cin >> amount;
		if(cin.fail()){
			cout << "Please enter an integer and try again.\n";
			return 0;
		}

		string sender="";
		cout << "Sender: ";
		cin >> sender;

		string reciever="";
		cout << "Reciever: ";
		cin >> reciever;
		
		//t.addTransaction(amount, sender, reciever);
	}	
	// Executes Find Transaction
	else if(var == 2){
		string sender="";
		cout << "Sender: ";
		cin >> sender;
	
		//t.findTransaction(sender);
	}
	// Executes Verify Chain
	else if(var == 3){
		//t.verifyChain();
	}
	else{
		cout << "Please select a valid option.\n";
		return 0;
	}

    int x = t.lastNum();
    cout << "Last digit : " << x << "\n";
    return 0;
}
