#ifndef ACTOR_H
#define ACTOR_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Time.hpp>

class Actor
{
public:
	sf::Sprite sprite;
	sf::IntRect mask;
	void setPosition(float x, float y);
	void setPosition(const sf::Vector2f& vec);
	Actor() {}
	virtual ~Actor() {}
};

#endif //ACTOR_H
