#include "Player.h"

Player::Player() : state(&neutral)
{
	playerTxt.loadFromFile("images/man_stand_1.png");
	sprite.setTexture(playerTxt);
	mask = sf::IntRect(0, 0, playerTxt.getSize().x, playerTxt.getSize().y);
}
Player::~Player()
{
}


void Player::button(bool pressed)
{
	enum INPUT { PRESS, RELEASE, HOLD, WAIT };
	static bool lastPressed;
	
	if (pressed)
	{
		lastPressed ? state->hold(this) : state->press(this);
	} else
	{
		lastPressed ? state->release(this) : state->wait(this);
	}
		
	lastPressed = pressed;
}

void Player::update(const sf::Time& time)
{
	state->update(this, time);
	height += velocity;
	velocity += gravity;
	
	clipToPath();
	applyHeight();
}

void Player::setPath(const Path& p)
{
	path = &p;
}

void Player::setPos(float pos)
{
	t = pos;
}

void Player::go()
{
	if (state == &stopped)
		state = &neutral;
}

void Player::clipToPath()
{
	setPosition(path->pos(t));
}

void Player::applyHeight()
{
	//setPosition(sprite.getPosition() + path->norm(t)*height);
}


void Player::initUp()
{
	state = &up;
	gravity = 1.0f;
}
void Player::initDown()
{
	state = &down;
	gravity = -1.0f;
}
void Player::initNeutral()
{
	state = &neutral;
	gravity = 0.0f;
	velocity = 0.0f;
}
void Player::initStopped()
{
	state = &stopped;
	gravity = 0.0f;
	velocity = 0.0f;
}

///////////////////////////////////////
void Player::UpState::hold(Player* player)
{
	
}
void Player::UpState::press(Player* player)
{
	
}
void Player::UpState::release(Player* player)
{
	
}
void Player::UpState::wait(Player* player)
{
	
}
void Player::UpState::update(Player* player, const sf::Time& time)
{
	if (player->height <= 0)
	{
		player->initDown();		
	}
}
//////////////////////////////////////////
void Player::DownState::hold(Player* player)
{
	
}
void Player::DownState::press(Player* player)
{
	
}
void Player::DownState::release(Player* player)
{
	
}
void Player::DownState::wait(Player* player)
{
	
}
void Player::DownState::update(Player* player, const sf::Time& time)
{
	if (player->height >= 0)
	{
		player-> initUp();
	}
}
/////////////////////////////////////////////
void Player::NeutralState::hold(Player* player)
{
	
}
void Player::NeutralState::press(Player* player)
{
	player->velocity = 100.0f;
	player->initUp();
}
void Player::NeutralState::release(Player* player)
{
	player->velocity = -100.0f;
	player->initDown();
}
void Player::NeutralState::wait(Player* player)
{
	
}
void Player::NeutralState::update(Player* player, const sf::Time& time)
{
	//Move down path
	player->t += time.asSeconds()*60.0f;
}
/////////////////////////////////////////////
void Player::StoppedState::hold(Player* player)
{
	
}
void Player::StoppedState::press(Player* player)
{
	
}
void Player::StoppedState::release(Player* player)
{
	
}
void Player::StoppedState::wait(Player* player)
{
	
}
void Player::StoppedState::update(Player* player, const sf::Time& time)
{
}