#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "DottedPath.hpp"
#include "Player.hpp"
#include "ImageRef.hpp"

Path makePath()
{
	Path path;

	return path;
}
#include <stdio.h>
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Orthogon");
	
	ImageRef imageRef;
	imageRef.loadTextures();
	
	Path path;
	StraightBlock b1, b2, b3, b4;
	b1.translate(100.0f, 100.0f)->scale(0.0f, 300.0f);
	b2.scale(200.0f, 0.0f);
	b3.scale(40.0f, 40.0f);
	b4.scale(-50.0f, 50.0f);
	
	path.smartAddBlock(&b1);
	path.smartAddBlock(&b2);
	path.smartAddBlock(&b3);
	path.smartAddBlock(&b4);
	
	DottedPath dp;
	dp.dotTexture = imageRef.get(ImageRef::LINE_2);
	dp.path = &path;
	dp.render();
	
	Player player(imageRef);
	player.setPath(path);
	player.go();
	
	player.GRAVITY = 0.00005f;
	player.LOWGRAVITY = 0.00001f;
	player.FRICTION = 0.1f;
	player.MOVESPEED = 60.0f;
	player.JUMPSPEED = 200.0f;
	
	sf::Clock clock;
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
		}
		
		player.button(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
		player.update(clock.restart());
		
		window.clear(sf::Color(100, 255, 100, 255));
		
		window.draw(dp);
		window.draw(player.sprite);
		window.display();
	}
	
	return EXIT_SUCCESS;
}