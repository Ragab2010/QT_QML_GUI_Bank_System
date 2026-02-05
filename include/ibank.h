// ibank.h
#pragma once
#include "account.h"

class IBank {
public:
    virtual ~IBank() = default;
    virtual int createAccount(const std::string& personName, const std::string& cardId, double initialBalance = 0.0) = 0;
    virtual bool deleteAccount(int accountId) = 0;
    virtual void deposit(int accountId, double amount) = 0;
    virtual void withdraw(int accountId, double amount) = 0;
    virtual const Account& getAccount(int accountId) const = 0;
};