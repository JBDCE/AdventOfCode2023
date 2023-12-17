#include "Draw.h"

Draw::Draw(int red, int green, int blue)
{
    red_ = red;
    green_ = green;
    blue_ = blue;
}

int Draw::get_red() const {
    return red_;
}

int Draw::get_green() const {
    return green_;
}

int Draw::get_blue() const {
    return blue_;
}