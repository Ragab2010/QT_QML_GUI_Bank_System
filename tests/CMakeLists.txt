add_executable(unit_tests
    test_account.cpp
    test_bank.cpp
    test_persistence.cpp
)

target_link_libraries(unit_tests PRIVATE bank Catch2::Catch2WithMain)
target_include_directories(unit_tests PRIVATE ${INCLUDE_DIR})