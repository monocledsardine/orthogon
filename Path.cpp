#include "Path.h"
#include <cmath>

const float SQRT2 = 1.41421356f;

//
//	PathBlock
//

PathBlock::PathBlock() : scaling(1.0f, 1.0f), rotation(0.0f), translation(0.0f, 0.0f)
{}

PathBlock* PathBlock::translate(float x, float y)
{
	translation.x += x;
	translation.y += y;
	
	resetTransform();
	
	return this;
}

PathBlock* PathBlock::rotate(const Angle& angle)
{
	rotation += angle;
	
	resetTransform();
	
	return this;
}

PathBlock* PathBlock::scale(float scaleX, float scaleY)
{
	changeScale(scaleX, scaleY);

	resetTransform();
	
	return this;
}

//
//	StraightBlock
//

StraightBlock::StraightBlock() :
	scaleFactor(1.0f/SQRT2)
{
}

sf::Vector2f StraightBlock::pos(float t) const
{
	return transform.transformPoint(t*scaleFactor, t*scaleFactor);
}

sf::Vector2f StraightBlock::norm(float t) const
{
	//The normal is the same at all points on the line
	sf::Vector2f result = pos(1.0f) - pos(0.0f);
	return sf::Vector2f(-result.y, result.x);
//	sf::Vector2f result(scaling.y*scaleFactor,-scaling.x*scaleFactor);	
//	return sf::Vector2f(scaling.y*scaleFactor,-scaling.x*scaleFactor);
}

float StraightBlock::length() const
{
	return 1.0f / scaleFactor;
}

void StraightBlock::changeScale(float scaleX, float scaleY)
{
	scaling.x *= scaleX;
	scaling.y *= scaleY;
	scaleFactor = 1.0f / sqrt(scaling.x*scaling.x + scaling.y*scaling.y);
}

//
//	Path
//

Path::Path()
{
}

void Path::addBlock(PathBlock* pb)
{
	blocks.push_back(pb);
}

void Path::smartAddBlock(PathBlock* pb)
{
	if (blocks.size() > 0)
	{
		PathBlock* lastGuy(blocks[blocks.size()-1]);
		sf::Vector2f vec = lastGuy->pos(lastGuy->length());
		pb->translate(vec.x, vec.y);
	}
	
	blocks.push_back(pb);
}

sf::Vector2f Path::pos(float t) const
{
	float aCount = 0.0f;
	float bCount = 0.0f;
	
	std::deque<PathBlock*>::const_iterator i(blocks.begin());
	std::deque<PathBlock*>::const_iterator end(blocks.end());
	while (i < end)
	{
		bCount += (*i)->length();
		if (bCount > t)
			return (*i)->pos(t-aCount);
		
		aCount = bCount;
		++i;
	}
	
	--i;
	return (*i)->pos((*i)->length());
}

sf::Vector2f Path::norm(float t) const
{
	float aCount = 0.0f;
	float bCount = 0.0f;
	
	std::deque<PathBlock*>::const_iterator i(blocks.begin());
	std::deque<PathBlock*>::const_iterator end(blocks.end());
	while (i < end)
	{
		bCount += (*i)->length();
		if (bCount > t)
			return (*i)->norm(t-aCount);
		
		aCount = bCount;
		++i;
	}
	
	--i;
	return (*i)->norm((*i)->length());
}

float Path::length() const
{
	float toReturn(0.0f);

	std::deque<PathBlock*>::const_iterator i(blocks.begin());
	std::deque<PathBlock*>::const_iterator end(blocks.end());
	while (i < end)
	{
		toReturn += (*i)->length();
		++i;
	}
	
	return toReturn;
}

void Path::changeScale(float scaleX, float scaleY)
{
	//psyche! You can't!
}