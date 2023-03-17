#pragma once
#include "Common.h"

class Forces
{
private:
	Vector2 currentSpeed;
	float frictionCoefficient;
	bool hasForce = false;

public:
	Forces(float frictionCoefficient);
	~Forces();
	void Update(float delta);
	void AddForce(Vector2 acceleration);
	void Stop();
	float GetMagnitude(Vector2 vector2);
	void SetFriction(float newFriction);
	Vector2 forceVector;

};

