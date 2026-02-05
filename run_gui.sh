#!/bin/bash
# Quick build and run script for the Qt QML Bank System

set -e

echo "=========================================="
echo "Qt QML Bank System - Build and Run"
echo "=========================================="
echo ""

# Check if Qt6 is installed
if ! command -v qmake6 &> /dev/null; then
    echo "ERROR: Qt6 is not installed!"
    echo ""
    echo "Install Qt6 with:"
    echo "  Ubuntu/Debian: sudo apt install qt6-base-dev qt6-qml-dev qt6-quick-dev"
    echo "  Or download from: https://www.qt.io/download-open-source"
    exit 1
fi

echo "Qt6 found: $(qmake6 -v | head -1)"
echo ""

# Create build directory
echo "Creating build directory..."
mkdir -p build
cd build

# Run CMake
echo "Configuring with CMake..."
cmake ..

# Build
echo ""
echo "Building project..."
make -j$(nproc)

# Run
echo ""
echo "=========================================="
echo "Build successful!"
echo "=========================================="
echo ""
echo "Running application..."
echo ""

cd app
./bank_system
