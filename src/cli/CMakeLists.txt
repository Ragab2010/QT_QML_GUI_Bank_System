
add_library(${CLI_NAME} STATIC cli.cpp)
target_include_directories(${CLI_NAME} PUBLIC ${INCLUDE_DIR})
target_link_libraries(${CLI_NAME} PUBLIC bank)
