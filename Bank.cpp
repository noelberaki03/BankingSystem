#include "Bank.hpp"
#include "Account.hpp"
#include <iostream>
#include <fstream>

// constructor
Bank::Bank() {
    ifstream inFile;
    inFile.open("Bank.txt");
    Account account;

    if (inFile.is_open()) {
        while (inFile >> account) {
            accounts[account.getAccountNumber()] = account;
        }
    }
    Account::setLastAccountNumber(account.getAccountNumber());
    inFile.close();
}

// add account to bank
Account Bank::openAccount(string fName, string lName, double balance) {
    Account account(fName, lName, balance);
    accounts[account.getAccountNumber()] = account;

    ofstream outFile;
    outFile.open("Bank.txt", ios::app);
    outFile << account;
    outFile.close();

    cout << "\nAccount has been opened";
    return account;
}

// returns true if account is in the bank
bool Bank::hasAccount(int accountNumber) {
    if (accounts.count(accountNumber) == 0) {
        cout << "\nError: Bank does not have an account with the account number " << accountNumber << endl << endl;
        return false;
    }
    return true;
}

// view account
Account Bank::balanceEnquiry(int accountNumber) {
    return hasAccount(accountNumber) ? accounts.at(accountNumber) : Account();
}

// add money to account
Account Bank::deposit(int accountNumber, double amount) {
    if (!hasAccount(accountNumber)) {
        return Account();
    }
    accounts.at(accountNumber).deposit(amount);
    cout << "\nSuccessfully deposited " << amount << " to account number " << accountNumber << endl << endl;
    return accounts.at(accountNumber);
}

// take money out of account
Account Bank::withdraw(int accountNumber, double amount) {
    if (!hasAccount(accountNumber)) {
        return Account();
    }
    accounts.at(accountNumber).withdraw(amount);
    cout << "\nSuccessfully withdrew " << amount << " from account number " << accountNumber << endl << endl;
    return accounts.at(accountNumber);
}

void Bank::closeAccount(int accountNumber) {
    if (!hasAccount(accountNumber)) { return; }
    cout << "Account deleted \n" << accounts.at(accountNumber);
    accounts.erase(accountNumber);

    ofstream outFile("Bank.txt");
    for (auto account : accounts) {
        outFile << account.second;
    }
    outFile.close();
}

void Bank::viewAllAcounts() const {
    cout << "[ " << endl;
    int count = 0;
    for (auto account : accounts) {
        cout << "    Account " << account.first << endl;
        cout << "------------------" << endl;
        cout << account.second << endl;
        count++;
    }
    if (count == 0) {
        cout << "Empty \n]\n" << endl;
    }
    else {
        cout << "]\n" << endl;
    }
}

Bank::~Bank() {
    ofstream outFile;
    outFile.open("Bank.data");

    for (const auto& pair : accounts) {
        outFile << pair.second;
    }

    outFile.close();
}