#include <catch2/catch_test_macros.hpp>
#include "account.h"

TEST_CASE("Account creation", "[account]") {
    Account acc("user1", 100.0);
    REQUIRE(acc.id() == "user1");
    REQUIRE(acc.balance() == 100.0);
}

TEST_CASE("Account deposit", "[account]") {
    Account acc("user1", 100.0);
    acc.deposit(50.0);
    REQUIRE(acc.balance() == 150.0);
}

TEST_CASE("Account withdraw", "[account]") {
    Account acc("user1", 100.0);
    acc.withdraw(30.0);
    REQUIRE(acc.balance() == 70.0);
}

TEST_CASE("Account withdraw insufficient funds", "[account]") {
    Account acc("user1", 50.0);
    REQUIRE_THROWS_AS(acc.withdraw(100.0), std::runtime_error);
    REQUIRE(acc.balance() == 50.0);
}