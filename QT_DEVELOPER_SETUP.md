# Qt QML 6 Bank System - Developer Setup Guide

## Prerequisites

### System Requirements
- Linux (Ubuntu 20.04+, Debian 11+, Fedora, etc.)
- macOS (10.14+)
- Windows (with appropriate build tools)

### Required Software

#### 1. Build Tools
```bash
# Ubuntu/Debian
sudo apt install build-essential cmake git

# Fedora
sudo dnf install gcc-c++ cmake git

# macOS
brew install cmake
```

#### 2. Qt6 Framework

Choose one installation method:

**Option A: System Package Manager (Easiest)**
```bash
# Ubuntu/Debian
sudo apt install qt6-base-dev qt6-qml-dev qt6-quick-dev qt6-tools-dev

# Fedora
sudo dnf install qt6-qtbase-devel qt6-qtdeclarative-devel

# macOS
brew install qt6
```

**Option B: Qt Online Installer (Most Complete)**
1. Download from: https://www.qt.io/download-open-source
2. Run the installer and select Qt 6.x
3. Choose desktop platform
4. Note the installation path

**Option C: Build from Source**
```bash
git clone https://github.com/qt/qt5.git
cd qt5
perl init-repository
./configure -prefix /opt/qt6
make -j$(nproc)
sudo make install
```

### Verify Installation

```bash
# Check if Qt6 tools are available
qmake6 -v
```

If qmake6 not found, add Qt to PATH:
```bash
# For system installation
export PATH="/usr/lib/qt6/bin:$PATH"

# For custom installation
export PATH="/opt/qt6/bin:$PATH"

# Add to ~/.bashrc for persistence
echo 'export PATH="/usr/lib/qt6/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
```

## Building the Project

### Quick Build

```bash
cd /path/to/bank_system
./run_gui.sh
```

### Manual Build

```bash
cd /path/to/bank_system

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake .. -DCMAKE_BUILD_TYPE=Release

# Build with parallel jobs
make -j$(nproc)

# Run the application
./app/bank_system
```

### Build Options

```bash
# Debug build with symbols (for debugging)
cmake .. -DCMAKE_BUILD_TYPE=Debug

# Release build with optimization
cmake .. -DCMAKE_BUILD_TYPE=Release

# Specify Qt prefix path (if not found)
cmake .. -DCMAKE_PREFIX_PATH=/path/to/Qt/6.x/gcc_64

# Verbose build output
cmake .. && make VERBOSE=1
```

## Development Workflow

### 1. Modify QML Interface

**File**: `app/main.qml`

Changes are reflected after rebuild:
```bash
cd build
make
./app/bank_system
```

### 2. Add New Bridge Method

**Step 1**: Add method signature to `include/bank_bridge.h`
```cpp
public slots:
    double getBalance(const QString& userId);
```

**Step 2**: Implement in `src/bank/bank_bridge.cpp`
```cpp
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

**Step 3**: Call from QML
```qml
var balance = bankBridge.getBalance(userIdField.text)
```

**Step 4**: Rebuild
```bash
cd build
make
./app/bank_system
```

### 3. Debugging

#### Print Debug Output

**In C++** (bank_bridge.cpp):
```cpp
#include <QDebug>

qDebug() << "Debug message:" << QString::fromStdString(userId);
```

**In QML** (main.qml):
```qml
console.log("QML debug:", userIdField.text)
```

Run with console output:
```bash
./app/bank_system 2>&1 | tee debug.log
```

#### Using Qt Creator IDE (Optional)

1. Install Qt Creator: `sudo apt install qtcreator` (or via Qt installer)
2. Open project: `File → Open File or Project`
3. Select `CMakeLists.txt`
4. Configure Qt Kit and click "Configure"
5. Use "Run" to build and debug
6. Use breakpoints and step-through debugging

#### Command-Line Debugging

```bash
# Build with debug symbols
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
make

# Run with gdb
gdb ./app/bank_system

