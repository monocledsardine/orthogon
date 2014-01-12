#include "Animation.h"
#include <algorithm>

using namespace std;

Animation::Animation()
{
	frameDuration = sf::Time::Zero;
	setTexture(texture, true); //By default textureRect is 0 x 0!
}

bool Animation::loadFromImage(const TiledImage& image, sf::Time dur, bool resetRect)
{
	bool result = texture.loadFromImage(image);
	frames.resize(image.tiles.size());
	copy(image.tiles.begin(), image.tiles.end(), frames.begin());
	
	frameDuration = dur;
	
	return result;
}

void Animation::setFrame(int index)
{
	if (numFrames() == 0)
	{
		return;
	}	
	setTextureRect(frames[index % numFrames()]);
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