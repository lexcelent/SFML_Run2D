#include <SFML/Graphics.hpp>
#include "Player.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Red);

	// console anti-spam "Failed to set DirectInput device axis mode: 1"
	sf::err().rdbuf(NULL);

	// load player
	Player player;

	//
	// TODO: Draw animation
	//

	// link the game to the time
	sf::Clock clock;

	while (window.isOpen())
	{
		// link the game to the time
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		// speed of the game
		time = time / 800;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// speed * time = distance
			//s.move(-0.1*time, 0);
			player.dx = -0.1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			//s.move(0.1*time, 0);
			player.dx = 0.1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			//s.move(0, -0.1);
			if (player.onGround) { player.dy = -0.4; player.onGround = false; }
		}

		player.update(time);

		window.clear();
		window.draw(player.sprite);
		window.display();
	}

	return 0;
}