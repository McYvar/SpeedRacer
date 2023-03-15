#pragma once
#include "Common.h"
#include <Node2D.hpp>
#include "EnemyCars.h"

class EnemySpawner : Node2D
{
	GODOT_CLASS(EnemySpawner, Node2D);

public:
	static void _register_methods();
	void _init();
	void _ready();
	void SpawnUnit();
};

