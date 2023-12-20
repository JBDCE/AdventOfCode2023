#include "Helpers.h"

#include <vector>
#include <iostream>

#include "Game.h"
#include "Draw.h"

int task1(std::vector<std::string> lines) {
    std::vector<Game> games;
    for (std::string line : lines) {
        games.push_back(Game(line));
    }

    int result = 0;
    for (Game game : games) {
        if (game.is_valid(12, 13, 14)) {
            result += game.get_id();
        }
    }
    return result;
}

int task2(std::vector<std::string> lines) {
    std::vector<Game> games;
    for (std::string line : lines) {
        games.push_back(Game(line));
    }

    int result = 0;
    for (Game game : games) {
        Draw mvp = game.get_mvp();
        int power = mvp.get_red() * mvp.get_green() * mvp.get_blue();
        result += power;
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc<2) {  // Exit on invalid input
        std::cout << "Usage: main.exe <Inputfile>" << std::endl;
        return -1;
    }
    // Open input file using the helper
    std::vector<std::string> lines = readFile(argv[1]);

    int result_1 = task1(lines);
    int result_2 = task2(lines);

    std::cout << "Task1 Result: " << result_1 << std::endl;
    std::cout << "Task2 Result: " << result_2 << std::endl;

    return 0;
}
