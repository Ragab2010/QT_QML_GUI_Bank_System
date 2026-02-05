# Create executable with Qt support
set(SRCS main.cpp)
set(RESOURCES resources.qrc)

add_executable(${EXECUTABLE_NAME} ${SRCS} ${RESOURCES})

# Enable Qt auto-moc
set_target_properties(${EXECUTABLE_NAME} PROPERTIES
    AUTOMOC ON
    AUTORCC ON
)

# Link include directory to target
target_include_directories(${EXECUTABLE_NAME} PUBLIC ${INCLUDE_DIR})

# Link Qt6 libraries
target_link_libraries(${EXECUTABLE_NAME} PRIVATE 
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    bank_bridge
)