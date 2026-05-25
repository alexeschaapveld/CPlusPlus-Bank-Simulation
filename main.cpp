#include <iostream>
#include <string>
#include <limits> // For std::numeric_limits<std::streamsize>::max()
#include "account.h"
#include "bank.h"

int main() {
    // Instantiate our central bank system to store accounts
    Bank centralBank;
    int userChoice;

    while(true) {
        std::cout << "\n=== Welcome to the Bank of C++ ===" << std::endl;
        std::cout << "1. Open an Account" << std::endl;
        std::cout << "2. Log into an Account" << std::endl;
        std::cout << "3. Exit the CLI" << std::endl;
        std::cout << "Requested Option: ";
        std::cin >> userChoice;
        
        // Comprehensive input validation for standard options
        if(std::cin.fail() || userChoice > 3 || userChoice < 1) {
            std::cout << "\nInvalid Option! Please enter a valid number (1-3).\n" << std::endl;
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad stream characters
            continue;
        }

        // OPTION 1: ACCOUNT CREATION
        if(userChoice == 1) {
            std::string username;
            std::string password;
            double initialDeposit;

            std::cout << "\n--- Open an Account ---" << std::endl;
            std::cout << "Please enter a username: ";
            std::cin >> username;
            std::cout << "Please enter a password: ";
            std::cin >> password;
            std::cout << "Please enter an initial deposit amount: $";
            std::cin >> initialDeposit;

            // Handle invalid deposit inputs
            if (std::cin.fail() || initialDeposit < 0) {
                std::cout << "Invalid deposit amount! Account creation aborted." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            // Route data to central bank manager
            centralBank.createAccount(username, password, initialDeposit);

        // OPTION 2: ACCOUNT LOGIN
        } else if(userChoice == 2) {
            std::string username;
            std::string password;

            std::cout << "\n--- Log into an Account ---" << std::endl;
            std::cout << "Please enter your username: ";
            std::cin >> username;
            std::cout << "Please enter your password: ";
            std::cin >> password;

            // Verification logic handled safely via internal bank verification mapping
            if (centralBank.login(username, password)) {
                // Future feature extension: Nested loop to interact with individual account
                // (e.g., withdraw, deposit, check balance commands)
            }
            
        // OPTION 3: TERMINATE APP
        } else {
            std::cout << "\nThank you for choosing Bank of C++. Goodbye!" << std::endl;
            break;
        }
    }
    return 0;
}