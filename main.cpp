#include <cstdlib>
#include <string>
#include <iostream>
#include "Blockchain.h"

using namespace std;

int main(){
	int var=0;
	Blockchain b;
	cout << "Welcome to the transaction-chain application..." << "\n";
	while(var!=4){
				 cout << "1) Add a transaction to the chain." << "\n"
				 << "2) Find a transaction with the name of receiver or  sender." << "\n"
				 << "3) Verify and print the chain." << "\n"
				 << "4) Exit the program\n";

			cin >> var;

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
				b.addTrans(amount, sender, reciever);
			}	
			// Executes Find Transaction
			else if(var == 2){
				string sender="";
				cout << "Sender/Reciever: ";
				cin >> sender;
			
				b.findUser(sender);
			}
			// Executes Verify Chain
			else if(var == 3){
				b.verifyBlockchain();
			}
			else if(var == 4){
				cout << "Have a great day.\n";
			}
			else{
				cout << "Please select a valid option.\n";
				return 0;
			}
	}
    return 0;
}
