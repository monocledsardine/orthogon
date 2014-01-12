#include "DottedPath.h"
#include <SFML/Graphics/Transform.hpp>

DottedPath::DottedPath() : dotInc(15.0f)
{
	renderTexture.create(500, 500);	
}


void DottedPath::render()
{
	renderTexture.clear(sf::Color(0,0,0,0));
	
	/*sf::RenderStates states;
	states.texture = dotTexture;
	
	sf::Vertex vertices[] = 
	{
		sf::Vertex(sf::Vector2f(0.0f, 0.0f)),
		sf::Vertex(sf::Vector2f(0.0f, dotTexture->getSize().y)),
		sf::Vertex(sf::Vector2f(dotTexture->getSize().x, dotTexture->getSize().y)),
		sf::Vertex(sf::Vector2f(dotTexture->getSize().x, 0.0f))
	};*/
	
	sprite.setTexture(*dotTexture);
	
	float i;
	float len = path->length();
	while (i < len)
	{
		sprite.setPosition(path->pos(i));
		renderTexture.draw(sprite);
		i += dotInc;
	}
	
	renderTexture.display();	
	sprite = sf::Sprite(renderTexture.getTexture());	
}

void DottedPath::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite);
}