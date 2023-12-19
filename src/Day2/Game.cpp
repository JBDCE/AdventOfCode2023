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
    bool Game::is_valid(int maxRed, int maxGreen, int maxBlue);
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

    regex drawPattern("\\d.+?(?:;|$)");
    std::sregex_iterator iterator(line.begin(), line.end(), drawPattern);
    std::sregex_iterator end;

    // Loop over matches
    while (iterator != end) {
        std::smatch match = *iterator;
        string match_string = match.str();
        regex bluePattern("\\d+ blue");
        regex redPattern("\\d+ red");
        regex greenPattern("\\d+ green");

        int blue = 0;
        int red = 0;
        int green = 0;

        std::smatch colorMatch;
        if (std::regex_search(match_string, colorMatch, bluePattern)){
            string n_string = colorMatch.str();
            blue = std::stoi(n_string.substr(0, n_string.length()-5));
        }
        if (std::regex_search(match_string, colorMatch, redPattern)){
            string n_string = colorMatch.str();
            red = std::stoi(n_string.substr(0, n_string.length()-4));
        }
        if (std::regex_search(match_string, colorMatch, greenPattern)){
            string n_string = colorMatch.str();
            green = std::stoi(n_string.substr(0, n_string.length()-6));
        }

        std::cout << "Match: " << match.str() << std::endl << "Blue: " << blue << " Red: " << red << " Green: " << green << std::endl;
        draws.push_back(Draw(red, green, blue));

        ++iterator;
    }

}

bool Game::is_valid(int maxRed, int maxGreen, int maxBlue) {
    for (Draw draw : this->draws) {
        if (draw.get_red() > maxRed) return false;
        if (draw.get_green() > maxGreen) return false;
        if (draw.get_blue() > maxBlue) return false;
    }
    return true;
}
