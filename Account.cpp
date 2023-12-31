#include "Account.hpp"

int Account::nextAccountNumber = 0;

// constructor
Account::Account(string fName, string lName, double balance) :
    firstName(fName), lastName(lName), balance(balance) {
    accountNumber = ++nextAccountNumber; 
}

// mutator
void Account::setLastAccountNumber(double accountNumber) {
    nextAccountNumber = accountNumber;
}

// accessors
double Account::getLastAccountNumber() {
    return nextAccountNumber;
}

double Account::getAccountNumber() {
    return accountNumber;
}

string Account::getFirstName() {
    return firstName;
}

string Account::getLastName() {
    return lastName;
}

double Account::getBalance() {
    return balance;
}

// add money to account
void Account::deposit(double amount) {
    balance += amount;
}

// take out money from account
void Account::withdraw(double amount) {
    if (balance - amount < MIN_BALANCE) {
        throw InsufficientFunds();
    }
    balance -= amount;
}

// operator overload to write Account to screen
ostream& operator<<(ostream &out, const Account &acc) {
    out << "Account Number: " << acc.accountNumber << endl;
    out << "Name on account: " << acc.firstName << " " << acc.lastName << endl;
    out << "Balance: " << acc.balance << endl;
    return out;
}

// operator overload to write Account to file
ofstream& operator<<(ofstream &ofs, const Account &acc) {
    ofs << acc.accountNumber << endl;
    ofs << acc.firstName << endl;
    ofs << acc.lastName << endl;
    ofs << acc.balance << endl;
    return ofs;
}

// operator overload to read Account from file
ifstream& operator>>(ifstream &ifs, Account &acc) {
    ifs >> acc.accountNumber;
    ifs >> acc.firstName;
    ifs >> acc.lastName;
    ifs >> acc.balance;
    return ifs;
}