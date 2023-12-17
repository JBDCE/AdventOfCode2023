#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

#include "Draw.h"

class Game
{
private:
    size_t id_;
    std::vector<Draw> draws;

public:
    Game(std::string input_line);
};

#endif