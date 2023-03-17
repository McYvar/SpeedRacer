#pragma once
#include "Common.h"
#include <Node2D.hpp>
#include <Input.hpp>
#include <RandomNumberGenerator.hpp>
#include "CarMovement.h"
#include "Forces.h"

class EnemyCars : public Node2D
{
	GODOT_CLASS(EnemyCars, Node2D);
	float movementSpeed = 0;
	float spawnHeight = 0;
	float maxSpawnLeft = 0;
	float maxSpawnRight = 0;
	float friction = 0;

private:
	Ref<RandomNumberGenerator> random;
	Forces myForces;
	float horizontalDirection;

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _process(float delta);

	EnemyCars();
	~EnemyCars();
	void Movement(float delta);

};

