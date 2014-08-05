#include <SFML/Graphics.hpp>

class Game
{
public:
    Game()
    : window(sf::VideoMode(640, 480), "T4NK")
    , TIME_PER_FRAME(sf::seconds(1.f / 60.f)) {}
    void run();

private:
    void processEvents();
    void update(sf::Time);
    void render();

    sf::RenderWindow window;
    sf::Time const TIME_PER_FRAME;
};
