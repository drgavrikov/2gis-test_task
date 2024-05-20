find_package(CLI11 REQUIRED)
find_package(GTest REQUIRED)

add_executable(TwoGisHomeTask main.cpp
        checksum.cpp
        checksum.hpp
        word_counter.cpp
        word_counter.hpp
)

target_link_libraries(TwoGisHomeTask CLI11::CLI11)
