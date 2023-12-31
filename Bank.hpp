#include "Account.hpp"
#include <map>

#ifndef BANK_
#define BANK_

class Bank {
    private:
        // stores accounts in the bank
        map<int, Account> accounts;
    
    public:
        // constructor
        Bank();
        // destructor
        ~Bank();
        // operations on accounts
        Account openAccount(string fName, string lName, double balance);
        Account balanceEnquiry(int accountNumber);
        Account deposit(int accountNumber, double amount);
        Account withdraw(int accountNumber, double amount);
        void closeAccount(int accountNumber);
        void viewAllAcounts() const;
        bool hasAccount(int accountNumber);
};

#endif