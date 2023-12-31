#include <iostream>
#include <fstream>

using namespace std;

#define MIN_BALANCE 0
#include <exception>

#ifndef INSUFFICIENTFUNDS_
#define INSUFFICIENTFUNDS_
struct InsufficientFunds : exception {};
#endif

#ifndef ACCOUNT_
#define ACCOUNT_

class Account {
    private:
        string firstName;
        string lastName;
        int accountNumber;
        double balance;
        static int nextAccountNumber;

    public:
        // constructor
        explicit Account(string fName = "n/a", string lName = "n/a", double balance = 0);
        
        // mutator
        static void setLastAccountNumber(double accountNumber);

        // accessors
        static double getLastAccountNumber();
        double getAccountNumber();
        string getFirstName();
        string getLastName();
        double getBalance();

        // operations
        void deposit(double amount);
        void withdraw(double amount);

        // operator overload to write Account to screen
        friend ostream& operator<<(ostream &out, const Account &acc);
        // operator overload to write Account to file
        friend ofstream& operator<<(ofstream &ofs, const Account &acc);
        // operator overload to read Account from file
        friend ifstream& operator>>(ifstream &ifs, Account &acc);
};

#endif