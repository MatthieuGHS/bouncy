#include "ball.hpp"
#include "constants.hpp"
#include <cmath>
#include <iostream>

Ball::Ball(float radius, sf::Vector2f pos, sf::Vector2f v)
    : radius(radius), pos(pos), v(v)
{
    shape.setRadius(radius);
    shape.setPosition(pos);
    shape.setFillColor(sf::Color::White);
}

sf::Vector2f Ball::getPos() { return this->pos; }

float Ball::getRad() { return this->radius; }

void Ball::update(float dt)
{
    this->v.y += config::G * dt;
    this->pos += v * dt;
    this->v *= std::pow(config::DRAG, dt);
    this->shape.setPosition(this->pos);
}

void Ball::draw(sf::RenderWindow &window) { window.draw(shape); }

void Ball::check(sf::RenderWindow &window)
{
    // check if ball is out of the window
    sf::Vector2u usize = window.getSize();
    sf::Vector2f size = sf::Vector2f(usize);

    if (pos.x + 2 * radius > size.x)
    {
        pos.x = size.x - 2 * radius;
        v.x = -v.x;
    }
    if (pos.x < 0)
    {
        pos.x = 0;
        v.x = -v.x;
    }
    if (pos.y + 2 * radius > size.y)
    {
        pos.y = size.y - 2 * radius;
        v.y = -v.y;
    }
    if (pos.y < 0)
    {
        pos.y = 0;
        v.y = -v.y;
    }
}

void Ball::resolveCollision(Ball &other)
{
    if (std::pow(this->pos.x - other.pos.x, 2) +
            std::pow(this->pos.y - other.pos.y, 2) <
        std::pow(this->radius + other.radius, 2))
    {
        std::cout << "Collision !";
    }
}
