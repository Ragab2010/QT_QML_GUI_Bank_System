cmake_minimum_required(VERSION 3.16)
project(bank_system VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(nlohmann_json 3.2.0 REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

option(BUILD_TESTS "Build unit tests" OFF)

if(BUILD_TESTS)
    include(FetchContent)

    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.4.0
    )

    FetchContent_MakeAvailable(Catch2)
endif()

set(CLI_NAME cli)
set(EXECUTABLE_NAME bank_system)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)
add_subdirectory(app)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
