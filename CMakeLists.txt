cmake_minimum_required(VERSION 3.10)
project(GridTraversal)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

# RPATH section
set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(CMAKE_INSTALL_RPATH "$ORIGIN")

if (WIN32)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

if(BUILD_TESTING)
    enable_testing()
endif()

add_subdirectory(modules/gridTraversal)
add_subdirectory(modules/main)
