cmake_minimum_required(VERSION 3.19.1)

project(rens VERSION 1.0)

configure_file(RENSConfig.h.in RENSConfig.h)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

# DOWNLOAD ALL THE SUBMODULES : 
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules!")
        endif()
    endif()
endif()

# CHECK ALL THE SUBMODULES
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The glfw submodules was not downloaded! GIT_SUBMODULE was turned off or failed.")
endif()


add_subdirectory(Adder)
target_link_directories(${PROJECT_NAME} 
    PRIVATE Adder)

add_subdirectory(Subtracter)
add_subdirectory(external/glfw)
target_link_directories(${PROJECT_NAME} 
    PRIVATE Subtracter
    PRIVATE external/glfw/src
)

target_include_directories(${PROJECT_NAME} 
    PUBLIC Adder 
    PUBLIC Subtracter
    PUBLIC external/glfw/include
)



target_link_libraries(${PROJECT_NAME} adder_lib subtracter_lib glfw)