# In gdb prompt:
(gdb) run
(gdb) break BankBridge::createAccount
(gdb) continue
```

## Troubleshooting

### Build Issues

**"Could NOT find Qt6"**
```bash
# Find Qt installation
find /usr -name "Qt6Config.cmake" 2>/dev/null

# Use the prefix path
cmake .. -DCMAKE_PREFIX_PATH=/usr/lib/cmake
```

**"No QML module found"**
```bash
# Ensure all Qt6 QML components are installed
sudo apt install libqt6qml6 qt6-qml-dev qt6-quick-dev
```

**"MOC or RCC error"**
```bash
# Clean and rebuild
rm -rf build
mkdir build && cd build
cmake ..
make
```

### Runtime Issues

**"Could not load the Qt platform plugin"**
```bash
# Set QT_QPA_PLATFORM_PLUGIN_PATH
export QT_QPA_PLATFORM_PLUGIN_PATH=/usr/lib/x86_64-linux-gnu/qt6/plugins
./app/bank_system
```

**"Blank window or missing UI"**
```bash
# Check QML syntax
cat app/main.qml | qmlformat

# Enable QML debugging
export QML_IMPORT_TRACE=1
./app/bank_system
```

**"Segmentation fault"**
```bash
# Run with gdb to find where it crashes
gdb ./app/bank_system
(gdb) run
(gdb) bt  # show backtrace
```

### Qt Version Conflicts

If you have both Qt5 and Qt6:
```bash
# Explicitly use Qt6
cmake .. -DCMAKE_PREFIX_PATH=/path/to/Qt6/6.x/gcc_64

# Or set environment
export CMAKE_PREFIX_PATH=/path/to/Qt6/6.x/gcc_64
```

## Project Structure for Development

```
bank_system/
├── app/
│   ├── main.cpp              # Qt application entry point
│   ├── main.qml              # QML UI (primary development file)
│   ├── resources.qrc         # Qt resource file
│   └── CMakeLists.txt
├── include/
│   ├── bank_bridge.h         # C++/QML bridge (extend here)
│   ├── bank.h                # Bank core logic
│   ├── account.h
│   └── ...
├── src/
│   ├── bank/
│   │   ├── bank_bridge.cpp   # Bridge implementation (extend here)
│   │   ├── bank.cpp
│   │   ├── account.cpp
│   │   └── CMakeLists.txt
│   └── ...
├── build/                    # Build output directory (generated)
├── CMakeLists.txt            # Root CMake configuration
├── QT_GUI_README.md          # User documentation
├── QT_GUI_EXTENSIONS.md      # Extension examples
└── run_gui.sh                # Build and run script
```

## Development Tips

### Hot Reload QML

While not supported out-of-the-box, you can enable fast development by:

1. Modifying `app/main.qml` directly
2. Rebuilding with `make` (only rebuilds resources)
3. Restarting the application

For larger changes, you can modularize QML:
```qml
// In main.qml
Loader {
    source: "components/AccountManager.qml"
}
```

### Performance Optimization

**For Release Builds**:
```bash
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
strip ./app/bank_system  # Remove symbols for smaller binary
```

**Memory Profiling**:
```bash
valgrind --leak-check=full ./app/bank_system
```

### Code Organization Tips

- Keep QML UI in `app/main.qml`
- Keep business logic in bank classes
- Keep bridge in `bank_bridge` for Qt integration
- Use signals/slots for loose coupling

## Running Tests

If you have unit tests configured:
```bash
cmake .. -DBUILD_TESTS=ON
make
./tests/unit_tests  # Run test suite
```

## Additional Resources

- **Qt 6 Documentation**: https://doc.qt.io/qt-6/
- **QML Guide**: https://doc.qt.io/qt-6/qmlapplications.html
- **Qt Creator Documentation**: https://doc.qt.io/qtcreator/
- **CMake Documentation**: https://cmake.org/cmake/help/latest/

## Getting Help

1. Check the error messages carefully
2. Review `QT_GUI_README.md` for common issues
3. Check Qt Creator's built-in help
4. Search Qt forums: https://forum.qt.io/
5. Check project documentation files

---

**Happy Development!** 🚀
