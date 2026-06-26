#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({900, 600}), "Bouncy Ball");
    sf::CircleShape ball(100);
    ball.setPosition({350, 200});
    ball.setFillColor(sf::Color::White);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear();
        window.draw(ball);
        window.display();
    }
    return 0;
}
