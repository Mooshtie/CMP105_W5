#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	zombTexture.loadFromFile("gfx/animZombie.png");
	zomb.setSize(sf::Vector2f(55, 108));
	zomb.setPosition(100, 100);
	zomb.setTexture(&zombTexture);

	zomb.setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	zomb.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	zomb.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(zomb);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}