#include "bank.h"
#include <iostream>
#include <limits>

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

void Bank::accountMenu(std::string username) {
    auto account = accounts.find(username);
    if(account == accounts.end()) {
        return;
    }

    bool loggedIn = true;
    while(loggedIn) {
        int userChoice;
        std::cout << "\n--- Account Menu ---" << std::endl;
        std::cout << "1. Display Balance" << std::endl;
        std::cout << "2. Display Account Number" << std::endl;
        std::cout << "3. Deposit" << std::endl;
        std::cout << "4. Withdraw" << std::endl;
        std::cout << "5. Logout" << std::endl;
        std::cout << "Requested Option: ";
        std::cin >> userChoice;

        if(std::cin.fail() || userChoice < 1 || userChoice > 5) {
            std::cout << "\nInvalid Option! Please enter a valid number (1-5)." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if(userChoice == 1) {
            account->second.displayBalance();
        } else if(userChoice == 2) {
            account->second.displayAccountNumber();
        } else if(userChoice == 3 || userChoice == 4) {
            double amount;
            std::cout << "Enter amount: $";
            std::cin >> amount;

            if(std::cin.fail()) {
                std::cout << "Invalid amount." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if(userChoice == 3) {
                account->second.deposit(amount);
            } else {
                account->second.withdraw(amount);
            }
        } else {
            loggedIn = false;
            std::cout << "Logged out successfully." << std::endl;
        }
    }
}

