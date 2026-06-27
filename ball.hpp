#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
  public:
    Ball(float radius, sf::Vector2f pos, sf::Vector2f v);

    void update(float);
    void draw(sf::RenderWindow &);
    void check(sf::RenderWindow &);

  private:
    sf::CircleShape shape;
    float radius;
    sf::Vector2f pos;
    sf::Vector2f v;
    sf::Vector2f a;
};
