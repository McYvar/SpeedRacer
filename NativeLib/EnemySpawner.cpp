#include "EnemySpawner.h"

void EnemySpawner::_register_methods()
{
	register_method("_ready", &EnemySpawner::_ready);
	register_method("SpawnUnity", &EnemySpawner::SpawnUnit);
}

void EnemySpawner::_init()
{
}

void EnemySpawner::_ready()
{
}

void EnemySpawner::SpawnUnit()
{

}
