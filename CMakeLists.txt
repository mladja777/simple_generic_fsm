cmake_minimum_required(VERSION 3.16)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bins)

set(TESTS_FOLDER "tests")

project(fsm
        VERSION 1.0
        LANGUAGES CXX)

include_directories(".")

add_executable(fsm_test "${TESTS_FOLDER}/Tests.cpp")

