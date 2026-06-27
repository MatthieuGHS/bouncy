#include "ball.hpp"
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({900, 600}), "Bouncy Ball");
    sf::Clock clock;
    Ball ball(30.f, {400.f, 300.f}, {60.f, 0.f});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        sf::Time dt = clock.restart();
        float seconds = dt.asSeconds();

        window.clear();
        ball.draw(window);
        ball.update(ball.getVelocity(), seconds);
        window.display();
    }
    return 0;
}
