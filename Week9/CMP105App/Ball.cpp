#include "Ball.h"
#include <math.h>
#include <ctime>
Ball::Ball() {

}

Ball::~Ball()
{
}

void Ball::update(float dt) {
	move(velocity * dt);
}