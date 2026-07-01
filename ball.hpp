#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
  public:
    Ball(float radius, sf::Vector2f pos, sf::Vector2f v);

    void update(float);
    void draw(sf::RenderWindow &);
    void check(sf::RenderWindow &);
    void checkCollision(sf::Vector2f, float);

    sf::Vector2f getPos();
    float getRad();

  private:
    float radius;
    sf::CircleShape shape;
    sf::Vector2f pos;
    sf::Vector2f v;
    sf::Vector2f a;
};
