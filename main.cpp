#include <iostream>

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

class Tank : public MoveParameters
{
public:
    Tank(int xpos, int ypos, int tankSpeed, Direction direction = Up)
    {
        x = xpos;
        y = ypos;
        dir = direction;
        speed = tankSpeed;
    }

    void setSpeed(int pixelsPerFrame)
    {
        speed = pixelsPerFrame;
    }

    void moveUp()
    {
        y -= speed; //for example 3 pixels per frame
    }

    void moveDown()
    {
        y += speed;
    }

    void moveLeft()
    {
        x -= speed;
    }

    void moveRight()
    {
        x += speed;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

