#include <gtest/gtest.h>
#include <string>

#include "word_counter.hpp"


TEST(CountWordTest, CountsCorrectNumberOfWords) {
    std::istringstream str("This is a test. This test is only a test. A test again, test!");
    std::string word = "test";

    int expected_count = 2;
    EXPECT_EQ(count_word(str, word), expected_count);
}

TEST(CountWordTest, HandlesEmptyString) {
    std::istringstream empty("");
    EXPECT_EQ(count_word(empty, "word"), 0);
}

TEST(CountWordTest, HandlesAbsentWord) {
    std::istringstream str("This is a test file with some text");
    EXPECT_EQ(count_word(str, "absent"), 0);
}

