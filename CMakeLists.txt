cmake_minimum_required(VERSION 3.28)
project(TwoGisHomeTask)

set(CMAKE_CXX_STANDARD 17)

include_directories("/usr/local/Cellar/cli11/2.4.2/include")
include_directories("/usr/local/Cellar/googletest/1.14.0/include")

add_executable(TwoGisHomeTask src/main.cpp
        src/checksum.cpp
        src/checksum.hpp
        src/word_counter.cpp
        src/word_counter.hpp
)

add_executable(TwoGisHomeTaskTests
        test/test_main.cpp
        src/checksum.cpp
        src/checksum.hpp
        test/checksum_tests.cpp
        src/word_counter.cpp
        src/word_counter.hpp
        test/word_counter_tests.cpp
)


target_link_libraries(TwoGisHomeTaskTests
        /usr/local/Cellar/googletest/1.14.0/lib/libgtest.a
        /usr/local/Cellar/googletest/1.14.0/lib/libgtest_main.a)
