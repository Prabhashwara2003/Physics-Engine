#include "PhysicsObject.h"

PhysicsObject::PhysicsObject(float xPosition, float yPosition)
	: xPosition(xPosition), yPosition(yPosition)
{

}

void PhysicsObject::update(float deltaTime) {
	Gravity gravity;
	yPosition = gravity.applyGravity(yPosition, deltaTime);

}

