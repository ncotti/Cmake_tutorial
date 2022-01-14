cmake_minimum_required(VERSION 3.10)

project(Tutorial)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Math)

add_executable(tuto tutorial.cpp)

target_link_libraries(tuto PUBLIC MathFunctions)

target_include_directories(tuto PUBLIC ${PROJECT_BINARY_DIR})

add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/test.txt
  COMMAND bash -c "echo hola")

install(TARGETS tuto DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/tutorial_config.h"
  DESTINATION include
  )


