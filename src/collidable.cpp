#include <collidable.h>

void Collidable::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Sprite);
}

sf::Vector2f Collidable::getPosition()
{
	return m_Sprite.getPosition();
}

void Collidable::setPosition(sf::Vector2f position)
{
	m_Sprite.setPosition(position);
}

void Collidable::setTexture(sf::Texture* pTexture)
{
	m_Sprite.setTexture(*pTexture);
}

void Collidable::setScale(float fXScale, float fYScale)
{
	m_Sprite.setScale(fXScale, fYScale);
}

sf::FloatRect Collidable::getRect()
{
	return m_Sprite.getGlobalBounds();
}

Collidable::Collidable()
{

}