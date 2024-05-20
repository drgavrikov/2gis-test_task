#include <fstream>
#include <stdexcept>
#include <cstdint>


uint32_t calculateChecksum(const std::string &filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Cannot open file");
    }

    uint32_t checksum = 0;
    uint32_t word;

    while (file.read(reinterpret_cast<char *>(&word), sizeof(word))) {
        checksum += word;
    }

    char remainingBytes[4] = {0};
    file.read(remainingBytes, 4);
    if (file.gcount() > 0) {
        word = *reinterpret_cast<uint32_t *>(remainingBytes);
        checksum += word;
    }

    file.close();
    return checksum;
}
