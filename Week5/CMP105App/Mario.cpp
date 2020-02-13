#include "Mario.h"

Mario::Mario()
{
	//set up walk animation
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));
	walk.setFrameSpeed(1.f / 10.f);

	//set up stationary animation
	duck.addFrame(sf::IntRect(0, 41, 16, 20));
	duck.addFrame(sf::IntRect(16, 41, 16, 20));
	duck.setFrameSpeed(1.f / 5.f);

	//set up Swimming animation
	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	swim.setFrameSpeed(1.f / 10.f);
}

void Mario::update(float dt)
{
	duck.animate(dt);
	setTextureRect(duck.getCurrentFrame());

	if (input->isKeyDown(sf::Keyboard::D) || input->isKeyDown(sf::Keyboard::A))
	{
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}

	if (input->isKeyDown(sf::Keyboard::S) || input->isKeyDown(sf::Keyboard::W))
	{
		swim.animate(dt);
		setTextureRect(swim.getCurrentFrame());
	}
}

void Mario::handleInput(float dt)
{
	//walking
	if (input->isKeyDown(sf::Keyboard::D))
	{
		walk.setPlaying(true);
		walk.setFlipped(false);
		setVelocity(200.f, 0.f);
		move(getVelocity() * dt);
	}
	else if (input->isKeyDown(sf::Keyboard::A))
	{
		walk.setPlaying(true);
		walk.setFlipped(true);
		setVelocity(-200.f, 0.f);
		move(getVelocity() * dt);
	}
	else
	{
		walk.reset();
	}

	//swimming
	if (walk.getFlipped() == true)
	{
		swim.setFlipped(true);
	}
	else
	{
		swim.setFlipped(false);
	}

	if (input->isKeyDown(sf::Keyboard::S))
	{
		swim.setPlaying(true);
		setVelocity(0.f, 200.f);
		move(getVelocity() * dt);
	}
	else if (input->isKeyDown(sf::Keyboard::W))
	{
		swim.setPlaying(true);
		setVelocity(0.f, -200.f);
		move(getVelocity() * dt);
	}
	else
	{
		swim.reset();
	}

	//duck
	if (walk.getFlipped() == true)
	{
		duck.setFlipped(true);
	}
	else
	{
		duck.setFlipped(false);
	}
}

Mario::~Mario()
{
}