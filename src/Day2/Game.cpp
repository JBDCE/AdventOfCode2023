#include <iostream>
#include <string>
#include <vector>
#include <regex>

#include "Draw.h"

using std::vector;
using std::string;
using std::regex;

class Game
{
private:
    size_t id_;
    vector<Draw> draws;

public:
    Game(string input_line);
};

Game::Game(string input_line)
{
    string line = input_line;
    // Find the id of the game
    regex idPattern("\\d+(?=:)");
    std::smatch idmatch;
    if (std::regex_search(line, idmatch, idPattern)){
        id_ = std::stoi(idmatch.str());
    }

    // Cut away the game text to make the regex for the next step easier
    line = line.substr(line.find(":") + 1); // +1 to also remove the space character
    // Seperate the games into a list
    std::cout << line << std::endl;

}
