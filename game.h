#include <SFML/Graphics.hpp>

class Tank : public sf::Sprite
{
public:
    Tank(int pos_x, int pos_y, int tankSpeed)
    {
        setPosition(pos_x, pos_y);
        speed = tankSpeed;
    }

    void setSpeed(int pixelsPerFrame)
    {
        speed = pixelsPerFrame;
    }

    int getSpeed() const
    {
        return speed;
    }

    sf::Vector2f getCenter() const
    {
        auto rect = getLocalBounds();
        return sf::Vector2f(rect.width / 2, rect.height / 2);
    }

private:
    int speed;
};


class Game
{
public:
    Game()
    : window(sf::VideoMode(640, 480), "T4NK")
    , TIME_PER_FRAME(sf::seconds(1.f / 60.f))
    , player(320, 200, 200)
    {
        playerTexture.loadFromFile("assets/tankBase.png");
        player.setTexture(playerTexture);
    }
    void run();

private:
    void processEvents();
    void updatePlayerPosition(sf::Time);
    void update(sf::Time);
    void render();

    sf::RenderWindow window;
    sf::Time const TIME_PER_FRAME;
    sf::Texture playerTexture;
    Tank player;
};
