#include <catch2/catch_test_macros.hpp>
#include "json_persistence.h"
#include <filesystem>
#include <unordered_map>

TEST_CASE("JsonPersistence save and load", "[persistence]") {
    std::string testFile = "test_accounts.json";
    JsonPersistence persistence(testFile);

    // Clean up before test
    std::filesystem::remove(testFile);

    std::unordered_map<UserId, Account> accounts;
    accounts.emplace("user1", Account("user1", 100.0));
    accounts.emplace("user2", Account("user2", 200.0));

    persistence.save(accounts);

    // Load in new persistence instance
    JsonPersistence loadPersistence(testFile);
    auto loaded = loadPersistence.load();

    REQUIRE(loaded.size() == 2);
    REQUIRE(loaded.at("user1").id() == "user1");
    REQUIRE(loaded.at("user1").balance() == 100.0);
    REQUIRE(loaded.at("user2").id() == "user2");
    REQUIRE(loaded.at("user2").balance() == 200.0);

    // Clean up
    std::filesystem::remove(testFile);
}

TEST_CASE("JsonPersistence load empty", "[persistence]") {
    std::string testFile = "test_empty.json";
    std::filesystem::remove(testFile);

    JsonPersistence persistence(testFile);
    auto loaded = persistence.load();

    REQUIRE(loaded.empty());

    // No file to clean
}