#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	
	// initialise game objects

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space)) {
		//ball.handleInput(dt);
		manager.spawn();
	}
}

// Update game objects
void Level::update(float dt)
{
	//ball.update(dt);
	manager.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	//window->draw(ball);
	manager.render(window);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}