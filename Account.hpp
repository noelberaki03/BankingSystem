#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>

class Account {
private:
    long accountNumber;
    std::string firstName;
    std::string lastName;
    float balance;
    static long NextAccountNumber;

public:
    Account() {}
    Account(std::string fname, std::string lname, float balance);
    long getAccNo() const { return accountNumber; }
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    float getBalance() const { return balance; }
    void Deposit(float amount);
    void Withdraw(float amount);
    static void setLastAccountNumber(long accountNumber);
    static long getLastAccountNumber();
    friend std::ofstream& operator<<(std::ofstream& ofs, const Account& acc);
    friend std::ifstream& operator>>(std::ifstream& ifs, Account& acc);
    friend std::ostream& operator<<(std::ostream& os, const Account& acc);
};