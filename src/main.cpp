#include <iostream>
#include <string>
#include <fstream>
#include <map>

#include "CLI/CLI.hpp"
#include "checksum.hpp"
#include "word_counter.hpp"


enum class Mode {
    Words,
    Checksum
};

const std::map<std::string, Mode> mode_map{
        {"words",    Mode::Words},
        {"checksum", Mode::Checksum}
};

int main(int argc, char *argv[]) {

    CLI::App app{"Program to count words and calculate checksum"};

    std::filesystem::path filename;
    Mode mode;
    std::string word;

    try {
        app.add_option("-f,--file", filename, "Input file name")
                ->required()
                ->check(CLI::ExistingFile);
        app.add_option("-m,--mode", mode, "Mode: words or checksum")
                ->required()
                ->transform(CLI::CheckedTransformer(mode_map, CLI::ignore_case));

        auto word_option = app.add_option("-v,--value", word, "Word to count occurrences of");
        app.callback([&] {
            if (mode == Mode::Words && !word_option->count()) {
                throw CLI::RequiredError(word_option->get_name());
            }
        });

        CLI11_PARSE(app, argc, argv)

        std::ifstream file(filename);
        if (mode == Mode::Checksum) {
            uint32_t result = checksum(file);
            std::cout << "The 32-bit checksum of the file '" << filename << "' is " << result << "." << std::endl;
        } else if (mode == Mode::Words) {
            size_t count = count_word(file, word);
            std::cout << "Counting occurrences of word: " << word << " in file '" << filename << "' is "
                      << count << std::endl;
        }
    } catch (const CLI::ParseError &e) {
        return app.exit(e);
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown error occurred." << std::endl;
        return 1;
    }

    return 0;
}
