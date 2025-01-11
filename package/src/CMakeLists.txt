cmake_minimum_required(VERSION 3.28)
project(_pybind_sandbox)

#find_package(Python COMPONENTS Interpreter Development REQUIRED)
set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 20)

pybind11_add_module(_pybind_sandbox main.cpp)

install(TARGETS _pybind_sandbox DESTINATION .)
