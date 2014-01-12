#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "DottedPath.h"
#include "Player.h"

Path makePath()
{
	Path path;

	return path;
}

sf::Texture Player::playerTxt;
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Orthogon");
	
	Path path;
	StraightBlock b1, b2, b3;
	b1.translate(10.0f, 10.0f)->scale(0.0f, 300.0f);
	b2.rotate(-PI / 2.0f)->scale(200.0f, 200.0f);
	b3.scale(40.0f, 200.0f);
	
	path.smartAddBlock(&b1);
	path.smartAddBlock(&b2);
	path.smartAddBlock(&b3);
	
	DottedPath dp;
	dp.dotTexture = new sf::Texture();
	dp.dotTexture->loadFromFile("images/line_1.png");
	dp.path = &path;
	dp.render();
	
	Player player;
	player.setPath(path);
	player.go();
	
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
	
	delete dp.dotTexture;
	
	return EXIT_SUCCESS;
}