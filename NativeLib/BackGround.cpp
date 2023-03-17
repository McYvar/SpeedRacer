#include "BackGround.h"
#include "CarMovement.h"

void BackGround::_register_methods()
{
	register_method("_process", &BackGround::_process);
	register_method("_ready", &BackGround::_ready);

	register_property("respawnHeight", &BackGround::respawnHeight, 0.0f);
	register_property("despawnHeight", &BackGround::despawnHeight, 0.0f);
}

void BackGround::_init()
{
}

void BackGround::_process(float delta)
{
	if (CarMovement::crashed) return;
	if (get_position().y > despawnHeight) {
		set_position(Vector2(get_position().x, respawnHeight));
	}

	myForces.AddForce(Vector2(0, 0.1f));
	myForces.Update(delta);
	set_position(get_position() + myForces.forceVector);
}

void BackGround::_ready()
{
	myForces.forceVector = Vector2(0, 10);
}

BackGround::BackGround() : myForces(Forces(0))
{
}

BackGround::~BackGround() = default;
