find_package(CLI11 REQUIRED)
find_package(GTest REQUIRED)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

add_executable(TwoGisHomeTaskTests
        test_main.cpp
        ${SRC_DIR}/checksum.hpp
        ${SRC_DIR}/checksum.cpp
        ${SRC_DIR}/word_counter.hpp
        ${SRC_DIR}/word_counter.cpp
        checksum_tests.cpp
        word_counter_tests.cpp
)

target_include_directories(TwoGisHomeTaskTests PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(TwoGisHomeTaskTests GTest::GTest GTest::Main)
