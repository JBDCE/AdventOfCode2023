#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

#include "Draw.h"

class Game
{
private:
    int id_;
    std::vector<Draw> draws;

public:
    Game(std::string input_line);
    bool is_valid(int maxRed, int maxGreen, int maxBlue) const;
    int get_id() const;
    Draw get_mvp() const;
};

#endif
