#include <utilities.h>

const float Utils::kfPi = 3.14159f;
const float Utils::kfDegToRad = kfPi / 180.0f;
const float kfCollisionTolerance = 0.25;

float Utils::dotProduct(const sf::Vector2f vectorA, const sf::Vector2f vectorB)
{
	return (vectorA.x * vectorB.x) + (vectorA.y * vectorB.y);
}

float Utils::magnitude(const sf::Vector2f vector)
{
	return sqrtf(powf(vector.x, 2.0f) + powf(vector.y, 2.0f));
}

sf::Vector2f Utils::angleUnitVector(const float fAngle)
{
	return sf::Vector2f(cosf(fAngle * kfDegToRad), sinf(fAngle * kfDegToRad));
}

sf::Vector2f Utils::normaliseVector(const sf::Vector2f vector)
{
	float fMagnitude(magnitude(vector));

	if (fMagnitude != 0)
		return sf::Vector2f(vector.x / fMagnitude, vector.y / fMagnitude);
	else
		return sf::Vector2f(0.0f, 0.0f);
}

float Utils::min(const float fFirst, const float fSecond)
{
	if (fFirst < fSecond)
		return fFirst;
	else
		return fSecond;
}

float Utils::max(const float fFirst, const float fSecond)
{
	if (fFirst < fSecond)
		return fSecond;
	else
		return fFirst;
}

sf::Vector2f Utils::rotateVector(const sf::Vector2f vector, const float fAngle)
{
	sf::Vector2f retVector;

	retVector.x = (vector.x * cosf(fAngle)) + (vector.y * -sinf(fAngle));
	retVector.y = (vector.x * sinf(fAngle)) + (vector.y *  cosf(fAngle));

	return retVector;
}

void Utils::wallPlayerCollision(Collidable& collider, Player& player)
{
	sf::FloatRect localWall, localPlayer;

	float xOverlap;
	float yOverlap;
	
	localWall = collider.getRect();
	localPlayer = player.getRect();

	//if the wall is above the player
	if (localWall.top < localPlayer.top)
		yOverlap = localPlayer.top - (localWall.top + localWall.height);
	//if the wall is below the player
	else if (localWall.top > localPlayer.top)
		yOverlap = ((localPlayer.top + localPlayer.height) - localWall.top);
	else
	{
		//sf::err() << "Collision too small (yAxis)\n";
		yOverlap = 0;
	}	

	//if the wall is to the left of the player
	if (localWall.left < localPlayer.left)
		xOverlap = localPlayer.left - (localWall.left + localWall.height);
	//if the wall is to the right of the player
	else if (localWall.left > localPlayer.left)
		xOverlap = (localPlayer.left + localPlayer.width) - localWall.left;
	else
	{
		//sf::err() << "Collision too small (xAxis)\n";
		xOverlap = 0;
	}

	

	//function aborts if collision is insignificant
	if (fabsf(xOverlap) <= 0.2f && fabsf(yOverlap) <= 0.2f)
	{
		//sf::err() << "No Collision!\n";
		return;
	}

	if (fabsf(xOverlap) > fabsf(yOverlap))
	{
		player.Movable::setPosition(sf::Vector2f(player.Movable::getPosition().x, player.Movable::getPosition().y - yOverlap));
		if (yOverlap > 0)
			player.setVelocity(sf::Vector2f(player.getVelocity().x, 0.0f));
		else
			player.setVelocity(sf::Vector2f(player.getVelocity().x, 1.0f));
	}
	else
	{
		player.Movable::setPosition(sf::Vector2f(player.Movable::getPosition().x - xOverlap, player.Movable::getPosition().y));
		if (xOverlap > 0)
			player.setVelocity(sf::Vector2f(-5.0f, player.getVelocity().y));
		else
			player.setVelocity(sf::Vector2f(5.0f, player.getVelocity().y));
	}

}
