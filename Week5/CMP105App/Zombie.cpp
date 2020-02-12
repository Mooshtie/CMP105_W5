#include "Zombie.h"

Zombie::Zombie()
{
	//set up walk animation
	walk.addFrame(sf::IntRect(0, 0, 55, 100));
	walk.addFrame(sf::IntRect(55, 0, 55, 100));
	walk.addFrame(sf::IntRect(110, 0, 55, 100));
	walk.addFrame(sf::IntRect(165, 0, 55, 100));
	walk.addFrame(sf::IntRect(220, 0, 55, 100));
	walk.addFrame(sf::IntRect(275, 0, 55, 100));
	walk.addFrame(sf::IntRect(330, 0, 55, 100));
	walk.addFrame(sf::IntRect(385, 0, 55, 100));
	walk.setFrameSpeed(1.f / 10.f);
}

void Zombie::update(float dt)
{
	walk.animate(dt);
	setTextureRect(walk.getCurrentFrame());
}

void Zombie::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		walk.play(true);
		walk.setFlipped(false);
		setVelocity(200.f, 0.f);
		move(getVelocity() * dt);
	}
	else if (input->isKeyDown(sf::Keyboard::Left))
	{
		walk.play(true);
		walk.setFlipped(true);
		setVelocity(-200.f, 0.f);
		move(getVelocity() * dt);
	}
	else if (input->isKeyDown(sf::Keyboard::Down))
	{
		walk.play(true);
		setVelocity(0.f, 200.f);
		move(getVelocity() * dt);
	}
	else if (input->isKeyDown(sf::Keyboard::Up))
	{
		walk.play(true);
		setVelocity(0.f, -200.f);
		move(getVelocity() * dt);
	}
	else
	{
		walk.pause();
	}
}

Zombie::~Zombie()
{
}