#include "Bank.hpp"
#include "Account.hpp"
#include <iostream>

using namespace std;

void menu() {
    cout << "\tSelect an option below";
    cout << "\n\t1 Open an Account";
    cout << "\n\t2 Balance Enquiry";
    cout << "\n\t3 Deposit to Account";
    cout << "\n\t4 Withdraw from Account";
    cout << "\n\t5 Close an Account";
    cout << "\n\t6 Show All Accounts";
    cout << "\n\t7 Quit\n";
    cout << "\nEnter your choice: ";
}

void openAccount(Bank &bank) {
    string firstName;
    string lastName;
    double balance;

    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;
    cout << "Enter initil balance: ";
    cin >> balance;

    Account acc = bank.openAccount(firstName, lastName, balance);
    cout << "\n------------------------" << endl;
    cout << "      Account details" << endl;
    cout << acc;
    cout << "------------------------" << endl;
}

void balanceEnquiry(Bank &bank) {
    int accountNumber;

    cout << "Enter account number: ";
    cin >> accountNumber;
    if (!bank.hasAccount(accountNumber)) { return; }
    cout << "\n------------------------" << endl;
    Account acc = bank.balanceEnquiry(accountNumber);
    cout << "      Account details" << endl;
    cout << acc;
    cout << "------------------------" << endl;
}

void depositToAccount(Bank &bank) {
    int accountNumber;
    double amount;

    cout << "Enter account number: ";
    cin >> accountNumber;
    cout << "Enter deposit amount: ";
    cin >> amount;
    if (!bank.hasAccount(accountNumber)) { return; }
    cout << "\n------------------------" << endl;
    Account acc = bank.deposit(accountNumber, amount);
    cout << "      Account details" << endl;
    cout << acc;
    cout << "------------------------" << endl;
}

void withdrawFromAccount(Bank &bank) {
    int accountNumber;
    double amount;

    cout << "Enter account number: ";
    cin >> accountNumber;
    cout << "Enter withdraw amount: ";
    cin >> amount;
    if (!bank.hasAccount(accountNumber)) { return; }
    cout << "\n------------------------" << endl;
    try {
        Account acc = bank.withdraw(accountNumber, amount);
        cout << "      Account details" << endl;
        cout << acc;
    }
    catch (InsufficientFunds e) {
        cout << "Error: Failure to withdraw due to insufficient funds";
    }
    cout << "------------------------" << endl;
}

void closeAnAccount(Bank &bank) {
    int accountNumber;

    cout << "Enter account number: ";
    cin >> accountNumber;
    if (!bank.hasAccount(accountNumber)) { return; }
    cout << "\n------------------------" << endl;
    bank.closeAccount(accountNumber);
    cout << "------------------------" << endl << endl;
}


int main() {
    Bank bank;
    int choice;

    cout << "\t    Banking System" << endl;
    cout << "\t------------------------" << endl;

    do {
        menu();
        cin >> choice;
        cout << endl;

        switch(choice) {
            case 1: openAccount(bank); break;
            case 2: balanceEnquiry(bank); break;
            case 3: depositToAccount(bank); break;
            case 4: withdrawFromAccount(bank); break;
            case 5: closeAnAccount(bank); break;
            case 6: 
                cout << "\n------------------------" << endl;
                bank.viewAllAcounts(); 
                cout << "------------------------" << endl << endl;
            break;
            case 7: break;
            default: cout << choice << " is an invalid choice selection" << endl;
        }
        
    } while (choice != 7);
    
    return 0;
}