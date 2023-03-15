#pragma once
#include "Common.h"
#include <Node2D.hpp>
#include "EnemyCars.h"
#include <vector>

class EnemySpawner : public Node2D
{
	GODOT_CLASS(EnemySpawner, Node2D);

	float deSpawnHeigt;
	float carsPerSecond;
	float increaseDifficultyPerTime;
	float difficlutyIncreaseAmount;

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _process(float delta);
	void SpawnUnit();
	void DeleteUnit(Node2D* unit);

private:
	Node2D* enemyCar;
	vector<Node2D*> enemyCarVector;
	float timePassed;
	float totalTimePassed;
	int difficultyIncreaseIterator;
};

