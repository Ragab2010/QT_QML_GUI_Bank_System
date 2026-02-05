# Bank library (compiled with PIC for shared library compatibility)
add_library(bank STATIC 
    account.cpp 
    bank.cpp 
    json_persistence.cpp
)
target_include_directories(bank PUBLIC ${INCLUDE_DIR})
target_link_libraries(bank PUBLIC 
    nlohmann_json::nlohmann_json
)
set_target_properties(bank PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)

# Bank bridge library (must be shared for Qt MOC)
add_library(bank_bridge SHARED bank_bridge.cpp)
target_include_directories(bank_bridge PUBLIC ${INCLUDE_DIR})
target_link_libraries(bank_bridge PUBLIC 
    bank
    Qt6::Core
)
set_target_properties(bank_bridge PROPERTIES
    AUTOMOC ON
)