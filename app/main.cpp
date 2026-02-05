#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "bank.h"
#include "json_persistence.h"
#include "bank_bridge.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Initialize bank system
    JsonPersistence persistence("accounts.json");
    Bank bank(persistence);

    // Create bridge and expose to QML
    BankBridge bridge(bank);

    // Setup QML engine
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("bankBridge", &bridge);

    const QUrl url(QStringLiteral("qrc:/app/main.qml"));
    engine.load(url);

    if (engine.rootObjects().isEmpty())
        return -1;

    int result = app.exec();

    // Save data on exit
    bank.save();

    return result;
}