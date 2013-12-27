#ifndef ACTOR_H
#define ACTOR_H

#include <SFML/Graphics/Drawable.hpp>

class Actor
{
public:
	sf::Sprite sprite;
	sf::IntRect mask;
	
	Actor() {}
private:
	virtual ~Actor() {}
};

#endif //ACTOR_H
