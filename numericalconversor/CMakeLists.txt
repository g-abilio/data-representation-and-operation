cmake_minimum_required(VERSION 3.28.3)

project(numerical_conversor)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(methods_)

add_executable(${PROJECT_NAME} numericalconversor.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE methods_)

target_link_directories(${PROJECT_NAME} PRIVATE methods_)

target_link_libraries(${PROJECT_NAME} methods)