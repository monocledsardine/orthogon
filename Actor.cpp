#include "Actor.hpp"

void Actor::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
	mask.left = static_cast<int>(x);
	mask.top = static_cast<int>(y);
}

void Actor::setPosition(const sf::Vector2f& vec)
{
	setPosition(vec.x, vec.y);
}