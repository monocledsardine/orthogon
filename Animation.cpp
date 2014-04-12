#include "Animation.h"
#include <algorithm>

using namespace std;

Animation::Animation()
{
	frameDuration = sf::Time::Zero;
}

void Animation::loadFromTexture(const TiledTexture& texture, sf::Time dur, bool resetRect)
{
	setTexture(texture);
	frames = &texture.tiles;
	setOrigin(frames->origin.x, frames->origin.y);
	
	frameDuration = dur;
	setFrame(0);
}

void Animation::setFrame(int index)
{
	if (numFrames() == 0)
	{
		return;
	}	
	setTextureRect(frames->at(index % numFrames()));
	currentTime = frameDuration*static_cast<float>(index);
}

void Animation::setFrame(const sf::Time& time)
{
	if (numFrames() == 0)
	{
		return;
	}	
	setTextureRect(frames->at(getFrame(time) % numFrames()));
}

bool Animation::update(const sf::Time& time)
{
	bool toReturn = false;
	currentTime += time;
	
	sf::Time length(frameDuration*static_cast<float>(numFrames()));
	
	while (currentTime > length)
	{
		currentTime -= length;
		toReturn = true;
	}	
	
	setFrame(currentTime);
	return toReturn;
}

int Animation::getFrame(const sf::Time& time) const
{
	if (frameDuration == sf::Time::Zero || numFrames() == 0)
		return 0;
		
	float ratio(time.asSeconds() / frameDuration.asSeconds());
	
	if (ratio >= 0.0f)
		return (int)ratio % numFrames();
	else
		return numFrames() - 1 - ((-(int)ratio) % numFrames());
}