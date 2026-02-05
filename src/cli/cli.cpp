#include "cli.h"
#include <iostream>

void CLI::run() {
    while (true) {
        showMenu();
        int choice;
        std::cin >> choice;

        try {
            if (!handleChoice(choice)) return;
        } catch (const std::exception& ex) {
            std::cout << "Error: " << ex.what() << '\n';
        }
    }
}

void CLI::showMenu() const {
    std::cout << "\n1. Create Account\n"
              << "2. Delete Account\n"
              << "3. Deposit\n"
              << "4. Withdraw\n"
              << "5. Show Account\n"
              << "0. Exit\n"
              << "Choice: ";
}

bool CLI::handleChoice(int choice) {
    switch (choice) {
    case 1: {
        std::string name;
        std::string cardId;
        double initial;
        std::cout << "Enter person name: ";
        std::cin >> std::ws;
        std::getline(std::cin, name);
        std::cout << "Enter national card ID: ";
        std::cin >> cardId;
        std::cout << "Initial deposit (or 0): ";
        std::cin >> initial;
        int accountId = bank_.createAccount(name, cardId, initial);
        std::cout << "The Account ID is: " << accountId << "\n";
        break;
    }

    case 2: {
        int accountId;
        std::cout << "Enter Account ID to delete: ";
        std::cin >> accountId;
        if (bank_.deleteAccount(accountId))
            std::cout << "Account deleted\n";
        else
            std::cout << "Account not found\n";
        break;
    }

    case 3: {
        int accountId;
        double amount;
        std::cout << "Enter Account ID: ";
        std::cin >> accountId;
        std::cout << "Amount: ";
        std::cin >> amount;
        bank_.deposit(accountId, amount);
        std::cout << "Deposit successful\n";
        break;
    }

    case 4: {
        int accountId;
        double amount;
        std::cout << "Enter Account ID: ";
        std::cin >> accountId;
        std::cout << "Amount: ";
        std::cin >> amount;
        bank_.withdraw(accountId, amount);
        std::cout << "Withdraw successful\n";
        break;
    }

    case 5: {
        int accountId;
        std::cout << "Enter Account ID: ";
        std::cin >> accountId;
        std::cout << "Balance: " << bank_.getAccount(accountId).balance() << '\n';
        break;
    }

    case 0:
        return false;

    default:
        std::cout << "Invalid choice\n";
    }
    return true;
}
