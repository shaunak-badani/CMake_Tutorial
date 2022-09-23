cmake_minimum_required(VERSION 3.19.1)

project(rens)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(Adder)
target_link_libraries(${PROJECT_NAME} adder)

add_subdirectory(Subtracter)
target_link_libraries(${PROJECT_NAME} subtracter)
