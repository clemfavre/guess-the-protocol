cmake_minimum_required(VERSION 3.10)
project(MyParser)  # Name your project

set(CMAKE_CXX_STANDARD 17)  # Set C++ standard

add_executable(parser parser.cpp)  # Add your source file

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)