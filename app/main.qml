import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window

ApplicationWindow {
    id: root
    visible: true
    width: 1200
    height: 750
    title: "Universal Bank System"

    color: "#f5f5f5"

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 15

        // Header
        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 60
            color: "#2196F3"
            radius: 5

            Text {
                anchors.centerIn: parent
                text: "Universal Bank Management System"
                font.pixelSize: 28
                font.bold: true
                color: "white"
            }
        }

        // Tab navigation
        TabBar {
            id: tabBar
            Layout.fillWidth: true
            currentIndex: 0

            TabButton {
                text: "1. Create Account"
            }
            TabButton {
                text: "2. Account Details"
            }
            TabButton {
                text: "3. Manage Account"
            }
            TabButton {
                text: "4. Search Person"
            }
            TabButton {
                text: "5. All Accounts"
            }
        }

        // Content area
        StackLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            currentIndex: tabBar.currentIndex

            // ==================== TAB 1: CREATE ACCOUNT ====================
            Rectangle {
                color: "white"
                radius: 5

                ColumnLayout {
                    anchors.fill: parent
                    anchors.margins: 20
                    spacing: 15

                    Text {
                        text: "Create New Account"
                        font.pixelSize: 18
                        font.bold: true
                    }

                    RowLayout {
                        spacing: 10

                        Text {
                            text: "Person Name:"
                            Layout.preferredWidth: 120
                        }

                        TextField {
                            id: createPersonNameField
                            Layout.fillWidth: true
                            placeholderText: "Enter person's name"
                            background: Rectangle {
                                border.color: "#ccc"
                                border.width: 1
                                radius: 3
                            }
                        }
                    }

                    RowLayout {
                        spacing: 10

                        Text {
                            text: "National Card ID:"
                            Layout.preferredWidth: 120
                        }

                        TextField {
                            id: createCardIdField
                            Layout.fillWidth: true
                            placeholderText: "Enter 14-digit national card ID"
                            background: Rectangle {
                                border.color: "#ccc"
                                border.width: 1
                                radius: 3
                            }
                        }
                    }

                    RowLayout {
                        spacing: 10

                        Text {
                            text: "Initial Balance:"
                            Layout.preferredWidth: 120
                        }

                        TextField {
                            id: initialBalanceField
                            Layout.fillWidth: true
                            placeholderText: "Enter initial balance (optional)"
                            validator: DoubleValidator { }
                            background: Rectangle {
                                border.color: "#ccc"
                                border.width: 1
                                radius: 3
                            }
                        }
                    }

                    Button {
                        text: "Create Account"
                        hoverEnabled: true
                        Layout.preferredWidth: 150
                        Layout.preferredHeight: 40
                        background: Rectangle {
                            color: "#4CAF50"
                            radius: 3
                        }
                        
                        contentItem: Text {
                            text: parent.text
                            color: "white"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                        
                        onClicked: {
                            if (createPersonNameField.text.length > 0 && createCardIdField.text.length >= 14) {
                                var accountId = bankBridge.createAccount(
                                    createPersonNameField.text,
                                    createCardIdField.text,
                                    parseFloat(initialBalanceField.text) || 0
                                )
                                if (accountId > 0) {
                                    statusMessage.text = "✓ Account created successfully!\nThe Account ID is: " + accountId
                                } else {
                                    statusMessage.text = "❌ Failed to create account"
                                }
                                createPersonNameField.text = ""
                                createCardIdField.text = ""
                                initialBalanceField.text = ""
                            } else {
                                statusMessage.text = "❌ Please enter name and 14-digit card ID"
                            }
                        }
                    }

                    Item { Layout.fillHeight: true }
                }
            }

            // ==================== TAB 2: ACCOUNT DETAILS ====================
            Rectangle {
                color: "white"
                radius: 5

                ColumnLayout {
                    anchors.fill: parent
                    anchors.margins: 20
                    spacing: 15

                    Text {
                        text: "Account Details"
                        font.pixelSize: 18
                        font.bold: true
                    }

                    RowLayout {
                        spacing: 10
                        Text { text: "Account ID:"; Layout.preferredWidth: 120 }
                        TextField {
                            id: detailsAccountIdField
                            Layout.fillWidth: true
                            placeholderText: "Enter account ID"
                            background: Rectangle { border.color: "#ccc"; border.width: 1; radius: 3 }
                        }
                    }

                    Button {
                        text: "View Details"
                        Layout.preferredWidth: 150
                        Layout.preferredHeight: 40
                        background: Rectangle { color: "#2196F3"; radius: 3 }
                        contentItem: Text { text: parent.text; color: "white"; horizontalAlignment: Text.AlignHCenter; verticalAlignment: Text.AlignVCenter }

                        onClicked: {
                            var accountId = parseInt(detailsAccountIdField.text)
                            if (accountId > 0) {
                                bankBridge.getAccountDetails(accountId)
                            } else {
                                statusMessage.text = "❌ Please enter a valid account ID"
                            }
                        }
                    }

                    Rectangle {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        color: "#f9f9f9"
                        border.color: "#ddd"
                        border.width: 1
                        radius: 3

                        ColumnLayout {
                            anchors.fill: parent
                            anchors.margins: 15
                            spacing: 12

                            Text { text: "Account Information"; font.pixelSize: 14; font.bold: true }
                            Rectangle { Layout.fillWidth: true; Layout.preferredHeight: 1; color: "#ddd" }

                            RowLayout {
                                Text { text: "Account ID:"; Layout.preferredWidth: 140; font.bold: true }
                                Text { id: detailsAccountId; text: "-"; Layout.fillWidth: true }
                            }
                            RowLayout {
                                Text { text: "Owner Name:"; Layout.preferredWidth: 140; font.bold: true }
                                Text { id: detailsOwnerName; text: "-"; Layout.fillWidth: true }
                            }
                            RowLayout {
                                Text { text: "Balance:"; Layout.preferredWidth: 140; font.bold: true }
                                Text { id: detailsBalance; text: "$ 0.00"; Layout.fillWidth: true; color: "#4CAF50"; font.bold: true; font.pixelSize: 16 }
                            }
                            RowLayout {
                                Text { text: "Created:"; Layout.preferredWidth: 140; font.bold: true }
                                Text { id: detailsCreatedTime; text: "-"; Layout.fillWidth: true; wrapMode: Text.WordWrap }
                            }
                            RowLayout {
                                Text { text: "Last Operation:"; Layout.preferredWidth: 140; font.bold: true; verticalAlignment: Text.AlignTop }
                                Text { id: detailsLastOperation; text: "-"; Layout.fillWidth: true; wrapMode: Text.WordWrap }
                            }

                            Item { Layout.fillHeight: true }
                        }
                    }
                }
            }

            // ==================== TAB 3: MANAGE ACCOUNT ====================
            Rectangle {
                color: "white"
                radius: 5

                ColumnLayout {
                    anchors.fill: parent
                    anchors.margins: 20
                    spacing: 15

                    Text {
                        text: "Manage Account"
                        font.pixelSize: 18
                        font.bold: true
                    }

                    RowLayout {
                        spacing: 10
                        Text { text: "Account ID:"; Layout.preferredWidth: 120 }
                        TextField {
                            id: manageAccountIdField
                            Layout.fillWidth: true
                            placeholderText: "Enter account ID"
                            background: Rectangle { border.color: "#ccc"; border.width: 1; radius: 3 }
                        }
                    }

                    Rectangle {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 100
                        color: "#e3f2fd"
                        radius: 5

                        ColumnLayout {
                            anchors.fill: parent
                            anchors.margins: 15

                            Text { text: "Current Balance"; font.pixelSize: 14; font.bold: true }
                            Text { id: manageBalanceDisplay; text: "$ 0.00"; font.pixelSize: 36; font.bold: true; color: "#2196F3" }
                        }
                    }

                    RowLayout {
                        spacing: 10
                        Text { text: "Amount:"; Layout.preferredWidth: 120 }
                        TextField {
                            id: transactionAmountField
                            Layout.fillWidth: true
                            placeholderText: "Enter amount"
                            validator: DoubleValidator { }
                            background: Rectangle { border.color: "#ccc"; border.width: 1; radius: 3 }
                        }
                    }

                    RowLayout {
                        spacing: 10
                        Layout.fillWidth: true

                        Button {
                            text: "Load Balance"
                            Layout.preferredWidth: 120
                            Layout.preferredHeight: 40
                            background: Rectangle { color: "#2196F3"; radius: 3 }
                            contentItem: Text { text: parent.text; color: "white"; horizontalAlignment: Text.AlignHCenter; verticalAlignment: Text.AlignVCenter }

                            onClicked: {
                                var accountId = parseInt(manageAccountIdField.text)
                                if (accountId > 0) {
                                    loadAccountBalance()
                                } else {
                                    statusMessage.text = "❌ Please enter a valid account ID"
                                }
                            }
                        }

                        Button {
                            text: "Deposit"
                            Layout.preferredWidth: 120
                            Layout.preferredHeight: 40
                            background: Rectangle { color: "#4CAF50"; radius: 3 }
                            contentItem: Text { text: parent.text; color: "white"; horizontalAlignment: Text.AlignHCenter; verticalAlignment: Text.AlignVCenter }

                            onClicked: {
                                var accountId = parseInt(manageAccountIdField.text)
                                if (accountId > 0 && parseFloat(transactionAmountField.text) > 0) {
                                    bankBridge.deposit(accountId, parseFloat(transactionAmountField.text))
                                    transactionAmountField.text = ""
                                    loadAccountBalance()
                                } else {
                                    statusMessage.text = "❌ Please enter valid account ID and amount"
                                }
                            }
                        }

                        Button {
                            text: "Withdraw"
                            Layout.preferredWidth: 120
                            Layout.preferredHeight: 40
                            background: Rectangle { color: "#f44336"; radius: 3 }
                            contentItem: Text { text: parent.text; color: "white"; horizontalAlignment: Text.AlignHCenter; verticalAlignment: Text.AlignVCenter }

                            onClicked: {
                                var accountId = parseInt(manageAccountIdField.text)
                                if (accountId > 0 && parseFloat(transactionAmountField.text) > 0) {
                                    bankBridge.withdraw(accountId, parseFloat(transactionAmountField.text))
                                    transactionAmountField.text = ""
                                    loadAccountBalance()
                                } else {
                                    statusMessage.text = "❌ Please enter valid account ID and amount"
                                }
                            }
                        }

                        Button {
                            text: "Delete"
                            Layout.preferredWidth: 120
                            Layout.preferredHeight: 40
                            background: Rectangle { color: "#ff9800"; radius: 3 }
                            contentItem: Text { text: parent.text; color: "white"; horizontalAlignment: Text.AlignHCenter; verticalAlignment: Text.AlignVCenter }

                            onClicked: {
                                var accountId = parseInt(manageAccountIdField.text)
                                if (accountId > 0) {
                                    bankBridge.deleteAccount(accountId)
                                    manageAccountIdField.text = ""
                                    manageBalanceDisplay.text = "$ 0.00"
                                } else {
                                    statusMessage.text = "❌ Please enter a valid account ID"
                                }
                            }
                        }

                        Item { Layout.fillWidth: true }
                    }

                    Item { Layout.fillHeight: true }
                }
            }

            // ==================== TAB 4: SEARCH PERSON ====================
            Rectangle {
                color: "white"
                radius: 5

                ColumnLayout {
                    anchors.fill: parent
                    anchors.margins: 20
                    spacing: 15

                    Text {
                        text: "Search Person Accounts"
                        font.pixelSize: 18
                        font.bold: true
                    }

                    RowLayout {
                        spacing: 10
                        Text { text: "Person Name:"; Layout.preferredWidth: 120 }
                        TextField {
                            id: searchPersonNameField
                            Layout.fillWidth: true
                            placeholderText: "Enter person's name"
                            background: Rectangle { border.color: "#ccc"; border.width: 1; radius: 3 }
                        }
                    }

                    Button {
                        text: "Search"
                        Layout.preferredWidth: 150
                        Layout.preferredHeight: 40
                        background: Rectangle { color: "#2196F3"; radius: 3 }
                        contentItem: Text { text: parent.text; color: "white"; horizontalAlignment: Text.AlignHCenter; verticalAlignment: Text.AlignVCenter }

                        onClicked: {
                            if (searchPersonNameField.text.length > 0) {
                                bankBridge.getPersonAccounts(searchPersonNameField.text)
                            } else {
                                statusMessage.text = "❌ Please enter a person name"
                            }
                        }
                    }

                    Rectangle {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        color: "#f9f9f9"
                        border.color: "#ddd"
                        border.width: 1
                        radius: 3

                        ColumnLayout {
                            anchors.fill: parent
                            anchors.margins: 15
                            spacing: 10

                            Text { text: "Accounts for This Person"; font.pixelSize: 14; font.bold: true }
                            Rectangle { Layout.fillWidth: true; Layout.preferredHeight: 1; color: "#ddd" }

                            ScrollView {
                                Layout.fillWidth: true
                                Layout.fillHeight: true

                                TextArea {
                                    id: personAccountsDisplay
                                    readOnly: true
                                    wrapMode: TextArea.Wrap
                                    text: "Search results will appear here"
                                    font.family: "Courier"
                                    font.pixelSize: 11
                                }
                            }
                        }
                    }
                }
            }

            // ==================== TAB 5: ALL ACCOUNTS ====================
            Rectangle {
                color: "white"
                radius: 5

                ColumnLayout {
                    anchors.fill: parent
                    anchors.margins: 20
                    spacing: 15

                    Text {
                        text: "All Accounts Details"
                        font.pixelSize: 18
                        font.bold: true
                    }

                    Button {
                        text: "Refresh All Accounts"
                        Layout.preferredWidth: 200
                        Layout.preferredHeight: 40
                        background: Rectangle { color: "#2196F3"; radius: 3 }
                        contentItem: Text { text: parent.text; color: "white"; horizontalAlignment: Text.AlignHCenter; verticalAlignment: Text.AlignVCenter }

                        onClicked: {
                            bankBridge.getAllAccountDetails()
                        }
                    }

                    Rectangle {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        color: "#f9f9f9"
                        border.color: "#ddd"
                        border.width: 1
                        radius: 3

                        ColumnLayout {
                            anchors.fill: parent
                            anchors.margins: 15
                            spacing: 10

                            Text { text: "All Accounts in System"; font.pixelSize: 14; font.bold: true }
                            Rectangle { Layout.fillWidth: true; Layout.preferredHeight: 1; color: "#ddd" }

                            ScrollView {
                                Layout.fillWidth: true
                                Layout.fillHeight: true

                                TextArea {
                                    id: allAccountsDisplay
                                    readOnly: true
                                    wrapMode: TextArea.Wrap
                                    text: "Click 'Refresh All Accounts' to load data"
                                    font.family: "Courier"
                                    font.pixelSize: 11
                                }
                            }
                        }
                    }
                }
            }
        }

        // Status message
        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 40
            color: "#fff3cd"
            border.color: "#ffc107"
            border.width: 1
            radius: 3
            visible: statusMessage.text.length > 0

            Text {
                id: statusMessage
                anchors.fill: parent
                anchors.margins: 10
                verticalAlignment: Text.AlignVCenter
                color: "#856404"
                wrapMode: Text.WordWrap
            }
        }

        // Footer with Save button
        RowLayout {
            Layout.fillWidth: true
            spacing: 10

            Item { Layout.fillWidth: true }

            Button {
                text: "Save"
                Layout.preferredWidth: 100
                Layout.preferredHeight: 40
                background: Rectangle {
                    color: "#2196F3"
                    radius: 3
                }
                contentItem: Text {
                    text: parent.text
                    color: "white"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                onClicked: {
                    bankBridge.saveData()
                    statusMessage.text = "Data saved successfully!"
                }
            }

            Button {
                text: "Exit"
                Layout.preferredWidth: 100
                Layout.preferredHeight: 40
                background: Rectangle {
                    color: "#f44336"
                    radius: 3
                }
                contentItem: Text {
                    text: parent.text
                    color: "white"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                onClicked: Qt.quit()
            }
        }
    }

    function loadAccountBalance() {
        var accountId = manageAccountIdField.text
        if (accountId.length > 0) {
            var account = bankBridge.getAccount(accountId)
            if (account && account.accountId) {
                manageBalanceDisplay.text = "$ " + account.balance.toFixed(2)
                statusMessage.text = ""
            } else {
                statusMessage.text = "❌ Account not found"
                manageBalanceDisplay.text = "$ 0.00"
            }
        }
    }

    Connections {
        target: bankBridge

        function onError(message) {
            statusMessage.text = "❌ Error: " + message
        }

        function onAccountCreated(info) {
            statusMessage.text = "✓ Account created: " + info
        }

        function onBalanceChanged(accountId, newBalance) {
            statusMessage.text = "✓ Balance updated to: $" + newBalance.toFixed(2)
            manageBalanceDisplay.text = "$ " + newBalance.toFixed(2)
        }

        function onDetailsRetrieved(details) {
            if (details) {
                detailsAccountId.text = details.accountId || "-"
                detailsOwnerName.text = details.owner || "-"
                detailsBalance.text = "$ " + (details.balance || 0).toFixed(2)
                detailsCreatedTime.text = details.createdTime || "-"
                detailsLastOperation.text = (details.lastOperationType || "None") + "\n" + (details.lastOperationTime || "-")
                statusMessage.text = ""
            }
        }

        function onPersonAccountsRetrieved(accountsList) {
            personAccountsDisplay.text = accountsList || "No accounts found for this person"
            statusMessage.text = ""
        }

        function onAllAccountsRetrieved(accountsList) {
            allAccountsDisplay.text = accountsList || "No accounts in system"
            statusMessage.text = ""
        }

        function onAccountDeleted(message) {
            statusMessage.text = "✓ " + message
        }
    }
}
