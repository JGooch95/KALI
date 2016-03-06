#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include <SFML/Graphics.hpp>


class Collidable: public sf::Drawable
{
protected:

	sf::Sprite m_Sprite;
	sf::Texture m_Texture;

public:

	///virtual draw function inherited from sf::Drawable
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	///returns the position of the object (from it's origin) as a Vector2f
	sf::Vector2f getPosition();

	///sets the position of the object (from it's origin) to the passed Vector2f
	void setPosition(sf::Vector2f);


	void setTexture(sf::Texture* pTexture);


	void setScale(float fXScale, float fYScale);

	///returns a floatrect containing the object's position and dimensions
	sf::FloatRect getRect();

	///constructor of Collidable
	Collidable();



};





#endif 