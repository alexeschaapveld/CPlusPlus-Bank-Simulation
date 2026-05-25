#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

class Account {
    private:
        std::string username;
        std::string password;
        int accountNumber;
        double balance;
    public:
        Account(std::string username, std::string password, int accountNumber, double balance);
        void deposit(double amount);
        void withdraw(double amount);
        double getBalance();
        int getAccountNumber();
        void displayBalance();
        void displayAccountNumber();
        std::string getUsername() const;
        bool validatePassword(std::string password) const;
};

#endif