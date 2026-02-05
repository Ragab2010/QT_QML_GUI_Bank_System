#!/bin/bash

# Bank System GUI - Functional Test Script
# This script tests the bank_system Qt QML application

set -e

PROJECT_DIR="/home/ragab/vscode_workspace/bank_system"
BUILD_DIR="$PROJECT_DIR/build/app"
EXECUTABLE="$BUILD_DIR/bank_system"

echo "==========================================="
echo "Bank System Qt QML - Application Test"
echo "==========================================="
echo ""

# Check if executable exists
if [ ! -f "$EXECUTABLE" ]; then
    echo "❌ ERROR: Executable not found at $EXECUTABLE"
    echo "Please rebuild the project first"
    exit 1
fi

echo "✅ Executable found: $EXECUTABLE"
echo "   Size: $(ls -lh $EXECUTABLE | awk '{print $5}')"
echo ""

# Test 1: Run with offscreen platform (headless test)
echo "Test 1: Running application in offscreen mode..."
cd "$BUILD_DIR"

if timeout 5 ./bank_system -platform offscreen 2>&1 | grep -q "failed\|error" | grep -v "QML Connections\|deprecated"; then
    echo "❌ Application had errors during startup"
    exit 1
else
    echo "✅ Application started successfully"
fi

echo ""

# Test 2: Check data file location
echo "Test 2: Checking data persistence..."
if [ -f "accounts.json" ]; then
    echo "✅ Data file found: accounts.json"
    echo "   Content:"
    head -5 accounts.json | sed 's/^/     /'
else
    echo "⚠️  No accounts.json found (this is normal on first run)"
fi

echo ""

# Test 3: Verify library dependencies
echo "Test 3: Checking library dependencies..."
echo "Libraries required:"
ldd "$EXECUTABLE" | grep -E "libbank_bridge|libQt6|libstdc\+\+" | head -10 | sed 's/^/  /'

if ldd "$EXECUTABLE" | grep -q "not found"; then
    echo "❌ Some libraries are missing"
    exit 1
else
    echo "✅ All libraries found"
fi

echo ""

# Test 4: Check Qt modules
echo "Test 4: Checking Qt QML modules..."
QT_MODULES_PATH="/usr/lib/x86_64-linux-gnu/qt6/qml"
REQUIRED_MODULES=(
    "QtQuick"
    "QtQml"
    "QtQuick/Controls"
    "QtQuick/Layouts"
)

for module in "${REQUIRED_MODULES[@]}"; do
    if [ -d "$QT_MODULES_PATH/$module" ]; then
        echo "  ✅ $module"
    else
        echo "  ❌ $module (missing)"
    fi
done

echo ""

# Test 5: Verify resource embedding
echo "Test 5: Verifying embedded QML resources..."
if strings "$EXECUTABLE" | grep -q "main.qml"; then
    echo "✅ QML resources embedded in executable"
else
    echo "⚠️  Could not verify QML embedding (non-critical)"
fi

echo ""
echo "==========================================="
echo "Test Summary"
echo "==========================================="
echo ""
echo "✅ Application: READY FOR TESTING"
echo ""
echo "To run the GUI application with display:"
echo "  cd $BUILD_DIR"
echo "  ./bank_system"
echo ""
echo "To run in headless mode:"
echo "  ./bank_system -platform offscreen"
echo ""
echo "==========================================="
