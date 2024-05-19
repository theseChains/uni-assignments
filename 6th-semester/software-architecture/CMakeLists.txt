cmake_minimum_required(VERSION 3.20)

project(PolyclinicApp VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

find_package(Qt5 COMPONENTS Core Network Widgets Sql REQUIRED)

include_directories(src/client)
include_directories(src/server)
include_directories(src/common)
include_directories(src/common/data)

add_subdirectory(src/client)
add_subdirectory(src/server)
add_subdirectory(src/common)
