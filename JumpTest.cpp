#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "DottedPath.h"
#include "Player.h"
#include "ImageRef.h"

Path makePath()
{
	Path path;

	return path;
}
#include <stdio.h>
#include <iostream>
#include <sstream>
using namespace std;
int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "Jump Test");
	
	ImageRef imageRef;
	imageRef.loadTextures();
	
	Path path;
	StraightBlock b1;
	b1.translate(200.0f, 200.0f)->scale(0.00000000001f, 0.0f);
	path.smartAddBlock(&b1);
	
	Player player(imageRef);
	player.setPath(path);
	player.go();
	
	sf::Clock clock;
	
	//
	sf::Font font;
	font.loadFromFile("arial.ttf");
	
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(10);
	ostringstream os;
	
	
	player.GRAVITY = 0.00005f;
	player.LOWGRAVITY = 0.00001f;
	player.FRICTION = 0.0001f;
	player.MOVESPEED = 60.0f;
	player.JUMPSPEED = 100.0f;
					
	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
			{
				cout << "Gravity: ";
				cin >> player.GRAVITY;
				if (player.GRAVITY < 0.0f)
				{
					//set defaults
					player.GRAVITY = 0.00005f;
					player.LOWGRAVITY = 0.00001f;
					player.FRICTION = 0.1f;
					player.MOVESPEED = 60.0f;
					player.JUMPSPEED = 200.0f;
				}
				else
				{
					cout << "LowGravity: ";
					cin >> player.LOWGRAVITY;
					cout << "Friction: ";
					cin >> player.FRICTION;
					cout << "MoveSpeed: ";
					cin >> player.MOVESPEED;
					cout << "JumpSpeed: ";
					cin >> player.JUMPSPEED;
				}

				os << "Gravity: " << player.GRAVITY << endl;
				os << "LowGravity: " << player.LOWGRAVITY << endl;
				os << "Friction: " << player.FRICTION << endl;
				os << "MoveSpeed: " << player.MOVESPEED << endl;
				os << "JumpSpeed: " << player.JUMPSPEED << endl;
 			}
		}
		
		ostringstream gravStream;
		gravStream << "player gravity: " << player.gravity << endl;
		text.setString(os.str() + gravStream.str());
		player.button(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
		player.update(clock.restart());
		
		window.clear(sf::Color(255, 100, 100, 255));
		
		window.draw(player.sprite);
		window.draw(text);
		window.display();
	}
	
	return EXIT_SUCCESS;
}