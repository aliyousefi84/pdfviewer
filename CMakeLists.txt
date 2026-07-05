cmake_minimum_required(VERSION 3.28.3)
project(pdfviewer)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 COMPONENTS Widgets Gui REQUIRED)
find_package(Poppler REQUIRED)
set(CMAKE_AUTOMOC ON)


add_executable(file_explorer
    main.cpp
    ./mainwindow/mainwindow.cpp
    ./mainwindow/mainwindow.hpp
    ./viewerwidget/viewerwidget.cpp
    ./viewerwidget/viewerwidget.hpp

)

target_link_libraries(pdfviewer PRIVATE Qt::Widgets)
target_link_libraries(pdfviewer PRIVATE Poppler::cpp)