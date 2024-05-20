#include "gtest/gtest.h"
#include "../src/checksum.hpp"
#include <fstream>
#include <string>

// Тест на корректность вычисления контрольной суммы
TEST(CalculateChecksumTest, ComputesCorrectChecksum) {
    std::ofstream tempFile("test_data.txt", std::ios::binary);
    uint32_t expectedChecksum = 0;

    // Записываем данные в файл и вычисляем ожидаемую контрольную сумму
    for (int i = 0; i < 100; ++i) {
        uint32_t data = i;
        tempFile.write(reinterpret_cast<char*>(&data), sizeof(data));
        expectedChecksum += data;
    }

    tempFile.close();

    EXPECT_EQ(calculateChecksum("test_data.txt"), expectedChecksum);
    std::remove("test_data.txt");
}

// Тест на обработку пустого файла
TEST(CalculateChecksumTest, HandlesEmptyFile) {
    std::ofstream tempFile("empty_file.txt");

    // Проверяем, что функция calculateChecksum возвращает контрольную сумму 0 для пустого файла
    EXPECT_EQ(calculateChecksum("empty_file.txt"), 0);
    std::remove("empty_file.txt");
}


TEST(CalculateChecksumTest, ThrowsExceptionForNonExistingFile) {
    std::string filename = "non_existing_file.dat";
    EXPECT_THROW(calculateChecksum(filename), std::runtime_error);
}
