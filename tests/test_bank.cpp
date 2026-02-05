#include <catch2/catch_test_macros.hpp>
#include "bank.h"
#include "json_persistence.h"
#include <filesystem>

TEST_CASE("Bank create account", "[bank]") {
    std::string testFile = "test_bank.json";
    std::filesystem::remove(testFile);

    JsonPersistence persistence(testFile);
    Bank bank(persistence);

    REQUIRE(bank.createAccount("user1"));
    REQUIRE_FALSE(bank.createAccount("user1")); // Duplicate

    REQUIRE(bank.getAccount("user1").id() == "user1");
    REQUIRE(bank.getAccount("user1").balance() == 0.0);

    bank.save();
    std::filesystem::remove(testFile);
}

TEST_CASE("Bank deposit and withdraw", "[bank]") {
    std::string testFile = "test_bank2.json";
    std::filesystem::remove(testFile);

    JsonPersistence persistence(testFile);
    Bank bank(persistence);

    bank.createAccount("user1");
    bank.deposit("user1", 100.0);
    REQUIRE(bank.getAccount("user1").balance() == 100.0);

    bank.withdraw("user1", 50.0);
    REQUIRE(bank.getAccount("user1").balance() == 50.0);

    REQUIRE_THROWS_AS(bank.withdraw("user1", 100.0), std::runtime_error);

    bank.save();
    std::filesystem::remove(testFile);
}

TEST_CASE("Bank delete account", "[bank]") {
    std::string testFile = "test_bank3.json";
    std::filesystem::remove(testFile);

    JsonPersistence persistence(testFile);
    Bank bank(persistence);

    bank.createAccount("user1");
    REQUIRE(bank.deleteAccount("user1"));
    REQUIRE_FALSE(bank.deleteAccount("user1"));

    REQUIRE_THROWS_AS(bank.getAccount("user1"), std::runtime_error);

    bank.save();
    std::filesystem::remove(testFile);
}

TEST_CASE("Bank load from persistence", "[bank]") {
    std::string testFile = "test_bank4.json";
    std::filesystem::remove(testFile);

    {
        JsonPersistence persistence(testFile);
        std::unordered_map<UserId, Account> accounts;
        accounts.emplace("user1", Account("user1", 150.0));
        persistence.save(accounts);
    }

    JsonPersistence loadPersistence(testFile);
    Bank bank(loadPersistence);

    REQUIRE(bank.getAccount("user1").balance() == 150.0);

    std::filesystem::remove(testFile);
}