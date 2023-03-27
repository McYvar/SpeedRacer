#pragma once
#include "Common.h"
#include <Node2D.hpp>
#include "EnemyCars.h"
#include <vector>
#include "ScreenText.h"

class EnemySpawner : public Node2D
{
	GODOT_CLASS(EnemySpawner, Node2D);

	float deSpawnHeigt = 0;
	float carsPerSecond = 0;
	float increaseDifficultyPerTime = 0;
	float difficultyIncreaseAmount = 0;

private:
	Node2D* enemyCar = nullptr;
	vector<Node2D*> enemyCarVector;
	float timePassed = 0;
	float totalTimePassed = 0;
	int difficultyIncreaseIterator = 0;


public:
	static void _register_methods();
	void _init();
	void _ready();
	void _process(float delta);
	void SpawnUnit();
	void DeleteUnit(Node2D* unit) const;
};

