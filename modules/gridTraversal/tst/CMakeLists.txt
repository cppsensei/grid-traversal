# GoogleTest
include(FetchContent)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(GridImplTest ${PROJECT_SOURCE_DIR}/GridImplTest.cpp)
target_link_libraries(GridImplTest PRIVATE gridtraversal GTest::gtest_main)
target_include_directories(GridImplTest PRIVATE ../headers)

include(GoogleTest)
gtest_discover_tests(GridImplTest)
