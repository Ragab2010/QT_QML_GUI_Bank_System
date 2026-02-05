// account.h
#pragma once
#include <string>
#include <stdexcept>
#include <chrono>

using UserId = std::string;

class Account {
public:
    explicit Account(int accountId, double initialBalance = 0.0,
                     const std::string& personName = "", 
                     const std::string& cardId = "");

    int getAccountId() const noexcept { return accountId_; }
    double balance() const noexcept;
    void deposit(double amount);
    void withdraw(double amount);
    
    // Metadata getters
    const std::string& getPersonName() const noexcept { return personName_; }
    const std::string& getCardId() const noexcept { return cardId_; }
    const std::string& getCreationTime() const noexcept { return creationTime_; }
    const std::string& getLastOperationType() const noexcept { return lastOperationType_; }
    const std::string& getLastOperationTime() const noexcept { return lastOperationTime_; }
    
    // Metadata setters
    void setPersonName(const std::string& name) { personName_ = name; }
    void setCardId(const std::string& cardId) { cardId_ = cardId; }
    void updateOperationInfo(const std::string& type);

private:
    int accountId_;
    std::string cardId_;
    double balance_;
    std::string personName_;
    std::string creationTime_;
    std::string lastOperationType_;
    std::string lastOperationTime_;
    
    static std::string getCurrentTime();
};
