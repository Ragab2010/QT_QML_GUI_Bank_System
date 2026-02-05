#pragma once
#include <QObject>
#include <QString>
#include <QJsonArray>
#include <QJsonObject>
#include "bank.h"

class BankBridge : public QObject {
    Q_OBJECT

public:
    explicit BankBridge(Bank& bank, QObject* parent = nullptr);
    ~BankBridge();

public slots:
    int createAccount(const QString& personName, const QString& cardId, double initialBalance = 0.0);
    bool deleteAccount(int accountId);
    void deposit(int accountId, double amount);
    void withdraw(int accountId, double amount);
    QJsonObject getAccount(int accountId);
    QJsonArray getAllAccounts();
    void saveData();
    void getAccountDetails(int accountId);
    void getPersonAccounts(const QString& personName);
    void getAllAccountDetails();

signals:
    void accountCreated(int accountId);
    void accountDeleted(int accountId);
    void balanceChanged(int accountId, double newBalance);
    void error(const QString& message);
    void accountsUpdated();
    void detailsRetrieved(const QJsonObject& details);
    void personAccountsRetrieved(const QString& accountsList);
    void allAccountsRetrieved(const QString& accountsList);

private:
    Bank& bank_;
};
