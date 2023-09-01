#include "Account.hpp"
#include "Bank.hpp"
#include "InsufficientFunds.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>

Account::Account(std::string fname, std::string lname, float balance) {
    NextAccountNumber++;
    accountNumber = NextAccountNumber;
    firstName = fname;
    lastName = lname;
    this->balance = balance;
}

void Account::Deposit(float amount) {
    balance += amount;
}

void Account::Withdraw(float amount) {
    if (balance - amount < MIN_BALANCE)
        throw InsufficientFunds();
    balance -= amount;
}

void Account::setLastAccountNumber(long accountNumber) {
    NextAccountNumber = accountNumber;
}

long Account::getLastAccountNumber() {
    return NextAccountNumber;
}

std::ofstream& operator<<(std::ofstream& ofs, const Account& acc) {
    ofs << acc.accountNumber << std::endl;
    ofs << acc.firstName << std::endl;
    ofs << acc.lastName << std::endl;
    ofs << acc.balance << std::endl;
    return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, Account& acc) {
    ifs >> acc.accountNumber;
    ifs >> acc.firstName;
    ifs >> acc.lastName;
    ifs >> acc.balance;
    return ifs;
}

std::ostream& operator<<(std::ostream& os, const Account& acc) {
    os << "First Name: " << acc.getFirstName() << std::endl;
    os << "Last Name: " << acc.getLastName() << std::endl;
    os << "Account Number: " << acc.getAccNo() << std::endl;
    os << "Balance: " << acc.getBalance() << std::endl;
    return os;
}