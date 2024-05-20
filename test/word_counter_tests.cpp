#include "gtest/gtest.h"
#include "../src/word_counter.hpp"
#include <fstream>
#include <string>

// Тест на корректность подсчета слов
TEST(CountWordTest, CountsCorrectNumberOfWords) {
    std::ofstream tempFile("test_word_data.txt");
    std::string word = "test";

    tempFile << "This is a test. This test is only a test. A test again, test!";
    tempFile.close();

    int expectedCount = 5;

    EXPECT_EQ(countWord("test_word_data.txt", word), expectedCount);
    std::remove("test_word_data.txt");
}

// Тест на обработку пустого файла
TEST(CountWordTest, HandlesEmptyFile) {
    std::ofstream tempFile("empty_file.txt");

    EXPECT_EQ(countWord("empty_file.txt", "word"), 0);
    std::remove("empty_file.txt");
}

// Тест на обработку отсутствия искомого слова
TEST(CountWordTest, HandlesAbsentWord) {
    std::ofstream tempFile("test_file.txt");
    tempFile << "This is a test file with some text";

    EXPECT_EQ(countWord("test_file.txt", "absent"), 0);
    std::remove("test_file.txt");
}

// Тест на обработку неправильного пути к файлу
TEST(CountWordTest, HandlesInvalidFilePath) {
    EXPECT_THROW(countWord("invalid_file_path.txt", "word"), std::runtime_error);
}
