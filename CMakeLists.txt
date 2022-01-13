cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Math)

add_executable(Tutorial tutorial.cpp)

target_link_libraries(tuto PUBLIC MathFunctions)

configure_file(tutorial_config.h.in tutorial_config.h)

target_include_directories(tuto PUBLIC "${PROJECT_BINARY_DIR}")

install(TARGETS tuto DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/tutorial_config.h"
  DESTINATION include
  )


