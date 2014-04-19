#include "PlayerState.hpp"

void Player::button(bool pressed)
{
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

void Player::go()
{
	if (state == &stopped)
		state = &neutral;
}

void Player::initUp()
{
	state = &up;
}
void Player::initDown()
{
	state = &down;
}
void Player::initNeutral()
{
	state = &neutral;
	setNormalVelocity(0.0f);
}
void Player::initStopped()
{
	state = &stopped;
}

///////////////////////////////////////
///////////////////////////////////////
void Player::UpState::hold(Player* player)
{
	player->gravity = player->LOWGRAVITY;
	if (player->normalVelocity > 0)
	{
		player->down1();
	} else if (player->currentTxt != player->JUMP_TXT)
	{
		player->roll();
	}
}
void Player::UpState::press(Player* player)
{
	hold(player);
}
void Player::UpState::release(Player* player)
{
	wait(player);
}
void Player::UpState::wait(Player* player)
{
	player->gravity = player->GRAVITY;
	if (player->normalVelocity > 0)
	{
		player->down2();
	}  else if (player->currentTxt != player->JUMP_TXT)
	{
		player->roll();
	}
}
void Player::UpState::update(Player* player, const sf::Time& time)
{
	player->move(time);
	if (player->height > 0)
	{
		player->initDown();		
	}
}
//////////////////////////////////////////
void Player::DownState::hold(Player* player)
{
	player->gravity = -player->LOWGRAVITY;
	if (player->normalVelocity < 0)
	{
		player->down1();
	} else if (player->currentTxt != player->JUMP_TXT)
	{
		player->roll();
	}
}
void Player::DownState::press(Player* player)
{
	hold(player);
}
void Player::DownState::release(Player* player)
{
	wait(player);
}
void Player::DownState::wait(Player* player)
{
	player->gravity = -player->GRAVITY;
	if (player->normalVelocity < 0)
	{
		player->down2();
	} else if (player->currentTxt != player->JUMP_TXT)
	{
		player->roll();
	}
}
void Player::DownState::update(Player* player, const sf::Time& time)
{
	player->move(time);
	if (player->height <= 0)
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
	player->setNormalVelocity(-player->JUMPSPEED);
	player->jump();
	player->initUp();
}
void Player::NeutralState::release(Player* player)
{
	player->setNormalVelocity(player->JUMPSPEED);
	player->jump();
	player->initDown();
}
void Player::NeutralState::wait(Player* player)
{
	
}
void Player::NeutralState::update(Player* player, const sf::Time& time)
{
	player->t += time.asSeconds()*player->MOVESPEED;
	player->setPosition(player->path->pos(player->t));
}
/////////////////////////////////////////////