#include <string>
#include <fstream>
#include <iostream>

int main(void) {

    // Open the file input file
    std::fstream inputFile;
    inputFile.open("Input.txt");

    // Prepare variables to keep track of the lines in the file
    const size_t N_LINES = 1000;
    int numbers[N_LINES];
    
    std::string line;
    // The first N_LINES from the file and write them to the list
    for (size_t i=0; i<N_LINES; i++) {
        std::getline(inputFile, line);
        size_t posFirst = line.find_first_of("123456789");
        size_t posLast = line.find_last_of("123456789");

        // Concat the first and last digits together
        std::string digits = std::string(1, line[posFirst]) + line[posLast];

        // Then cast them to a number and write it to the output array
        numbers[i] = std::stoi(digits);

        std::cout << line << " - " << digits << std::endl;
    }

    // Iterate over the lines and sum them up to get the result
    int result = 0;
    for (size_t i=0; i<N_LINES; i++){
        result += numbers[i];
    }

    std::cout << "Final sum is: " << result;

    return 0;
}
