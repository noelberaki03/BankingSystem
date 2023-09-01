#include "Account.hpp"
#include "Bank.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>

long Account::NextAccountNumber = 0;

int main() {
    Account acc;
    Bank b;
    int choice;
    std::string fname, lname;
    long accountNumber;
    float balance, amount;

    std::cout << "***Banking System***" << std::endl;
    
    do {
        std::cout << "\n\tSelect one option below\n";
        std::cout << "\t1 Open an Account\n";
        std::cout << "\t2 Balance Enquiry\n";
        std::cout << "\t3 Deposit\n";
        std::cout << "\t4 Withdrawal\n";
        std::cout << "\t5 Close an Account\n";
        std::cout << "\t6 Show All Accounts\n";
        std::cout << "\t7 Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter First Name: ";
                std::cin >> fname;
                std::cout << "Enter Last Name: ";
                std::cin >> lname;
                std::cout << "Enter initial Balance: ";
                std::cin >> balance;
                acc = b.OpenAccount(fname, lname, balance);
                std::cout << std::endl << "Congratulations! Account is Created" << std::endl;
                std::cout << acc;
                break;
            case 2:
                std::cout << "Enter Account Number: ";
                std::cin >> accountNumber;
                acc = b.BalanceEnquiry(accountNumber);
                std::cout << std::endl << "Your Account Details" << std::endl;
                std::cout << acc;
                break;
            case 3:
                std::cout << "Enter Account Number: ";
                std::cin >> accountNumber;
                std::cout << "Enter Balance: ";
                std::cin >> amount;
                acc = b.Deposit(accountNumber, amount);
                std::cout << std::endl << "Amount is Deposited" << std::endl;
                std::cout << acc;
                break;
            case 4:
                std::cout << "Enter Account Number: ";
                std::cin >> accountNumber;
                std::cout << "Enter Balance: ";
                std::cin >> amount;
                acc = b.Withdraw(accountNumber, amount);
                std::cout << std::endl << "Amount Withdrawn" << std::endl;
                std::cout << acc;
                break;
            case 5:
                std::cout << "Enter Account Number: ";
                std::cin >> accountNumber;
                b.CloseAccount(accountNumber);
                std::cout << std::endl << "Account is Closed" << std::endl;
                break;
            case 6:
                b.ShowAllAccounts();
                break;
            case 7:
                break;
            default:
                std::cout << "\nEnter correct choice";
                exit(0);
        }
    } while (choice != 7);

    return 0;
}