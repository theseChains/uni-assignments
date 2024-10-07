cmake_minimum_required(VERSION 3.20)

project(SystemsProgrammingLab1 VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(SOURCES
    src/main.cpp
    src/TableManager.h
    src/TableManager.cpp
    src/ApplicationWindow.cpp
    src/ApplicationWindow.h
    src/ApplicationUi.ui
)

add_executable(app.out
    ${SOURCES}
)

target_link_libraries(app.out PRIVATE Qt5::Core Qt5::Widgets)
