#include <iostream>
#include <stdio.h>
#include "Test.h"
#include "Suite.h"
#include "../Path.hpp"

using namespace std;
using namespace TestSuite;

class GameTest :
	public Test
{
public:
	GameTest()
	{
	}
	
	void run()
	{
		testStraightPath();
		testPath();
	}
	
	void testStraightPath()
	{
		// Horizontal path, messed up
		Path path;
		StraightBlock block;
		block.scale(100.0f, 0.0f);
		block.translate(10.0f, 14.5f);
		block.rotate(-20.0f);
		path.addBlock(&block);
		test_(path.length() == 100.0f);
		
		// 3, 4, 5 triangle * 3
		block = StraightBlock();
		block.scale(3.0f, 4.0f);
		path.addBlock(&block);
		path.addBlock(&block);
		test_(path.length() == 15.0f);
		
		// scaling to 0 sticks
		block.scale(0.0f, 0.0f);
		block.scale(3.0f, 4.0f);
		test_(path.length() == 0.0f);
		
		// transforms are locally centered
		block = StraightBlock();
		block.translate(-3.0f, 1.5f);
		test_(block.pos(0.0f) == sf::Vector2f(-3.0f, 1.5f));
		test_(block.pos(block.length()) == sf::Vector2f(-2.0f, 2.5f));	

		block.rotate(PI / 2.0f);
		test_(block.pos(0.0f) == sf::Vector2f(-3.0f, 1.5f));
		test_(block.pos(block.length()) == sf::Vector2f(-4.0f, 2.5f));	
		
		block.scale(4.0f, 0.0f);
		test_(block.pos(0.0f) == sf::Vector2f(-3.0f, 1.5f));
		sf::Vector2f err = block.pos(block.length())-sf::Vector2f(-3.0f, 5.5f);
		test_(err.x < 0.00001f && err.y < 0.00001f);	
	}
	
	void testPath()
	{
		Path path;
		StraightBlock b1, b2, b3;
		b1.translate(10.0f, 1.0f)->scale(0.0f, -5.0f);
		b2.translate(10.0f, -4.0f)->rotate(-PI / 6.0f)->scale(sqrt(2.0f), sqrt(2.0f));
		b3.translate(b2.pos(b2.length()).x, b2.pos(b2.length()).y)->scale(3.0f, 4.0f);
		
		path.addBlock(&b1);
		path.addBlock(&b2);
		path.addBlock(&b3);
		
		test_(path.length() == 12.0f);
		test_(path.pos(7.0f) == b3.pos(0.0f));
		test_(path.norm(6.0f) == b2.norm(1.0f));
		
		sf::Vector2f nm = b3.norm(1.0f);
		test_(abs(nm.x*nm.x + nm.y*nm.y - 1.0f)  < 0.0001f);
	}
};

int main()
{
	Suite suite("SFML Game Tests");
	suite.addTest(new GameTest);
	suite.run();
	long nFail = suite.report();
	suite.free();
	return nFail;
}
