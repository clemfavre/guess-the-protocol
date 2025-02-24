cmake_minimum_required(VERSION 3.10)
project(MyParser)  # Name your project

set(CMAKE_CXX_STANDARD 17)  # Set C++ standard

add_executable(parser code/main.cpp code/parser.cpp)  # Add your source file

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# Add your source files
set(SOURCES code/parser.cpp)

# Add your test executable
add_executable(my_tests tests/tests.cpp)
target_link_libraries(my_tests gtest_main)

# Add the test
enable_testing()
add_test(NAME my_tests COMMAND my_tests)