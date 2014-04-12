#ifndef DOTTEDPATH_H
#define DOTTEDPATH_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Path.h"
#include "TiledImage.h"

#include <deque>

class DottedPath : public sf::Drawable
{
public:
	DottedPath();
	void render();
		
	TiledTexture* dotTexture;
	Path* path;
protected:
	void draw(sf::RenderTarget&, sf::RenderStates) const;
	
	sf::RenderTexture renderTexture;
	float dotInc;
private:
	std::deque<sf::Sprite> sprites;
};

#endif //DOTTEDPATH_H