#include "bank.h"

Bank::Bank(IPersistence& persistence) : persistence_(persistence), nextAccountId_(0) {
    accounts_ = persistence_.load();
    // Find the highest account ID to continue from there
    for (const auto& pair : accounts_) {
        nextAccountId_ = std::max(nextAccountId_, pair.first);
    }
    nextAccountId_++;  // Start with the next ID
}

int Bank::createAccount(const std::string& personName, const std::string& cardId, double initialBalance) {
    int accountId = nextAccountId_++;
    auto result = accounts_.emplace(accountId, Account{accountId, initialBalance, personName, cardId});
    if (result.second) {
        return accountId;
    }
    nextAccountId_--;
    throw std::runtime_error("Failed to create account");
}

bool Bank::deleteAccount(int accountId) {
    return accounts_.erase(accountId) > 0;
}

void Bank::deposit(int accountId, double amount) {
    findAccount(accountId).deposit(amount);
}

void Bank::withdraw(int accountId, double amount) {
    findAccount(accountId).withdraw(amount);
}

const Account& Bank::getAccount(int accountId) const {
    return findAccount(accountId);
}

std::vector<Account> Bank::getAllAccounts() const {
    std::vector<Account> result;
    for (const auto& pair : accounts_) {
        result.push_back(pair.second);
    }
    return result;
}

void Bank::save() {
    persistence_.save(accounts_);
}

Account& Bank::findAccount(int accountId) {
    auto it = accounts_.find(accountId);
    if (it == accounts_.end())
        throw std::runtime_error("Account not found");
    return it->second;
}

const Account& Bank::findAccount(int accountId) const {
    auto it = accounts_.find(accountId);
    if (it == accounts_.end())
        throw std::runtime_error("Account not found");
    return it->second;
}