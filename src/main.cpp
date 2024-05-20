#include <iostream>
#include <string>
#include "CLI/CLI.hpp"

#include "checksum.hpp"
#include "word_counter.hpp"


int main(int argc, char *argv[]) {

    CLI::App app{"Program to count words and calculate checksum"};

    std::string filename;
    std::string mode;
    std::string word;

    app.add_option("-f,--file", filename, "Input file name")->required();
    auto modeOpt = app.add_option("-m,--mode", mode, "Mode: words or checksum")->required();
    auto wordOpt = app.add_option("-v,--value", word, "Word to count occurrences of");

    CLI11_PARSE(app, argc, argv);

    if (mode == "words" && !word.empty()) {
        int count = countWord(filename, word);
        std::cout << "Counting occurrences of word: " << word << " in file '" << filename << "' is " << count << std::endl;
    } else if (mode == "checksum") {
        uint32_t checksum = calculateChecksum(filename);
        std::cout << "The 32-bit checksum of the file '" << filename << "' is " << checksum << "." << std::endl;
    } else {
        std::cerr << "Invalid mode or missing value for mode 'words'" << std::endl;
        std::cout << app.help() << std::endl;
        return 1;
    }

    return 0;
}
