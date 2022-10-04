#include <SFML/Graphics.hpp>
#include "Player.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Red);

	// console anti-spam "Failed to set DirectInput device axis mode: 1"
	sf::err().rdbuf(NULL);

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
			shape.move(-0.1*time, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			shape.move(0.1*time, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			shape.move(0, -0.1);
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}