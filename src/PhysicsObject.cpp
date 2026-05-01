#include "PhysicsObject.h"

PhysicsObject::PhysicsObject(float xPosition, float yPosition, bool gravityOn)
	: xPosition(xPosition), yPosition(yPosition), gravityOn(gravityOn)
{
	
}

void PhysicsObject::update(float deltaTime) {
	if (gravityOn)
	{
		yPosition = gravity.applyGravity(yPosition, deltaTime);
	}
	
	

}

