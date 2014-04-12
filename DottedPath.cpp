#include "DottedPath.h"
#include <SFML/Graphics/Transform.hpp>

DottedPath::DottedPath() : dotInc(15.0f)
{
	renderTexture.create(500, 500);	
}


void DottedPath::render()
{
	//renderTexture.clear(sf::Color(0,0,0,0));
	
	/*sf::RenderStates states;
	states.texture = dotTexture;
	
	sf::Vertex vertices[] = 
	{
		sf::Vertex(sf::Vector2f(0.0f, 0.0f)),
		sf::Vertex(sf::Vector2f(0.0f, dotTexture->getSize().y)),
		sf::Vertex(sf::Vector2f(dotTexture->getSize().x, dotTexture->getSize().y)),
		sf::Vertex(sf::Vector2f(dotTexture->getSize().x, 0.0f))
	};*/
	
	float len = path->length();
	sprites.resize(len/dotInc + 1);
	
	float i;
	while (i*dotInc < len)
	{
		sprites.push_back(sf::Sprite());
		sprites[i].setTexture(*dotTexture);
		sprites[i].setPosition(path->pos(i*dotInc));
		++i;
	}
}

void DottedPath::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	std::deque<sf::Sprite>::const_iterator i;
	std::deque<sf::Sprite>::const_iterator end(sprites.end());
	for (i=sprites.begin(); i < end; ++i)
		target.draw(*i);
}