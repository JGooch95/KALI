#ifndef MOVABLE_H
#define MOVABLE_H

#include <SFML/Graphics.hpp>
#include <collidable.h>

class Movable
{
protected:
	///stores the position of the object
	sf::Vector2f m_Position;

	///stores the velocity of the object
	sf::Vector2f m_Velocity;

	///stores the object's frictional coefficient
	float m_fFrictionCoeff;
	
	///calculates friction from passed velocity
	sf::Vector2f getFriction(sf::Vector2f velocity);

public:

	///update function
	virtual void update(sf::Vector2f timeVector);

	///starts moving the object
	void move(int iDir);

	///applies an impulse to the object
	void impulse(sf::Vector2f impulse);

	///returns the object's velocity as a vector
	sf::Vector2f getVelocity();

	void setVelocity(sf::Vector2f Vel);

	///sets the position of the object
	void setPosition(sf::Vector2f position);

	///get the position of the object
	sf::Vector2f getPosition();

	//default constructor
	Movable();

};



#endif