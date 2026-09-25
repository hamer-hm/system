cmake_minimum_required(VERSION 3.19)
project(system LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Sql)

qt_standard_project_setup()

set(CMAKE_AUTORCC on)
set(CMAKE_AUTOUIC on)
set(CMAKE_AUTOMOC on)
qt_add_executable(system
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    res.qrc
    dbmanager.h dbmanager.cpp
    stockwidget.h stockwidget.cpp stockwidget.ui
    stockindialog.h stockindialog.cpp stockindialog.ui
    saleorderwidget.h saleorderwidget.cpp saleorderwidget.ui
    specdelegate.h specdelegate.cpp
    numericdelegate.h numericdelegate.cpp
    orderquerywidget.h orderquerywidget.cpp orderquerywidget.ui

)
target_include_directories(system PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(system
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Sql
)

include(GNUInstallDirs)

install(TARGETS system
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET system
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
