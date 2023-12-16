#include "Helpers.h"

std::vector<std::string> read_file(std::string filepath) {
    // Open the file input file
    std::fstream inputFile;
    inputFile.open(filepath);

    // Using a vector like this ensures the file is only read once
    std::vector<std::string> line_vect;
    std::string line;
    while (std::getline(inputFile, line)) {
        line_vect.push_back(line);
    }

    return line_vect;
}
