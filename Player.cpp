#include "Player.hpp"
#include "VectorHelper.hpp"
#include <stdio.h>

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