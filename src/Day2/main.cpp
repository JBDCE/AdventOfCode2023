#include "Helpers.h"

#include <vector>
#include <iostream>

#include "Game.h"

int main(int argc, char* argv[]) {
    if (argc<2) {  // Exit on invalid input
        std::cout << "Usage: main.exe <Inputfile>" << std::endl;
        return -1;
    }
    // Open input file using the helper
    std::vector<std::string> lines = readFile(argv[1]);

    std::vector<Game> games;
    for (std::string line : lines) {
        games.push_back(Game(line));
    }

    return 0;
}