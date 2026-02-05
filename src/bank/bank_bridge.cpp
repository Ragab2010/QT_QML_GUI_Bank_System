#include "bank_bridge.h"
#include <QJsonObject>
#include <QJsonArray>

BankBridge::BankBridge(Bank& bank, QObject* parent)
    : QObject(parent), bank_(bank) {
}

BankBridge::~BankBridge() = default;

int BankBridge::createAccount(const QString& personName, const QString& cardId, double initialBalance) {
    try {
        if (personName.isEmpty() || cardId.isEmpty()) {
            emit error("Person name and card ID cannot be empty");
            return -1;
        }
        
        int accountId = bank_.createAccount(
            personName.toStdString(),
            cardId.toStdString(),
            initialBalance
        );
        
        emit accountCreated(accountId);
        emit accountsUpdated();
        return accountId;
    } catch (const std::exception& e) {
        emit error(QString::fromStdString(e.what()));
        return -1;
    }
}

bool BankBridge::deleteAccount(int accountId) {
    try {
        bool success = bank_.deleteAccount(accountId);
        if (success) {
            emit accountDeleted(accountId);
            emit accountsUpdated();
        }
        return success;
    } catch (const std::exception& e) {
        emit error(QString::fromStdString(e.what()));
        return false;
    }
}

void BankBridge::deposit(int accountId, double amount) {
    try {
        bank_.deposit(accountId, amount);
        const auto& account = bank_.getAccount(accountId);
        emit balanceChanged(accountId, account.balance());
        emit accountsUpdated();
    } catch (const std::exception& e) {
        emit error(QString::fromStdString(e.what()));
    }
}

void BankBridge::withdraw(int accountId, double amount) {
    try {
        bank_.withdraw(accountId, amount);
        const auto& account = bank_.getAccount(accountId);
        emit balanceChanged(accountId, account.balance());
        emit accountsUpdated();
    } catch (const std::exception& e) {
        emit error(QString::fromStdString(e.what()));
    }
}

QJsonObject BankBridge::getAccount(int accountId) {
    QJsonObject obj;
    try {
        const auto& account = bank_.getAccount(accountId);
        obj["accountId"] = accountId;
        obj["balance"] = account.balance();
    } catch (const std::exception& e) {
        emit error(QString::fromStdString(e.what()));
    }
    return obj;
}

QJsonArray BankBridge::getAllAccounts() {
    QJsonArray arr;
    // Note: You may need to add a method to Bank class to iterate all accounts
    // For now, this is a placeholder
    return arr;
}

void BankBridge::saveData() {
    try {
        bank_.save();
    } catch (const std::exception& e) {
        emit error(QString::fromStdString(e.what()));
    }
}

void BankBridge::getAccountDetails(int accountId) {
    try {
        const auto& account = bank_.getAccount(accountId);
        QJsonObject details;
        details["accountId"] = accountId;
        details["owner"] = QString::fromStdString(account.getPersonName());
        details["balance"] = account.balance();
        details["createdTime"] = QString::fromStdString(account.getCreationTime());
        details["lastOperationType"] = QString::fromStdString(account.getLastOperationType());
        details["lastOperationTime"] = QString::fromStdString(account.getLastOperationTime());
        
        emit detailsRetrieved(details);
    } catch (const std::exception& e) {
        emit error("Account not found: " + QString::fromStdString(e.what()));
        QJsonObject empty;
        emit detailsRetrieved(empty);
    }
}

void BankBridge::getPersonAccounts(const QString& personName) {
    try {
        QString result;
        const auto& allAccounts = bank_.getAllAccounts();
        
        bool found = false;
        for (const auto& account : allAccounts) {
            if (account.getPersonName() == personName.toStdString()) {
                found = true;
                result += QString("Account ID: %1\n")
                    .arg(account.getAccountId());
                result += QString("  Owner: %1\n")
                    .arg(QString::fromStdString(account.getPersonName()));
                result += QString("  Balance: $ %1\n\n")
                    .arg(account.balance(), 0, 'f', 2);
            }
        }
        
        if (!found) {
            result = QString("No accounts found for person: %1").arg(personName);
        }
        
        emit personAccountsRetrieved(result);
    } catch (const std::exception& e) {
        emit error(QString::fromStdString(e.what()));
    }
}

void BankBridge::getAllAccountDetails() {
    try {
        QString result;
        const auto& allAccounts = bank_.getAllAccounts();
        
        if (allAccounts.empty()) {
            result = "No accounts in system";
        } else {
            for (const auto& account : allAccounts) {
                result += QString("========================\n");
                result += QString("Account ID: %1\n")
                    .arg(account.getAccountId());
                result += QString("Owner: %1\n")
                    .arg(QString::fromStdString(account.getPersonName()));
                result += QString("Balance: $ %1\n")
                    .arg(account.balance(), 0, 'f', 2);
                result += QString("Created: %1\n")
                    .arg(QString::fromStdString(account.getCreationTime()));
                result += QString("Last Operation: %1 (%2)\n\n")
                    .arg(QString::fromStdString(account.getLastOperationType()),
                         QString::fromStdString(account.getLastOperationTime()));
            }
        }
        
        emit allAccountsRetrieved(result);
    } catch (const std::exception& e) {
        emit error(QString::fromStdString(e.what()));
    }
}

#include "moc_bank_bridge.cpp"
