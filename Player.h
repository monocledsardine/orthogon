#ifndef PLAYER_H
#define	PLAYER_H

#include <SFML/Graphics/Texture.hpp>
#include "Actor.h"
#include "Path.h"
#include "ImageRef.h"

class Player :
	public Actor
{
public:
	class State
	{
	public:
		virtual void hold(Player*)=0;
		virtual void press(Player*)=0;
		virtual void release(Player*)=0;
		virtual void wait(Player*)=0;
		virtual void update(Player*, const sf::Time&)=0;
	};
	
	class UpState :
		public State
	{
		virtual void hold(Player*);
		virtual void press(Player*);
		virtual void release(Player*);
		virtual void wait(Player*);
		virtual void update(Player*, const sf::Time&);
	};
	
	class DownState :
		public State
	{
		virtual void hold(Player*);
		virtual void press(Player*);
		virtual void release(Player*);
		virtual void wait(Player*);
		virtual void update(Player*, const sf::Time&);
	};
	
	class NeutralState :
		public State
	{
		virtual void hold(Player*);
		virtual void press(Player*);
		virtual void release(Player*);
		virtual void wait(Player*);
		virtual void update(Player*, const sf::Time&);
	};
	
	class StoppedState :
		public State
	{
		virtual void hold(Player*);
		virtual void press(Player*);
		virtual void release(Player*);
		virtual void wait(Player*);
		virtual void update(Player*, const sf::Time&);
	};
	
	Player(ImageRef&);
	virtual ~Player();
	
	void getTextures(ImageRef&);
	
	//basic
	void button(bool);
	void update(const sf::Time&);
	void updateSprite(const sf::Time&);
	
	//path
	void setPath(const Path&);
	void setPos(float pos);
	void go();
	void clipToPath();
	void applyHeight();
	void move(const sf::Time&);
	
	//physics
	void setNormalVelocity(float, bool);
	void setParallelVelocity(float, bool);
	
	//states
	void initUp();
	void initDown();
	void initNeutral();
	void initStopped();
	
	float height;
	float normalVelocity;
	float parallelVelocity;
	float gravity;
	float t;
	State* state;
	
	UpState up;
	DownState down;
	NeutralState neutral;
	StoppedState stopped;

	float FRICTION;// = 0.001f;
	float GRAVITY;// = 0.000015f;
	float LOWGRAVITY;// = 0.000003f;
	float MOVESPEED;// = 60.0f;
	float JUMPSPEED;// = 130.0f;
		
	void setSprite(TiledTexture* tt, float spd)
	{
		if (sprite.getTexture() != tt)
		{
			sprite.loadFromTexture(*tt, sf::seconds(spd)); 
			currentTxt=tt;
		}	
	}
	
	TiledTexture* ROLL_TXT;
	static const float ROLL_FSPEED = 0.02f;
	
	TiledTexture* DOWN1_TXT;
	static const float DOWN1_FSPEED = 0.1f;
	
	TiledTexture* DOWN2_TXT;
	static const float DOWN2_FSPEED = 0.1f;
	
	TiledTexture* EAT_TXT;
	static const float EAT_FSPEED = 0.1f;
	
	TiledTexture* OOF_TXT;
	static const float OOF_FSPEED = 0.1f;
	
	TiledTexture* RUN_TXT;
	static const float RUN_FSPEED = 0.1f;
	
	TiledTexture* STAND_TXT;
	static const float STAND_FSPEED = 0.1f;
	
	TiledTexture* JUMP_TXT;
	static const float JUMP_FSPEED = 0.2f;
	
	void roll();
	void down1();
	void down2();
	void eat();
	void oof();
	void run();
	void stand();
	void jump();
private:
	sf::Vector2f fulcrum;
	const Path* path;
	sf::Vector2f velocity;
	TiledTexture* currentTxt;
};

#endif //PLAYER_H