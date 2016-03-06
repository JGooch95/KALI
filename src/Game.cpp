#include "Game.h"
#include <utilities.h>

Game::Game()
{

	if (!wallTex.loadFromFile("./assets/Textures/Blocks/Stone.png"))
	{
		//sf::err() << "wallTex not loaded\n";
	}
	wallTex.setSmooth(true);

	if (!spikeTex.loadFromFile("./assets/Textures/Spikes.png"))
	{
		//sf::err() << "spikeTex not loaded\n";
	}

	if (!intro.loadFromFile("./assets/Sound/FMOD/menu song/Audio Asset/intro {445d2142-d2c9-4c9e-8b75-6d7beae6096a}.wav"))
	{
		//sf::err() << "Failed to load music\n";
	}

	if (!loop.loadFromFile("./assets/Sound/FMOD/menu song/Audio Asset/main.wav"))
	{
		//sf::err() << "Failed to load music\n";
	}
	sound.setBuffer(intro);
	sound.play();
	spikeTex.setSmooth(true);
	bInitialised = false;
}

void Game::draw(RenderTarget & target, RenderStates states) const 
{
	for (auto wall : m_Walls)
		target.draw(wall);

	for (auto spike : m_Spikes)
		target.draw(spike);

	target.draw(Shaman);
}

void Game::update(float timestep)
{

	MainMenuMusic();
	processKeyPress();
	Shaman.update(Vector2f(timestep, timestep));
	checkCollisions();

	if (!bInitialised)
	{
		Shaman.Movable::setPosition(sf::Vector2f(25.0f, 25.0f));
		bInitialised = true;
	}
}

void Game::checkCollisions()
{
	for (auto wall : m_Walls)
	{
		if (Shaman.getRect().intersects(wall.getRect()))
		{
			Utils::wallPlayerCollision(wall, Shaman);

			//sf::err() << "Collision!\n";
		}
	}
	for (auto spike : m_Spikes)
	{
		if (Shaman.getRect().intersects(spike.getRect()))
		{
			Shaman.Movable::setPosition(sf::Vector2f(100.0f, 30.0f));
			//sf::err() << "Collision!\n";
		}
	}
}

void Game::processKeyPress()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && fabsf(Shaman.getVelocity().y) < 0.2) // If 'W' pressed then jump
		Shaman.PlayerJump();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) // If 'D' pressed then move right
		Shaman.move(1);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //If 'A' pressed then move left
		Shaman.move(-1);
}


void Game::GenerateBlocks()
{
	Collidable wall;
	Collidable spike;


	std::vector<std::vector<char>> LevelBits = Loader::LoadLevel("./assets/Level3.txt");
	for (int i = 0; i < LevelBits.size(); i++)//For every Row
	{
		for (int j = 0; j < LevelBits[i].size(); j++)//For every bit
		{
			switch (LevelBits[i][j])
			{
			case 'w':
				wall.setTexture(&wallTex);
				wall.setScale(0.25f, 0.25f);
				wall.setPosition(sf::Vector2f(j*25.0f, i*25.0f));
				m_Walls.push_back(wall);
				break;

			case 's':
				spike.setTexture(&spikeTex);
				spike.setScale(0.25f, 0.25f);
				spike.setPosition(sf::Vector2f(j*25.0f, i*25.0f));
				m_Spikes.push_back(spike);
				break;
		

			}
		}
	}

};

sf::Vector2f Game::getPlayerPos()
{
	return Shaman.Movable::getPosition();
}

void Game::MainMenuMusic()
{

	if (sound.getStatus() != sf::Sound::Playing)
	{
		sound.setBuffer(loop);
		sound.play();
	}

}