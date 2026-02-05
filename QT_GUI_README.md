# Bank System - Qt QML 6 GUI

## Overview

Your bank system now includes a modern Qt QML 6 graphical user interface! The GUI provides a user-friendly way to manage bank accounts without using the command-line interface.

## Features

The Qt QML GUI includes three main tabs:

### 1. **Create Account Tab**
- Create new bank accounts by entering a user ID
- Optionally set an initial balance
- Real-time account creation with instant feedback

### 2. **Manage Account Tab**
- View current account balance
- Perform deposit operations
- Perform withdrawal operations
- Delete accounts when needed
- Real-time balance updates

### 3. **View Accounts Tab**
- Look up account details by user ID
- Display account information including user ID and balance
- Easy account information retrieval

## Architecture

### C++ Bridge Layer

A new `BankBridge` class (`bank_bridge.h` and `bank_bridge.cpp`) acts as a bridge between the C++ backend and QML frontend:

- **Location**: `include/bank_bridge.h` and `src/bank/bank_bridge.cpp`
- **Functionality**: Exposes bank operations as Qt slots callable from QML
- **Signals**: Emits signals for account creation, deletion, balance changes, and errors

### QML User Interface

The UI is defined in `app/main.qml` and uses Qt Quick Controls:

- **Design**: Modern Material Design style
- **Layout**: Tab-based navigation with responsive layouts
- **Components**: Text fields, buttons, rectangles, and status messages

## Building the Project

### Prerequisites

Make sure you have Qt 6 installed on your system:

```bash
# Ubuntu/Debian
sudo apt install qt6-base-dev qt6-qml-dev qt6-quick-dev

# Or download from https://www.qt.io/download-open-source
```

### Build Steps

```bash
cd /path/to/bank_system
mkdir -p build
cd build
cmake ..
make -j$(nproc)
```

### Running the Application

```bash
./build/app/bank_system
```

The GUI window will open with tabs for managing accounts.

## Project Structure

```
bank_system/
├── app/
│   ├── main.cpp           # Qt application entry point
│   ├── main.qml           # QML user interface
│   ├── resources.qrc      # Qt resource file
│   └── CMakeLists.txt
├── include/
│   ├── bank_bridge.h      # C++/QML bridge interface
│   ├── bank.h
│   ├── account.h
│   └── ...
├── src/
│   ├── bank/
│   │   ├── bank_bridge.cpp     # Bridge implementation
│   │   ├── bank.cpp
│   │   ├── account.cpp
│   │   └── CMakeLists.txt
│   ├── cli/               # Original CLI (still available)
│   └── ...
└── CMakeLists.txt
```

## Key Changes from Original Project

1. **Updated CMakeLists.txt**: Added Qt6 requirements and CMAKE_AUTOMOC
2. **New BankBridge Class**: Provides Qt-compatible interface to bank operations
3. **QML User Interface**: Modern UI for account management
4. **Updated App Entry Point**: Switched from CLI to Qt GUI
5. **Dual Library Setup**: Bank core logic remains separate, bridge connects it to Qt

## CMake Configuration

The CMake build system now:

- Finds Qt6 with Core, Gui, Qml, and Quick modules
- Enables AUTOMOC for automatic signal/slot code generation
- Enables AUTORCC for automatic resource compilation
- Creates a shared library for `bank_bridge` (required for Qt's MOC)
- Compiles bank core library with Position Independent Code (PIC) for shared object compatibility

## Extending the GUI

To add more features to the QML interface:

1. **Add new slots to BankBridge** in `bank_bridge.h`
2. **Implement the slots** in `bank_bridge.cpp`
3. **Update main.qml** to add UI elements that call the new slots
4. **Rebuild** the project with `make`

Example - Adding a new operation:

```cpp
// In bank_bridge.h
public slots:
    double getBalance(const QString& userId);

// In bank_bridge.cpp
double BankBridge::getBalance(const QString& userId) {
    try {
        const auto& account = bank_.getAccount(userId.toStdString());
        return account.balance();
    } catch (const std::exception& e) {
        emit error(QString::fromStdString(e.what()));
        return -1.0;
    }
}
```

Then call it from QML:
```qml
var balance = bankBridge.getBalance(userIdField.text)
```

## Data Persistence

The application maintains all data in `accounts.json`:

- Accounts are automatically saved when the "Save" button is clicked
- Data is also saved when the application exits
- The JSON format remains compatible with the original CLI version

## Original CLI Mode

The original command-line interface is still available. You can build and run it separately:

1. Modify `app/main.cpp` to use the CLI instead of Qt
2. Or create a separate CMake configuration for the CLI executable

## Troubleshooting

### Build Errors

**"Could not find Qt6"**: Make sure Qt6 is installed and cmake can find it:
```bash
cmake .. -DCMAKE_PREFIX_PATH=/path/to/Qt6
```

### Runtime Issues

**"Could not load the Qt platform plugin"**: Set the Qt plugin path:
```bash
export QT_QPA_PLATFORM_PLUGIN_PATH=/path/to/Qt6/plugins
./app/bank_system
```

**"Blank QML window"**: Check that `main.qml` is in the resources and properly compiled into the executable.

## Future Enhancements

Potential improvements to the GUI:

- Account list view with sorting/filtering
- Transaction history display
- Import/export functionality
- Multi-user authentication
- Account statistics and charts
- Dark/light theme toggle
- Keyboard shortcuts
- Undo/redo functionality

## License

Same as the original bank system project.
