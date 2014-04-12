#include "Player.h"
#include "VectorHelper.h"

Player::Player(ImageRef& ref) : state(&neutral)
{
	getTextures(ref);
	roll();
	mask = sf::IntRect(0, 0, ROLL_TXT->getSize().x, ROLL_TXT->getSize().y);
}
Player::~Player()
{
}

void Player::getTextures(ImageRef& ref)
{
	ROLL_TXT = ref.get(ImageRef::MAN_UP_1);
	DOWN1_TXT = ref.get(ImageRef::MAN_DOWN_1);
	DOWN2_TXT = ref.get(ImageRef::MAN_DOWN_2);
	EAT_TXT = ref.get(ImageRef::MAN_EAT_1);
	OOF_TXT = ref.get(ImageRef::MAN_OOF_1);
	STAND_TXT = ref.get(ImageRef::MAN_STAND_1);
	JUMP_TXT = ref.get(ImageRef::MAN_JUMP_1);
}

#include <stdio.h>
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

void Player::update(const sf::Time& time)
{
	fulcrum = path->pos(t);
	state->update(this, time);
	updateSprite(time);
}

void Player::roll(){setSprite(ROLL_TXT, ROLL_FSPEED); sprite.setRotation(0);}
void Player::down1() {setSprite(DOWN1_TXT, DOWN1_FSPEED);
	if (gravity < 0) sprite.setRotation(180); else sprite.setRotation(0);}
void Player::down2() {setSprite(DOWN2_TXT, DOWN2_FSPEED);
	if (gravity < 0) sprite.setRotation(180); else sprite.setRotation(0);}
void Player::eat() {setSprite(EAT_TXT, EAT_FSPEED);}
void Player::oof() {setSprite(OOF_TXT, OOF_FSPEED);}
void Player::run() {setSprite(RUN_TXT, RUN_FSPEED);}
void Player::stand() {setSprite(STAND_TXT, STAND_FSPEED);}
void Player::jump() {setSprite(JUMP_TXT, JUMP_FSPEED);}

void Player::updateSprite(const sf::Time& time)
{
	bool endAnim = sprite.update(time);
	if (endAnim)
	{
		if (currentTxt == JUMP_TXT);
			roll();
	}
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