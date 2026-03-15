cmake_minimum_required(VERSION 3.20)
project(unit-conversion VERSION 1.0)

add_executable(unit-conversion src/main.cpp)
target_include_directories(unit-conversion PRIVATE include)
set_target_properties(unit-conversion PROPERTIES
  CXX_STANDARD 23
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS OFF
)