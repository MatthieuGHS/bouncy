#include "ball.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode({900, 600}), "Bouncy Ball");
    sf::Clock clock;
    std::vector<Ball> balls;
    // balls.emplace_back(70.f, sf::Vector2f{400.f, 300.f}, sf::Vector2f{200.f,
    // 200.f});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            if (const auto *mouseButtonPressed =
                    event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouseButtonPressed->button == sf::Mouse::Button::Left)
                {
                    balls.emplace_back(
                        10.f, sf::Vector2f{mouseButtonPressed->position},
                        sf::Vector2f{200.f, 200.f});
                }
            }
        }
        sf::Time dt = clock.restart();
        float seconds = dt.asSeconds();
        window.clear();
        for (Ball &ball : balls)
        {
            ball.update(seconds);
            ball.check(window);
            for (Ball &oball : balls)
            {
                if (&oball != &ball)
                {
                    ball.checkCollision(oball.getPos(), oball.getRad());
                }
            }
            ball.draw(window);
        }
        window.display();
    }
    return 0;
}
