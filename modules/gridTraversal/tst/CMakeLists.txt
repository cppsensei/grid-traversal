# GoogleTest
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(GridTest src/GridTest.cpp)
target_link_libraries(GridTest PRIVATE gridtraversal GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(GridTest)
