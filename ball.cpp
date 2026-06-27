#include "ball.hpp"

Ball::Ball(float radius, sf::Vector2f pos, sf::Vector2f v)
    : radius(radius), pos(pos), v(v)
{
    shape.setRadius(radius);
    shape.setPosition(pos);
    shape.setFillColor(sf::Color::White);
}

void Ball::draw(sf::RenderWindow &window) { window.draw(shape); }

void Ball::update(sf::Vector2f v, float dt)
{
    this->pos += v * dt;
    this->shape.setPosition(this->pos);
}

sf::Vector2f Ball::getVelocity() { return v; }
