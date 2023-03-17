#include "Forces.h"

Forces::Forces(float frictionCoefficient) :
	forceVector(Vector2::ZERO),
	currentSpeed(Vector2::ZERO) {
	this->frictionCoefficient = frictionCoefficient;
}

Forces::~Forces() = default;

void Forces::Update(float delta)
{

	if (GetMagnitude(forceVector) > 0.1f) {
		hasForce = true;
		currentSpeed += -forceVector.normalized() * frictionCoefficient;
	}
	else if (hasForce) {
		hasForce = false;
		forceVector = Vector2::ZERO;
		currentSpeed = Vector2::ZERO;
	}
	forceVector += currentSpeed * delta;
}

void Forces::AddForce(Vector2 speed) {
	currentSpeed = speed;
}

void Forces::Stop()
{
	forceVector = Vector2::ZERO;
	currentSpeed = Vector2::ZERO;
}

float Forces::GetMagnitude(Vector2 vector2)
{
	return Math::sqrt(vector2.x * vector2.x + vector2.y * vector2.y);
}

void Forces::SetFriction(float newFriction)
{
	frictionCoefficient = newFriction;
}
