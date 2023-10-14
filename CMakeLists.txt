cmake_minimum_required(VERSION 3.10)
project(MLP_Architecture VERSION 0.5)
file(GLOB HEADERS "include/*.hpp")
file(GLOB SOURCES "src/*.cpp")
add_executable(MLP_Architecture ${SOURCES} ${HEADERS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)