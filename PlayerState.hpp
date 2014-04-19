class PlayerState
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
	
	State* state;
	
	UpState up;
	DownState down;
	NeutralState neutral;
}