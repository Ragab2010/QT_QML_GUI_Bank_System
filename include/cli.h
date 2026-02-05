// cli.h
#pragma once
#include "ibank.h"
#include <iostream>

class CLI {
public:
    explicit CLI(IBank& bank) : bank_(bank) {}

    void run();

private:
    void showMenu() const;
    bool handleChoice(int choice);

private:
    IBank& bank_;
};
