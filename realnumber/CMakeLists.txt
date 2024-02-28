cmake_minimum_required(VERSION 3.28.3)

project(real_number VERSION 2.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(real_numberConfig.h.in real_numberConfig.h)

add_subdirectory(methods_)

add_executable(real_number realnumber.cpp)

target_include_directories(real_number PRIVATE methods_)

target_include_directories(real_number PUBLIC ${PROJECT_BINARY_DIR})

target_link_libraries(real_number methods)