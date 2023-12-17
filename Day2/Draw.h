#ifndef DRAW_H
#define DRAW_H

class Draw
{
private:
    int red_;
    int green_;
    int blue_;
public:
    Draw(int red, int green, int blue);
    int get_red() const;
    int get_green() const;
    int get_blue() const;
};

#endif