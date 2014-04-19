
class PlayerMotion
{
public:
	void update(const sf::Time&);
	
	void setPath(const Path&);
	void setPos(float pos);
	void go();
	void clipToPath();
	void applyHeight();
	void move(const sf::Time&);
	
	void setNormalVelocity(float, bool);
	void setParallelVelocity(float, bool);
	
	float height;
	float normalVelocity;
	float parallelVelocity;
	float gravity;
	float t;
	
	float FRICTION;// = 0.001f;
	float GRAVITY;// = 0.000015f;
	float LOWGRAVITY;// = 0.000003f;
	float MOVESPEED;// = 60.0f;
	float JUMPSPEED;// = 130.0f;
	
private:
	sf::Vector2f fulcrum;
	const Path* path;
	sf::Vector2f velocity;
}