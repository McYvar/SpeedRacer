#include "EnemyCars.h"

void EnemyCars::_register_methods()
{
	register_method("_ready", &EnemyCars::_ready);
	register_method("_process", &EnemyCars::_process);
	register_method("Movement", &EnemyCars::Movement);

	register_property("movementSpeed", &EnemyCars::movementSpeed, 0.0f);
	register_property("spawnHeight", &EnemyCars::spawnHeight, 0.0f);
	register_property("maxSpawnLeft", &EnemyCars::maxSpawnLeft, 0.0f);
	register_property("maxSpawnRight", &EnemyCars::maxSpawnRight, 0.0f);
	register_property("friction", &EnemyCars::friction, 0.0f);
}

void EnemyCars::_init()
{
}

void EnemyCars::_ready()
{
	random = (godot::Ref<RandomNumberGenerator>)RandomNumberGenerator::_new();
	random->randomize();
	set_position(Vector2(Math::lerp(maxSpawnLeft, maxSpawnRight, random->randf()), spawnHeight));

	random->randomize();
	horizontalDirection = Math::lerp(-4, 4, random->randf());
	Godot::print(String::num(horizontalDirection));

	myForces.SetFriction(friction);
}

void EnemyCars::_process(float delta)
{
	if (!CarMovement::crashed || get_position().y > 650)
	Movement(delta);
}

EnemyCars::EnemyCars() : myForces(Forces(0))
{
}

EnemyCars::~EnemyCars()
{
}

void EnemyCars::Movement(float delta)
{
	if (get_position().x < maxSpawnLeft) {
		horizontalDirection *= -1;
		set_position(Vector2(maxSpawnLeft, get_position().y));
		myForces.forceVector = Vector2(0, myForces.forceVector.y);
	}
	else if (get_position().x > maxSpawnRight) {
		horizontalDirection *= -1;
		set_position(Vector2(maxSpawnRight, get_position().y));
		myForces.forceVector = Vector2(0, myForces.forceVector.y);
	}

	myForces.AddForce(Vector2(horizontalDirection, movementSpeed));
	myForces.Update(delta);
	set_position(get_position() + myForces.forceVector);
}
