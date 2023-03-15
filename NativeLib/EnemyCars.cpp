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
}

void EnemyCars::_init()
{
}

void EnemyCars::_ready()
{
	random = (godot::Ref<RandomNumberGenerator>)RandomNumberGenerator::_new();
	random->randomize();
	set_position(Vector2(Math::lerp(maxSpawnLeft, maxSpawnRight, random->randf()), spawnHeight));
}

void EnemyCars::_process(float delta)
{
	Movement(delta);
}

EnemyCars::EnemyCars()
{
}

EnemyCars::~EnemyCars()
{
}

void EnemyCars::Movement(float delta)
{
	Vector2 currentPos = get_position();
	set_position(Vector2(currentPos.x, currentPos.y - movementSpeed * delta));
}
