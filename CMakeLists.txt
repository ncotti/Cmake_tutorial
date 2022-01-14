cmake_minimum_required(VERSION 3.10)

project(Tutorial)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Math)

add_executable(tuto tutorial.cpp "${PROJECT_SOURCE_DIR}/test.txt")

target_link_libraries(tuto PUBLIC MathFunctions)

add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/test.txt
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND echo "hola" >> test.txt
    COMMENT "Creating test.txt" )

target_include_directories(tuto PUBLIC ${PROJECT_BINARY_DIR} )


install(TARGETS tuto DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/tutorial_config.h"
    DESTINATION include
    )


