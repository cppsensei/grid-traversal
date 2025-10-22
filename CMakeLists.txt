cmake_minimum_required(VERSION 3.10)
project(GridTraversal)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

if(BUILD_TESTING)
    enable_testing()
endif()

include(GNUInstallDirs)

add_subdirectory(modules/gridTraversal)
add_subdirectory(modules/main)
