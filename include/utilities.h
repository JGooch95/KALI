#ifndef UTILITIES_H
#define UTILITIES_H

#include <SFML/Graphics.hpp>
#include <collidable.h>
#include <player.h>


class Utils
{
public: 

	/* ---------------- Attributes ---------------- */

	///stores the value of pi
	static const float kfPi;

	///stores the value of pi/180 for use in converting degrees to radians
	static const float kfDegToRad;




	/* ---------------- Methods ---------------- */

	///returns the dot product of two passed vectors, vectorA & vectorB
	static float dotProduct(const sf::Vector2f vectorA, const sf::Vector2f vectorB);

	///returns the magnitude of passed vector
	static float magnitude(const sf::Vector2f vector);

	///returns the direction unit vector given the angle fAngle
	static sf::Vector2f angleUnitVector(const float fAngle);

	///returns the normalised unit vector of passed vector
	static sf::Vector2f normaliseVector(const sf::Vector2f vector);

	///returns the lowest of the two passed floats
	static float min(const float fFirst, const float fSecond);

	///returns the highest of the two passed floats
	static float max(const float fFirst, const float fSecond);

	///returns the passed vector rotated around the origin clockwise by fAngle
	static sf::Vector2f rotateVector(const sf::Vector2f vector, const float fAngle);

	///checks and resolves collisions of passed OBB and Circle
	static void wallPlayerCollision(Collidable& collider, Player& player);

};

#endif