#include "bank.h"
#include <iostream>

Bank::Bank() {
    nextAccountNumber = 100000000; // Starting account number
}

bool Bank::createAccount(std::string username, std::string password, double initialDeposit) {
    if(accounts.find(username) != accounts.end()) {
        std::cout << "Username already exists!" << std::endl;
        return false;
    }
    Account newAccount(username, password, nextAccountNumber++, initialDeposit);
    accounts.insert({username, newAccount});
    std::cout << "Account Successfully Created!" << std::endl;
    return true;
}

bool Bank::login(std::string username, std::string password) {
    auto it = accounts.find(username);
    if(it == accounts.end()) {
        std::cout << "Username not found!" << std::endl;
        return false;
    }
    if(it->second.validatePassword(password)) {
        std::cout << "Login Successful!" << std::endl;
        return true;
    } else {
        std::cout << "Incorrect Password!" << std::endl;
        return false;
    }
}