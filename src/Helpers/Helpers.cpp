#include "Helpers.h"

std::vector<std::string> readFile(std::string filepath) {
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

std::string textToNumber(std::string inputString) {
    std::string outputString = "";
    for (size_t i = 0; i < inputString.length(); i++) {
        // If we find a digit at this position
        if (inputString.find_first_of("123456789", i) == i) {
            outputString += inputString[i];

        // Otherwise handle the words if possible
        } else if (inputString.find("one", i) == i) {
            outputString += "1";
        } else if (inputString.find("two", i) == i) {
            outputString += "2";
        } else if (inputString.find("three", i) == i) {
            outputString += "3";
        } else if (inputString.find("four", i) == i) {
            outputString += "4";
        } else if (inputString.find("five", i) == i) {
            outputString += "5";
        } else if (inputString.find("six", i) == i) {
            outputString += "6";
        } else if (inputString.find("seven", i) == i) {
            outputString += "7";
        } else if (inputString.find("eight", i) == i) {
            outputString += "8";
        } else if (inputString.find("nine", i) == i) {
            outputString += "9";
        }
    }
    return outputString;
}
