#include <Player.h>
#include <utilities.h>

Player::Player()
{
	if (!m_Texture.loadFromFile("./assets/Textures/Player/wizard.png"))
	{
		sf::err() << "Wizard not loaded";
	}

	Frames[0].top = 0;
	Frames[0].left = 0;
	Frames[0].width = 60;
	Frames[0].height = 90;

	for (int i = 0; i < 8; i++)
	{
		Frames[i + 1].top = 90;
		Frames[i + 1].left = 60 * i;
		Frames[i + 1].width = 60;
		Frames[i + 1].height = 90;


		Frames[i + 9].top = 180;
		Frames[i + 9].left = 60 * i;
		Frames[i + 9].width = 60;
		Frames[i + 9].height = 90;
	}

	m_Sprite.setTexture(m_Texture);


	m_Sprite.setTextureRect(Frames[9]);
}

void Player::PlayerJump()
{

	impulse(sf::Vector2f(0, -500.0f));
	
}

void Player::update(sf::Vector2f timevector)
{	
	m_Sprite.setPosition(Movable::getPosition());
	Movable::update(timevector);
	//sf::err() << "PlayerPos: " << Movable::getPosition().x << ", " << Movable::getPosition().y << "\n";
	//sf::err() << "SpritePos: " << Collidable::getPosition().x << ", " << Collidable::getPosition().y << "\n";
	//sf::err() << "Velocity: " << Utils::magnitude(m_Velocity) << "\n";

	int iFrame = AnimationTimer.getElapsedTime().asMilliseconds() / 83;
	if (m_Velocity.x > 25.0f)
	{
		m_Sprite.setTextureRect(Frames[(iFrame % 8) + 9]);
	}
	if (m_Velocity.x < -25.0f)
	{
		m_Sprite.setTextureRect(Frames[(7 - (iFrame % 8)) + 1]);
	}

}