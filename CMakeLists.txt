cmake_minimum_required(VERSION 3.28.3)
project(pdfviewer)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 COMPONENTS Widgets Gui REQUIRED)
set(POPPLER_INCLUDE_DIR "/usr/include/poppler/qt6")
set(POPPLER_LIB "/usr/lib/x86_64-linux-gnu/libpoppler-qt6.so")

set(CMAKE_AUTOMOC ON)


add_executable(pdfviewer
    main.cpp
    ./src/mainwindow/mainwindow.hpp
    ./src/mainwindow/mainwindow.cpp
    ./src/viewerwidget/viewwidget.hpp
    ./src/viewerwidget/viewwidget.cpp

)

if(NOT EXISTS ${POPPLER_LIBRARY})
    find_library(POPPLER_LIBRARY NAMES poppler-cpp)
    find_path(POPPLER_INCLUDE_DIR poppler/cpp/poppler-document.h)
endif()

target_include_directories(pdfviewer PRIVATE ${POPPLER_INCLUDE_DIR})
target_link_libraries(pdfviewer PRIVATE ${POPPLER_LIB})
target_link_libraries(pdfviewer PRIVATE Qt::Widgets)

