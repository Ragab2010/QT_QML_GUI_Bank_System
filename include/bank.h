// bank.h
#pragma once
#include "account.h"
#include "ibank.h"
#include "ipersistence.h"
#include <unordered_map>
#include <vector>

class Bank : public IBank {
public:
    explicit Bank(IPersistence& persistence);
    int createAccount(const std::string& personName, const std::string& cardId, double initialBalance = 0.0);
    bool deleteAccount(int accountId);
    void deposit(int accountId, double amount);
    void withdraw(int accountId, double amount);
    const Account& getAccount(int accountId) const;
    std::vector<Account> getAllAccounts() const;
    void save();

private:
    Account& findAccount(int accountId);
    const Account& findAccount(int accountId) const;
    int nextAccountId_;

private:
    std::unordered_map<int, Account> accounts_;
    IPersistence& persistence_;
};
