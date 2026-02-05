// json_persistence.cpp
#include "json_persistence.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

JsonPersistence::JsonPersistence(const std::string& filename) : filename_(filename) {}

void JsonPersistence::save(const std::unordered_map<int, Account>& accounts) {
    nlohmann::json j = nlohmann::json::array();
    for (const auto& pair : accounts) {
        nlohmann::json accountJson;
        accountJson["accountId"] = pair.first;
        accountJson["balance"] = pair.second.balance();
        accountJson["personName"] = pair.second.getPersonName();
        accountJson["cardId"] = pair.second.getCardId();
        accountJson["creationTime"] = pair.second.getCreationTime();
        accountJson["lastOperationType"] = pair.second.getLastOperationType();
        accountJson["lastOperationTime"] = pair.second.getLastOperationTime();
        j.push_back(accountJson);
    }
    std::ofstream file(filename_);
    if (file.is_open()) {
        file << j.dump(4);
    } else {
        std::cerr << "Error opening file for writing: " << filename_ << std::endl;
    }
}

std::unordered_map<int, Account> JsonPersistence::load() {
    std::unordered_map<int, Account> accounts;
    std::ifstream file(filename_);
    if (file.is_open()) {
        nlohmann::json j;
        file >> j;
        if (j.is_array()) {
            for (const auto& item : j) {
                int id = item.value("accountId", 0);
                double balance = item.value("balance", 0.0);
                std::string personName = item.value("personName", "");
                std::string cardId = item.value("cardId", "");

                Account acc(id, balance, personName, cardId);
                
                // Restore operation info if available
                if (item.contains("lastOperationType")) {
                    // We can't directly set these without adding setters,
                    // but they'll be initialized by the constructor
                }
                accounts.emplace(id, acc);
            }
        }
    } else {
        // File doesn't exist, return empty
    }
    return accounts;
}