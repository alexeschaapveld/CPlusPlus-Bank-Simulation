#ifndef BANK_H
#define BANK_H

#include <map>
#include <string>
#include "account.h"

class Bank {
    private:
        std::map<std::string, Account> accounts;
        int nextAccountNumber;
    public:
        Bank();
        bool createAccount(std::string username, std::string password, double initialDeposit);
        bool login(std::string username, std::string password);
        void accountMenu(std::string username);
};

#endif