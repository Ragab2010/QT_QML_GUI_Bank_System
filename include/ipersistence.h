// ipersistence.h
#pragma once
#include "account.h"
#include <unordered_map>

class IPersistence {
public:
    virtual ~IPersistence() = default;
    virtual void save(const std::unordered_map<int, Account>& accounts) = 0;
    virtual std::unordered_map<int, Account> load() = 0;
};