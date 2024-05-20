#include "checksum.hpp"
#include <cstdint>
#include <fstream>


std::uint32_t checksum(std::istream& input) {
    std::uint32_t checksum = 0;
    std::uint32_t shift = 0;

    auto process_char = [&checksum, &shift](unsigned char value) {
        auto word = static_cast<std::uint32_t>(value);
        checksum += (word << shift);
        shift += 8;
        if (shift == 32) {
            shift = 0;
        }
    };
    std::for_each(std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>(), process_char);

    return checksum;
}
