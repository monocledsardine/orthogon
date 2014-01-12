#ifndef PATH_H
#define PATH_H

#include "Angle.h"
#include <SFML/Graphics/VertexArray.hpp>
#include <deque>

// A 2D curve traversible by a single parameter t.
class Curve
{
public:
	// Find the position at t
	virtual sf::Vector2f pos(float t) const=0;
	
	// Find the unit normal of the curve at t
	virtual sf::Vector2f norm(float t) const=0;
	
	// Length of the curve as measured by t
	virtual float length() const=0;
};

// A small block of a path, capable of being transformed.
class PathBlock : public Curve
{
public:	
	PathBlock();
	
	PathBlock* translate(float x, float y);
	PathBlock* rotate(const Angle& angle);
	PathBlock* scale(float scaleX, float scaleY);
protected:
	virtual void changeScale(float scaleX, float scaleY)=0;	
	
	void resetTransform()
	{
		transform = sf::Transform();
		transform.translate(translation).rotate(rotation.asDegrees()).scale(scaling);
	}
	
	sf::Vector2f scaling;
	sf::Vector2f translation;
	Angle rotation;
	//Holds location and rotation of block
	sf::Transform transform;
};

// 
class StraightBlock : public PathBlock
{
public:
	StraightBlock(); 
	sf::Vector2f pos(float t) const;
	sf::Vector2f norm(float t) const;
	float length() const;
protected:
	void changeScale(float, float);
private:
	float scaleFactor;
};

class Path : public Curve
{
public:
	Path();
	void addBlock(PathBlock*);
	void smartAddBlock(PathBlock*);
	sf::Vector2f pos(float t) const;
	sf::Vector2f norm(float t) const;
	float length() const;
protected:
	void changeScale(float, float);
private:
	std::deque<PathBlock*> blocks;
};

#endif //PATH_H