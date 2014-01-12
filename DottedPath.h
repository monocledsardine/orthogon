#ifndef DOTTEDPATH_H
#define DOTTEDPATH_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Path.h"

class DottedPath : public sf::Drawable
{
public:
	DottedPath();
	void render();
		
	sf::Texture* dotTexture;
	Path* path;
protected:
	void draw(sf::RenderTarget&, sf::RenderStates) const;
	
	sf::RenderTexture renderTexture;
	float dotInc;
private:
	sf::Sprite sprite;
};

#endif //DOTTEDPATH_H