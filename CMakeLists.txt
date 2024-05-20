cmake_minimum_required(VERSION 3.28)
project(TwoGisHomeTask)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wpedantic -Werror")

add_subdirectory(src)
add_subdirectory(test)
