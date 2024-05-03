cmake_minimum_required(VERSION 3.20)

project(PolyclinicApp VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(src)

set(VIEW_SOURCES
    src/View/ApplicationViewUi.ui
    src/View/ApplicationView.cpp
    src/View/ApplicationView.h
    src/View/ViewConstants.h
)

set(CONTROLLER_SOURCES
    src/Controller/ApplicationController.cpp
    src/Controller/ApplicationController.h
)

set(MODEL_SOURCES
    src/Model/ApplicationModel.cpp
    src/Model/ApplicationModel.h
)

add_executable(PolyclinicApp
    ${VIEW_SOURCES}
    ${CONTROLLER_SOURCES}
    ${MODEL_SOURCES}
    src/main.cpp)

target_link_libraries(PolyclinicApp PRIVATE Qt5::Widgets)
