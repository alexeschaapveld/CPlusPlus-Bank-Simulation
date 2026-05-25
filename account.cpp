#include "account.h"
#include <iostream>
#include <string>

Account::Account(std::string username, std::string password, int accountNumber, double balance) {
    this->username = username;
    this->password = password;
    this->accountNumber = accountNumber;
    this->balance = balance;
}

void Account::deposit(double amount) {
    if(amount > 0) {
        balance += amount;
        std::cout << "Successful Deposit!" << std::endl;
    } else {
        std::cout << "Deposit Failed!" << std::endl;
    }
}

void Account::withdraw(double amount) {
    if(balance - amount < 0) {
        std::cout << "Withdrawl Amount too Great!" << std::endl;
    } else if(amount < 0) {
        std::cout << "Invalid Withdrawl Amount!" << std::endl;
    } else {
        balance = balance - amount;
        std::cout << "Successful Withdrawl!" << std::endl;
    }
}

double Account::getBalance() { return balance; }
int Account::getAccountNumber() { return accountNumber; }

void Account::displayBalance() { std::cout << "Current Balance: " << balance << std::endl; }
void Account::displayAccountNumber() { std::cout << "Account Number: " << accountNumber << std::endl; }
 
std::string Account::getUsername() const { return username; }

bool Account::validatePassword(std::string password) const {
    return this->password == password;
}