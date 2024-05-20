#include <fstream>
#include <string>

int countWord(const std::string &filepath, std::string word) {
    std::ifstream file(filepath);
    if (!file) {
        throw std::runtime_error("Cannot open file");
    }

    int count = 0;

    char c;
    bool isEqual = true;
    int index = 0;
    while (file.get(c)) {
        if (ispunct(c) || isspace(c)) {
            if (isEqual && index == word.length()) {
                count++;
            }
            isEqual = true;
            index = 0;
        } else {
            if (index < word.length() && word[index] == c) {
                index++;
            } else {
                isEqual = false;
            }
        }
    }

    if (isEqual && index == word.length()) {
        count++;
    }

    file.close();
    return count;
}
