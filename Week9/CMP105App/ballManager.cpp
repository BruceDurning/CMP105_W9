#include "ballManager.h"

ballManager::ballManager()
{
	spawnPoint = sf::Vector2f(350, 250);
	texture.loadFromFile("gfx/Beach_Ball.png");

	for (int i = 0; i < 2000; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(100, 100));
	}
}

ballManager::~ballManager()
{
}

void ballManager::spawn()
{
	for (int i = 0; i < balls.size(); i++) {
		if (!balls[i].isAlive()) {
			balls[i].setAlive(true);
			balls[i].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
			balls[i].setPosition(spawnPoint);
			return;
		}
	}
}

void ballManager::update(float dt)
{
	//call update on all ALIVE balls
	for (int i = 0; i < balls.size(); i++) {
		if (balls[i].isAlive()) {
			balls[i].update(dt);
		}
	}
	deathCheck();
}

void ballManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++) {
		if (balls[i].isAlive()) {
			if (balls[i].getPosition().x < -100) {
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().x > 800) {
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().y < -100) {
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().y > 600) {
				balls[i].setAlive(false);
			}
		}
	}
}

void ballManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < balls.size(); i++) {
		if (balls[i].isAlive()) {
			window->draw(balls[i]);
		}
	}
}
