#include "PlayerMotion.hpp"

void Player::update(const sf::Time& time)
{
	fulcrum = path->pos(t);
	state->update(this, time);
	updateSprite(time);
}

void Player::setPath(const Path& p)
{
	path = &p;
}

void Player::setPos(float pos)
{
	t = pos;
}

void Player::setNormalVelocity(float v, bool relative = false)
{
	if (relative)
		normalVelocity += v;
	else
		normalVelocity = v;
		
	//printf("Velocitynorm: (%f, %f)\n", velocity.x, velocity.y);
}
void Player::setParallelVelocity(float v, bool relative = false)
{
	if (relative)
		parallelVelocity += v;
	else
		parallelVelocity = v;
	//printf("VELOCITYPARA: (%f, %f)\n", velocity.x, velocity.y);
}

void Player::move(const sf::Time& time)
{
	t += time.asSeconds()*MOVESPEED;
	
	sf::Vector2f disp = path->pos(t) - sprite.getPosition();
	sf::Vector2f norm = path->norm(t);
	sf::Vector2f para = sf::Vector2f(norm.y, -norm.x);
	
	//distances normal and parallel to path	
	float normDist = (disp.x*para.y - disp.y*para.x) / (norm.x*para.y - norm.y*para.x);
	float paraDist; 
	if (para.x == 0)
		paraDist = (disp.y - normDist*norm.y) / para.y;
	else
		paraDist = (disp.x - normDist*norm.x) / para.x;
	
	normalVelocity += gravity/time.asSeconds();
		
	parallelVelocity = 0.0f;
		
	sf::Vector2f newFulcrum(path->pos(t));
	setPosition(sprite.getPosition() + newFulcrum-fulcrum);
	
	height = -normDist;
		
	velocity = (para*parallelVelocity + norm*normalVelocity)/(1.0f + FRICTION*time.asSeconds());
	setPosition(sprite.getPosition() + velocity*time.asSeconds());
}

void Player::clipToPath()
{
	setPosition(fulcrum);
}

void Player::applyHeight()
{
	setPosition(sprite.getPosition() + path->norm(t)*height);
}

