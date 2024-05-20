#include "word_counter.hpp"
#include <cctype>
#include <fstream>
#include <string>


size_t count_word(std::istream &input, const std::string &word) {
    size_t count = 0;
    bool equal = true;
    size_t index = 0;

    char ch;
    while (input.get(ch))
        if (std::isspace(static_cast<unsigned char>(ch))) {
            if (equal && index == word.length()) {
                count++;
            }
            equal = true;
            index = 0;
        } else {
            if (index < word.length() && word[index] == ch) {
                index++;
            } else {
                equal = false;
            }
        }


    if (equal && index == word.length()) {
        count++;
    }
    return count;
}
