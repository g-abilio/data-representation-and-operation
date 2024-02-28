cmake_minimum_required(VERSION 3.28.3)

project(real_number VERSION 1.0)

configure_file(real_numberconfig.h.in real_numberconfig.h)

set(CXX_STANDARD 11)
set(CXX_STANDARD_REQUIRED True)

add_subdirectory(methods_)

add_executable(real_number realnumber.cpp)

target_include_directories(real_number PUBLIC ${PROJECT_BINARY_DIR})

target_include_directories(real_number PRIVATE methods_)

target_link_directories(real_number PRIVATE methods_)

target_link_libraries(real_number methods)