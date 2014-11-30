project (qwebpa)
cmake_minimum_required(VERSION 2.8.11)

find_package(Qt5Core QUIET)
find_package(Qt5Gui QUIET)
find_package(Qt5Test QUIET)

set(QTCORE_LIBRARIES ${Qt5Core_LIBRARIES})
# if there is no QT_ROOT, try to deduce it from Qt QtCore include
if ("${QT_ROOT}" STREQUAL "")
    set(QT_ROOT ${QT_QTCORE_INCLUDE_DIR}/../..)
endif()
include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${Qt5Gui_INCLUDE_DIRS})
include_directories(${Qt5Test_INCLUDE_DIRS})

add_subdirectory(src)

enable_testing()
add_subdirectory(test)

# install(FILES DESTINATION ${CMAKE_ROOT}/Modules)
