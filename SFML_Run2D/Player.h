#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

// Ground of the map
const int Ground = 550;

// Map size
const int H = 12; // Height
const int W = 12; // Width
const int TileSize = 32;


sf::String TileMap[H]{
	"BBBBBBBBBBBB",
	"B          B",
	"B          B",
	"B          B",
	"B          B",
	"B          B",
	"B          B",
	"B          B",
	"B          B",
	"B          B",
	"B          B",
	"BBBBBBBBBBBB",
};

class Player
{
public:
	float dx, dy; // speed
	sf::FloatRect rect; // x, y, width, height
	bool onGround = false;
	sf::Texture texture;
	sf::Sprite sprite;
	float currentFrame; // animation

	Player() {
		texture.loadFromFile("images/player.png");
		sprite.setTexture(texture);
		rect = sf::FloatRect(0, 0, 32, 32);
		sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
		
		// start position
		rect.left = 64;
		rect.top = 64;
		
		dx = dy = 0;
		currentFrame = 0;
	}
	
	void update(float time)
	{
		// rect.left is X
		rect.left += dx * time;
		Collision(0);

		// 0.0005 is acceleration
		// acceleration * time = speed
		if (!onGround) dy = dy + 0.0005 * time;

		// rect.top is Y
		rect.top += dy * time;
		onGround = false;
		Collision(1);

		//
		// Use this code if you don't have collision check
		// and you are using "Ground" 
		// 
		// stay on the Ground
		/*
		if (rect.top > Ground) {
			rect.top = Ground;
			dy = 0;
			onGround = true;
		}
		*/

		// animation
		currentFrame += 0.005 * time;
		if (currentFrame > 2) currentFrame -= 2;

		if (dx > 0) sprite.setTextureRect(sf::IntRect(0 + int(currentFrame) * 32, 32, 32, 32));
		if (dx < 0) sprite.setTextureRect(sf::IntRect(0 + int(currentFrame) * 32 + 32, 32, -32, 32));
		if (dx == 0) sprite.setTextureRect(sf::IntRect(0 + int(currentFrame) * 32, 0, 32, 32));

		sprite.setPosition(rect.left, rect.top);

		dx = 0;
	}

	// dir is direction
	// 0 is X, 1 is Y
	void Collision(bool dir) {
		for (int i = rect.top / TileSize; i < (rect.top + rect.height) / TileSize; i++)
			for (int j = rect.left / TileSize; j < (rect.left + rect.width) / TileSize; j++)
				if (TileMap[i][j] == 'B')
				{
					if ((dx > 0) && (dir == 0)) { rect.left = j * TileSize - rect.width; }
					if ((dx < 0) && (dir == 0)) { rect.left = j * TileSize + TileSize; }
					if ((dy > 0) && (dir == 1)) { rect.top = i * TileSize - rect.height; dy = 0; onGround = true; }
					if ((dy < 0) && (dir == 1)) { rect.top = i * TileSize + rect.height; dy = 0; }
				}
			
	}
};

#endif