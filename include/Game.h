#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Loader.h"
#include <vector>
#include <SFML/Audio.hpp>

using namespace sf;

class Game : public Drawable
{
private:

	///Texture objects for each game element
	sf::Texture playerTex, wallTex, spikeTex;

	///data structures containing the game's collidable elements
	std::vector<Collidable> m_Walls;
	std::vector<Collidable> m_Spikes;

	///instance of the player object
	Player Shaman;

	sf::SoundBuffer intro, loop;
	sf::Sound sound;
	bool bInitialised;
public:

	///default constructor
	Game();

	///virtual draw function inherited from sf::Drawable
	void draw(RenderTarget &target, RenderStates states) const;

	///update function 
	void update(float timestep);

	///checks if the player collides with collidable objects, resolving the collision if it does
	void checkCollisions();


	void processKeyPress();


	///populates the collidable vectors with data from text files
	void GenerateBlocks();

	///returns the player's position for use in the game's viewport
	sf::Vector2f getPlayerPos();



	void MainMenuMusic();

};


#endif