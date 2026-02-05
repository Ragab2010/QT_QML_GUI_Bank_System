#include "account.h"
#include <sstream>
#include <iomanip>
#include <ctime>

Account::Account(int accountId, double initialBalance, const std::string& personName, const std::string& cardId)
        : accountId_(accountId),
            cardId_(cardId),
            balance_(initialBalance),
            personName_(personName),
      creationTime_(getCurrentTime()),
      lastOperationType_("None"),
      lastOperationTime_(getCurrentTime()) {}

double Account::balance() const noexcept {
    return balance_;
}

void Account::deposit(double amount) {
    if (amount <= 0)
        throw std::invalid_argument("Deposit amount must be positive");
    balance_ += amount;
    updateOperationInfo("Deposit");
}

void Account::withdraw(double amount) {
    if (amount <= 0)
        throw std::invalid_argument("Withdraw amount must be positive");
    if (amount > balance_)
        throw std::runtime_error("Insufficient balance");
    balance_ -= amount;
    updateOperationInfo("Withdrawal");
}

void Account::updateOperationInfo(const std::string& type) {
    lastOperationType_ = type;
    lastOperationTime_ = getCurrentTime();
}

std::string Account::getCurrentTime() {
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time_t), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}