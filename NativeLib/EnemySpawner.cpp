#include "EnemySpawner.h"

void EnemySpawner::_register_methods()
{
	register_method("_ready", &EnemySpawner::_ready);
	register_method("SpawnUnity", &EnemySpawner::SpawnUnit);
	register_method("_process", &EnemySpawner::_process);
	register_method("DeleteUnit", &EnemySpawner::DeleteUnit);

	register_property("despawnHeight", &EnemySpawner::deSpawnHeigt, 0.0f);
	register_property("carsPerSecond", &EnemySpawner::carsPerSecond, 0.0f);
	register_property("increaseDifficultyPerTime", &EnemySpawner::increaseDifficultyPerTime, 0.0f);
	register_property("difficlutyIncreaseAmount", &EnemySpawner::difficlutyIncreaseAmount, 0.0f);
}

void EnemySpawner::_init()
{
	enemyCarVector = vector<Node2D*>();
}

void EnemySpawner::_ready()
{
	enemyCar = cast_to<Node2D>(get_node("EnemyCarNode2D"));
	if (enemyCar != nullptr) Godot::print("found!");
	timePassed = 0;
	totalTimePassed = 0;
	difficultyIncreaseIterator = 1;
}

void EnemySpawner::_process(float delta)
{
	timePassed += delta;
	totalTimePassed += delta;

	// Start spawning units, progressivly gets harder over time
	if (carsPerSecond * timePassed > 1) {
		timePassed = 0;
		SpawnUnit();
	}

	if (totalTimePassed / difficultyIncreaseIterator > increaseDifficultyPerTime) {
		difficultyIncreaseIterator++;
		carsPerSecond += difficlutyIncreaseAmount;
		Godot::print(String::num(carsPerSecond));
	}

	// Iterates trough the list to check if a car should be removed when reaching a certain height
	enemyCarVector.erase(remove_if(enemyCarVector.begin(), enemyCarVector.end(),
		[&](Node2D* element) {
			if (element->get_position().y > deSpawnHeigt) {
				DeleteUnit(element);
				return true;
			}
			return false;
		}), enemyCarVector.end());
}

void EnemySpawner::SpawnUnit()
{
	Node2D* newCar = cast_to<Node2D>(enemyCar->duplicate());
	newCar->set_name("car1");
	newCar->set_position(Vector2(100, 100));
	get_node("/root")->add_child(newCar);
	enemyCarVector.push_back(newCar);
}

void EnemySpawner::DeleteUnit(Node2D* unit)
{
	Godot::print("deleted unit");
	unit->queue_free();
	unit = nullptr;
}
