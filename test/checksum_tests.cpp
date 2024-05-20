#include <gtest/gtest.h>
#include <string>

#include "checksum.hpp"


TEST(ChecksumTest, EmptyString) {
    std::istringstream empty("");
    ASSERT_EQ(0u, checksum(empty));
}

TEST(ChecksumTest, SingleCharacterString) {
    std::istringstream single("A");
    ASSERT_EQ(65u, checksum(single));
}

TEST(ChecksumTest, MultipleCharacterString) {
    std::istringstream input("Hello, World!");
    ASSERT_EQ(670630983, checksum(input));
}
