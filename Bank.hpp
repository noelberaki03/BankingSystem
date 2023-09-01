#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>

class Bank {
private:
    std::map<long, Account> accounts;

public:
    Bank();
    Account OpenAccount(std::string fname, std::string lname, float balance);
    Account BalanceEnquiry(long accountNumber);
    Account Deposit(long accountNumber, float amount);
    Account Withdraw(long accountNumber, float amount);
    void CloseAccount(long accountNumber);
    void ShowAllAccounts();
    ~Bank();
};