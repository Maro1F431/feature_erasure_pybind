cmake_minimum_required(VERSION 3.8.2)
project(PyleneToPython)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -fpermissive")

#put source files here except main.cc
set(SRC_MODULE
    "src/convert.cc"
    )

find_package(Pylene REQUIRED)
find_package(pybind11 REQUIRED)
pybind11_add_module(pylene MODULE ${SRC_MODULE})
target_link_libraries(pylene PRIVATE Pylene::Pylene)
