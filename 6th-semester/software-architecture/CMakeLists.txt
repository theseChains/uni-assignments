cmake_minimum_required(VERSION 3.20)

project(PolyclinicApp VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Widgets Sql REQUIRED)

include_directories(src)

QT5_ADD_RESOURCES(RESOURCE_FILES
    res/darkstyle.qrc
)

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

set(CONFIG_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/config)
set(CONFIG_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/config)
file(COPY ${CONFIG_SOURCE_DIR}/config.ini DESTINATION ${CONFIG_BUILD_DIR})

add_executable(PolyclinicApp
    ${RESOURCE_FILES}
    ${VIEW_SOURCES}
    ${CONTROLLER_SOURCES}
    ${MODEL_SOURCES}
    src/main.cpp
)

target_link_libraries(PolyclinicApp PRIVATE Qt5::Core Qt5::Widgets Qt5::Sql)
