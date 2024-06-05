cmake_minimum_required(VERSION 3.5)

project(QtExtDemo VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(QtExtIncludeDir
        ${CMAKE_CURRENT_LIST_DIR}/sdk/include
)
set(QtExtLinkDir "${CMAKE_CURRENT_LIST_DIR}/sdk")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(QtExtLibs hcored hguid hwidgetd hvisiond)
else()
    set(QtExtLibs hcore hgui hwidget hvision)
endif()

set(BUILD_EXT_DEMO OFF)

if(PROJECT_IS_TOP_LEVEL OR BUILD_EXT_DEMO)

    find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
    find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

    qt_add_executable(QtExtDemo
        MANUAL_FINALIZATION
        main.cpp
        mainwindow.cpp
        mainwindow.h
    )

    target_link_directories(QtExtDemo PRIVATE ${QtExtLinkDir})
    target_link_libraries(QtExtDemo PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        ${QtExtLibs})
    target_include_directories(QtExtDemo PRIVATE ${QtExtIncludeDir})

    set_target_properties(QtExtDemo PROPERTIES
        ${BUNDLE_ID_OPTION}
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
    )

    include(GNUInstallDirs)
    install(TARGETS QtExtDemo
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )

    qt_finalize_executable(QtExtDemo)

endif()
