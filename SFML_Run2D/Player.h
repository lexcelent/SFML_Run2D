#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

// temporary solution
const int Ground = 150;

class Player
{
public:
	float dx, dy; // speed
	sf::FloatRect rect; // x, y, width, height
	bool onGround = false;
	sf::Texture texture;
	sf::Sprite sprite;

	Player() {
		texture.loadFromFile("images/player.png");
		sprite.setTexture(texture);
		rect = sf::FloatRect(100, 100, 50, 50);
		dx = dy = 0;
	}

	void update(float time)
	{
		// rect.left is X
		rect.left += dx * time;

		// 0.0005 is acceleration
		// acceleration * time = speed
		if (!onGround) dy = dy + 0.0005 * time;

		// rect.top is Y
		rect.top += dy * time;
		onGround = false;

		if (rect.top > Ground) {
			rect.top = Ground;
			dy = 0;
			onGround = true;
		}

		sprite.setPosition(rect.left, rect.top);

		dx = 0;
	}
};

#endif