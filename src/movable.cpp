#include <movable.h>

sf::Vector2f Movable::getFriction(sf::Vector2f velocity)
{
	sf::Vector2f frictionalForce;

	//coulomb model of friction
	frictionalForce = m_fFrictionCoeff * 9.8f * velocity;

	return frictionalForce;
}

void Movable::update(sf::Vector2f timeVector)
{
	const float kfGravity = 1200.0f;
	//RK4 integration used to calulate velocity and position
	sf::Vector2f v1, v2, v3, v4, a1, a2, a3, a4;

	//x-axis
	v1.x = m_Velocity.x;
	a1.x = 0.0f - getFriction(v1).x;

	v2.x = v1.x + a1.x * (timeVector.x / 2.0f);
	a2.x = 0.0f - getFriction(v2).x;

	v3.x = v1.x + a2.x * (timeVector.x / 2.0f);
	a3.x = 0.0f - getFriction(v3).x;

	v4.x = v1.x + a3.x * timeVector.x;
	a4.x = 0.0f - getFriction(v4).x;

	m_Position.x += (v1.x + 2.0f * v2.x + 2.0f * v3.x + v4.x) * timeVector.x / 6.0f;
	m_Velocity.x += (a1.x + 2.0f * a2.x + 2.0f * a3.x + a4.x) * timeVector.x / 6.0f;

	//y-axis
	v1.y = m_Velocity.y;
	a1.y = kfGravity;

	v2.y = v1.y + a1.y * (timeVector.y / 2.0f);
	a2.y = kfGravity;

	v3.y = v1.y + a2.y * (timeVector.y / 2.0f);
	a3.y = kfGravity;

	v4.y = v1.y + a3.y * timeVector.y;
	a4.y = kfGravity;

	m_Position.y += (v1.y + 2.0f * v2.y + 2.0f * v3.y + v4.y) * timeVector.y / 6.0f;
	m_Velocity.y += (a1.y + 2.0f * a2.y + 2.0f * a3.y + a4.y) * timeVector.y / 6.0f;
}
 
void Movable::move(int iDir)
{
	impulse(sf::Vector2f(25.0f * (float)iDir, 0.0f));
}

void Movable::impulse(sf::Vector2f impulse)
{
	m_Velocity += impulse;
}

sf::Vector2f Movable::getVelocity()
{
	return m_Velocity;
}

void Movable::setVelocity(sf::Vector2f Vel)
{
	m_Velocity = Vel;
}

void Movable::setPosition(sf::Vector2f position)
{
	m_Position = position;
}

sf::Vector2f Movable::getPosition()
{
	return m_Position;
}

Movable::Movable()
{
	m_Position.x = 0.0f;
	m_Position.y = 0.0f;
	m_Velocity.x = 0.0f;
	m_Velocity.y = 0.0f;
	m_fFrictionCoeff = 0.5;
}




