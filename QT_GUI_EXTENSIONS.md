// Example: Extending BankBridge with Additional Features

/*
This file demonstrates how to add new features to the BankBridge class
to expose more bank operations to the QML interface.

To use these examples:
1. Add the methods to bank_bridge.h (in the "public slots:" section)
2. Implement them in bank_bridge.cpp
3. Add corresponding signals if needed (in the "signals:" section)
4. Update main.qml to call these new methods
5. Rebuild the project
*/

// ============ HEADER FILE ADDITIONS (bank_bridge.h) ============

/*
// Add these to the "public slots:" section

    // Get list of all user IDs
    QJsonArray getAllUserIds();
    
    // Get account details as a formatted string
    QString getAccountSummary(const QString& userId);
    
    // Transfer money between accounts
    bool transfer(const QString& fromUserId, const QString& toUserId, double amount);
    
    // Check if account exists
    bool accountExists(const QString& userId);
    
    // Get account creation status
    QString getLastOperationStatus();
*/

/*
// Add these to the "signals:" section

    void transferCompleted(const QString& from, const QString& to, double amount);
    void accountCheckResult(const QString& userId, bool exists);
    void operationStatusChanged(const QString& status);
*/


// ============ IMPLEMENTATION ADDITIONS (bank_bridge.cpp) ============

/*
#include "bank_bridge.h"
#include <QJsonObject>
#include <QJsonArray>
#include <sstream>
#include <iomanip>

// Get list of all user IDs
QJsonArray BankBridge::getAllUserIds() {
    QJsonArray arr;
    // Note: This requires adding a method to the Bank class to iterate all accounts
    // For now returning empty array as placeholder
    return arr;
}

// Get account details as a formatted string
QString BankBridge::getAccountSummary(const QString& userId) {
    try {
        const auto& account = bank_.getAccount(userId.toStdString());
        std::ostringstream oss;
        oss << "User ID: " << account.id() << "\n";
        oss << "Balance: $" << std::fixed << std::setprecision(2) << account.balance();
        return QString::fromStdString(oss.str());
    } catch (const std::exception& e) {
        emit error(QString::fromStdString(e.what()));
        return "";
    }
}

// Transfer money between accounts
bool BankBridge::transfer(const QString& fromUserId, const QString& toUserId, double amount) {
    try {
        if (amount <= 0) {
            emit error("Transfer amount must be positive");
            return false;
        }
        
        // Withdraw from source account
        bank_.withdraw(fromUserId.toStdString(), amount);
        
        // Deposit to destination account
        bank_.deposit(toUserId.toStdString(), amount);
        
        emit transferCompleted(fromUserId, toUserId, amount);
        emit accountsUpdated();
        return true;
    } catch (const std::exception& e) {
        emit error(QString::fromStdString(e.what()));
        return false;
    }
}

// Check if account exists
bool BankBridge::accountExists(const QString& userId) {
    try {
        const auto& account = bank_.getAccount(userId.toStdString());
        emit accountCheckResult(userId, true);
        return true;
    } catch (const std::exception& e) {
        emit accountCheckResult(userId, false);
        return false;
    }
}

// Get account creation status
QString BankBridge::getLastOperationStatus() {
    // This would need to be tracked with a member variable
    return "Operation completed";
}
*/


// ============ QML USAGE EXAMPLES (main.qml) ============

/*
// Example 1: Check if account exists before showing it
Button {
    text: "Check Account"
    onClicked: {
        var exists = bankBridge.accountExists(userIdField.text)
        if (exists) {
            statusMessage.text = "Account found!"
            loadAccountBalance()
        } else {
            statusMessage.text = "Account not found"
        }
    }
}

// Example 2: Transfer money between accounts
TextField {
    id: fromUserField
    placeholderText: "From User ID"
}

TextField {
    id: toUserField
    placeholderText: "To User ID"
}

TextField {
    id: transferAmountField
    placeholderText: "Amount to transfer"
}

Button {
    text: "Transfer Funds"
    onClicked: {
        var success = bankBridge.transfer(
            fromUserField.text,
            toUserField.text,
            parseFloat(transferAmountField.text)
        )
        if (success) {
            statusMessage.text = "Transfer successful!"
            fromUserField.text = ""
            toUserField.text = ""
            transferAmountField.text = ""
        }
    }
}

// Example 3: Get account summary
Button {
    text: "Get Summary"
    onClicked: {
        var summary = bankBridge.getAccountSummary(userIdField.text)
        summaryDisplay.text = summary
    }
}

// Example 4: React to signals
Connections {
    target: bankBridge
    
    onTransferCompleted: {
        statusMessage.text = "Transfer: " + from + " → " + to + 
                             " ($" + amount.toFixed(2) + ")"
    }
    
    onAccountCheckResult: {
        var msg = "Account '" + userId + "' " + 
                  (exists ? "exists" : "does not exist")
        statusMessage.text = msg
    }
}
*/


// ============ UPDATING BANK CLASS ============

/*
If you need to iterate all accounts, add this to bank.h:

public:
    std::unordered_map<UserId, Account>::const_iterator begin() const {
        return accounts_.begin();
    }
    
    std::unordered_map<UserId, Account>::const_iterator end() const {
        return accounts_.end();
    }
    
    size_t size() const {
        return accounts_.size();
    }

Then use it in bank_bridge.cpp:

QJsonArray BankBridge::getAllUserIds() {
    QJsonArray arr;
    for (const auto& [userId, account] : accounts_) {
        arr.append(QString::fromStdString(userId));
    }
    return arr;
}
*/
