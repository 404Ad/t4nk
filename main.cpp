#include <iostream>
#include "game.h"

using namespace std;

class MoveParameters
{
protected:
    int x,y,speed;
    enum Direction
    {
        Up,
        Right,
        Down,
        Left
    };
    Direction dir;
};

class Bullet : public MoveParameters
{
public:
    Bullet(int xpos, int ypos, Direction direction, int bulletSpeed = 4)
    {
        x = xpos;
        y = ypos;
        dir = direction;
        speed = bulletSpeed;
    }

};

int main()
{
    Game game;
    game.run();

    return 0;
}

