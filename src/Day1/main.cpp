#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "Helpers.h"

int task1(std::vector<std::string> lines) {
    size_t n_lines = lines.size();
    int numbers[n_lines];

    for (size_t i=0; i<n_lines; i++) {
        // Search for the first instance of digits
        std::string line = lines[i];
        size_t posFirst = line.find_first_of("123456789");
        size_t posLast = line.find_last_of("123456789");

        // Concat the first and last digits together
        std::string digits = std::string(1, line[posFirst]) + line[posLast];

        // Then cast them to a number and write it to the output array
        numbers[i] = std::stoi(digits);

        std::cout << i << ": " << line << " - " << digits << std::endl;
    }

    // Iterate over the lines and sum them up to get the result
    int result = 0;
    for (size_t i=0; i<n_lines; i++){
        result += numbers[i];
    }
    return result;
}

int task2(std::vector<std::string> lines) {

    std::vector<std::string> convertedLines;
    for (const std::string line : lines) {
        convertedLines.push_back(textToNumber(line));
    }

    return task1(convertedLines);
}


int main(void) {
    // Open input file using the helper
    std::vector<std::string> lines = readFile("Input.txt");

    // Calculate the tasks based on the input file
    int result1 = task1(lines);
    int result2 = task2(lines);

    std::cout << "Task 1 Sum: " << result1 << std::endl;
    std::cout << "Task 2 Sum: " << result2 << std::endl;

    return 0;
}
