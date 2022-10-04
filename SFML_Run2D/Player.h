//#include <SFML/Graphics.hpp>
/*
// temporary solution
int ground = 150;

#pragma once
class Player
{
public:
	float dx, dy; // speed
	sf::FloatRect rect; // x, y, width, height
	bool onGround = false;

	Player()
	{
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

		if (rect.top > ground) {
			rect.top = ground; 
			dy = 0;
			onGround = true;
		}

		dx = 0;
	}
};

*/
