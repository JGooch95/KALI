#ifndef COLLECTABLES_H
#define COLLECTABLES_H

#include <SFML/Graphics.hpp>

class Collectable : public sf::Drawable
{
	Collectable(char Item);

	char m_cItemType;
	void ItemCollected();

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void update(float timestep);
};

#endif