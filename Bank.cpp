#include "Account.hpp"
#include "Bank.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>

Bank::Bank() {
    Account account;
    std::ifstream infile;
    infile.open("Bank.data");
    if (infile.is_open()) {
        while (infile >> account) {
            accounts.insert(std::pair<long, Account>(account.getAccNo(), account));
        }
        Account::setLastAccountNumber(account.getAccNo());
        infile.close();
    }
}

Account Bank::OpenAccount(std::string fname, std::string lname, float balance) {
    Account account(fname, lname, balance);
    accounts.insert(std::pair<long, Account>(account.getAccNo(), account));

    std::ofstream outfile;
    outfile.open("Bank.data", std::ios::trunc);

    for (const auto& pair : accounts) {
        outfile << pair.second;
    }

    outfile.close();
    return account;
}

Account Bank::BalanceEnquiry(long accountNumber) {
    auto itr = accounts.find(accountNumber);
    if (itr != accounts.end()) {
        return itr->second;
    }
    throw std::runtime_error("Account not found");
}

Account Bank::Deposit(long accountNumber, float amount) {
    auto itr = accounts.find(accountNumber);
    if (itr != accounts.end()) {
        itr->second.Deposit(amount);
        return itr->second;
    }
    throw std::runtime_error("Account not found");
}

Account Bank::Withdraw(long accountNumber, float amount) {
    auto itr = accounts.find(accountNumber);
    if (itr != accounts.end()) {
        itr->second.Withdraw(amount);
        return itr->second;
    }
    throw std::runtime_error("Account not found");
}

void Bank::CloseAccount(long accountNumber) {
    auto itr = accounts.find(accountNumber);
    if (itr != accounts.end()) {
        accounts.erase(accountNumber);
    }
}

void Bank::ShowAllAccounts() {
    for (const auto& pair : accounts) {
        std::cout << "Account " << pair.first << std::endl << pair.second << std::endl;
    }
}

Bank::~Bank() {
    std::ofstream outfile;
    outfile.open("Bank.data", std::ios::trunc);

    for (const auto& pair : accounts) {
        outfile << pair.second;
    }

    outfile.close();
}