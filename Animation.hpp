#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "TiledImage.hpp"

class Animation	:
	public sf::Sprite
{
public:
	Animation();
	virtual ~Animation() {}
	
	void loadFromTexture(const TiledTexture&, sf::Time dur = sf::Time::Zero, 
						bool resetRect = false);
	
	/*	Return the indexed frame, or the frame 
		indicated by modulo (numFrames) if index
		is out of bounds.
	*/
	//const sf::Texture& getFrame(int index) const;
	
	/*	Set the current frame for drawing
	*/
	void setFrame(int index);
	void setFrame(const sf::Time&);
	
	/*	Return the index of the frame indicated by
		elapsed time since the start of the animation.
	*/
	int getFrame(const sf::Time&) const;
	
	bool update(const sf::Time&);
	
	/*const sf::Texture& getFrame(const sf::Time&) const 
		{ return getFrame(getIndex(sf::Time)); }*/	
		
	int numFrames() const 
		{ return frames->size(); }
	
	/* 	Time between frames
	*/
	sf::Time frameDuration;
protected:
	const TileSet* frames;
	sf::Time currentTime;
};


/*	Something that uses an Animation
*/
class Animatable
{
public:
	Animatable() : animationSpeed(1.0f) {}

	int getFrame() const { return sprite->getFrame(frameTime); }	
	void updateTime(sf::Time t) { frameTime += t*animationSpeed; }

	Animation* sprite;
	sf::Time frameTime;
	float animationSpeed;
};

#endif //ANIMATION_H