// json_persistence.h
#pragma once
#include "ipersistence.h"
#include <string>

class JsonPersistence : public IPersistence {
public:
    explicit JsonPersistence(const std::string& filename);
    void save(const std::unordered_map<int, Account>& accounts) override;
    std::unordered_map<int, Account> load() override;

private:
    std::string filename_;
};