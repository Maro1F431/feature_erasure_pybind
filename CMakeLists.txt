cmake_minimum_required(VERSION 3.8.2)
project(PyleneToPython)

set(CMAKE_CXX_STANDARD 14) 
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -pedantic")

#put source files here except main.cc
set(SRC_MODULE
    "src/func.cc"
    )

#put test files here
set(SRC_TESTS
    "tests/test.cc"
    )
find_package(Pylene REQUIRED)
find_package(pybind11 REQUIRED)
pybind11_add_module(pylene MODULE src/main.cc)
target_link_libraries(pylene PRIVATE Pylene::Pylene)

# TESTS
# Check if GTest is installed
find_package(GTest REQUIRED)

# If it is, create a dedicated target "test"
include(GoogleTest)

add_executable(test)
target_sources(test PRIVATE
    ${SRC_TESTS}
    ${SRC_MODULE})

target_compile_options(test PRIVATE -Wall -Werror -Wextra)
target_link_libraries(test PRIVATE GTest::GTest gtest_main Pylene::Pylene)
add_custom_command(TARGET test POST_BUILD
COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/build/test
WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
COMMENT "Running tests...")
