#ifndef PLAYER_H
#define	PLAYER_H

#include <SFML/Graphics/Texture.hpp>
#include "Actor.h"
#include "Path.h"

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
	
	Player();
	virtual ~Player();
	
	//basic
	void button(bool);
	void update(const sf::Time&);
	
	//path
	void setPath(const Path&);
	void setPos(float pos);
	void go();
	void clipToPath();
	void applyHeight();
	
	//states
	void initUp();
	void initDown();
	void initNeutral();
	void initStopped();
	
	//phsyics
	
	static sf::Texture playerTxt;
	float height;
	float velocity;
	float gravity;
	float t;
	State* state;
	
	UpState up;
	DownState down;
	NeutralState neutral;
	StoppedState stopped;

private:
	
	const Path* path;
};

#endif //PLAYER_H