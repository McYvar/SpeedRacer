#pragma once
#include "Common.h"
#include <Sprite.hpp>
#include <Input.hpp>
#include <RandomNumberGenerator.hpp>

class EnemyCars : public Sprite
{
	GODOT_CLASS(EnemyCars, Sprite);
	float movementSpeed = 0;
	float spawnHeight = 0;
	float maxSpawnLeft = 0;
	float maxSpawnRight = 0;

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _process(float delta);

	EnemyCars();
	~EnemyCars();
	void Movement(float delta);

private:
	Ref<RandomNumberGenerator> random;
};

