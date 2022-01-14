add_library(MathFunctions math.cpp)

target_include_directories(MathFunctions
          PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
          )


install(TARGETS MathFunctions DESTINATION lib)
install(FILES math.h DESTINATION include)