#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>

void mainMenu();
void gameMenu();

int main()
{

	mainMenu();


	return 0;
}

void mainMenu()
{
	sf::RenderWindow menuWindow(sf::VideoMode(1024, 768, 32U), "Ritual", 5U);
	RectangleShape rectMenu;
	Sprite spriteMenu;
	Texture textMenu;

	rectMenu.setPosition(0,0);
	rectMenu.setSize(Vector2f(1024,768));
	rectMenu.setFillColor(Color::Blue);
	if (!textMenu.loadFromFile("./Assets/Textures/Mainmenu.png"))
	{
		std::cout << "Error was unable to load.";
	};

	spriteMenu.setOrigin(rectMenu.getSize().x / 2.f, rectMenu.getSize().y / 2.f);
	spriteMenu.setTexture(textMenu);
	spriteMenu.setScale(Vector2f(1,1));
	spriteMenu.setPosition(rectMenu.getPosition().x + rectMenu.getSize().x / 2.f, rectMenu.getPosition().y + rectMenu.getSize().y / 2.f);

	while (menuWindow.isOpen())
	{
		sf::Event event;
		while (menuWindow.pollEvent(event))
		{
			// Closes window if close button clicked
			if (event.type == sf::Event::Closed)
			{
				menuWindow.close(); // Allows window to close when 'X' is pressed
				
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Key::Space)
				{
					menuWindow.close();
					gameMenu();
				}
				
			}
		}
		menuWindow.clear(Color::White);
		menuWindow.draw(spriteMenu);
		menuWindow.display();
	}
	
}

void gameMenu()
{
	sf::RenderWindow gameWindow(sf::VideoMode(1024, 768, 32U), "Ritual", 5U);
	sf::View gameView;
	gameView.setSize(sf::Vector2f(gameWindow.getSize()));


	sf::Time frameTime = sf::seconds(1.0f / 144.0f);
	sf::Clock deltaClock;
	float fTimeSinceUpdate; //stores the time since that last game update was made

	Game game;
	game.GenerateBlocks();

	/* ---------------------- Window Loop ---------------------- */

	while (gameWindow.isOpen())
	{
		/* ---------------------- Event Polling ---------------------- */

		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			// Closes window if close button clicked
			if (event.type == sf::Event::Closed)
			{
				gameWindow.close(); // Allows window to close when 'X' is pressed
				return;
			}
		}


		/* ---------------------- Collision Detection ---------------------- */

		//game.checkCollisions();

		/* ---------------------- Updating ---------------------- */

		if (deltaClock.getElapsedTime() > frameTime) //if the elapsed time is > 1/60th of a second (frametime)
		{
			fTimeSinceUpdate = deltaClock.restart().asSeconds(); //restart the clock

			game.update(fTimeSinceUpdate);
			/*	for (auto collidable : vCollidables)
			{
			collidable->update(fTimeSinceUpdate);
			}*/
		}
		gameView.setCenter(game.getPlayerPos());
		gameWindow.setView(gameView);
		/* ---------------------- Drawing ---------------------- */

		gameWindow.clear(sf::Color::Black);
		/*for (auto collidable : vCollidables)
		{
		gameWindow.draw(*collidable);
		}*/
		/* ---------------------- Display ---------------------- */
	
		gameWindow.draw(game);
		gameWindow.display();

	}


}