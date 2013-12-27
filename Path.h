#ifndef PATH_H
#define PATH_H

#include <SFML/Graphics/VertexArray.hpp>
#include "Angle.h"

class Path
{
public
	Path();
	sf::Vector2f xy(float t);
private:
	sf::VertexArray points;
};

class PathBlock
{
public:	
	PathBlock();
	sf::Vector2f xy(float pos, Angle angle = 0);
};
#endif //PATH_H