# Enable testing

# Include Google Test using FetchContent

message("Fetching Google Test")

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/master.zip # URL to Google Test repository
)
FetchContent_MakeAvailable(googletest)

# Add headers, if any (replace "header.h" with your actual header files)
message("Current Source Dir:" ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(../include)
set(HEADERS
    ../include/dummy.hpp
)
# Add the test executable
add_executable(unit_tests ${HEADERS} example_test.cpp)

# Link the test executable with the main library and Google Test
target_link_libraries(unit_tests PRIVATE  gtest_main)

# Add the test to CTest
include(CTest)
include(GoogleTest)
gtest_discover_tests(unit_tests)
