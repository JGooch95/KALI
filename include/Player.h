#ifndef PLAYER_H
#define PLAYER_H

#include "collidable.h"
#include "movable.h"
#include <iostream>

class Player : public Collidable, public Movable
{
public:
	sf::IntRect Frames[17];
	Player();
	void PlayerJump();
	sf::Texture m_PlayerTexture;
	void update(sf::Vector2f timevector);

	sf::Clock AnimationTimer;
};

#endif