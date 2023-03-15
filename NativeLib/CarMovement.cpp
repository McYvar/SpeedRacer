#include "CarMovement.h"

bool CarMovement::crashed = false;

void CarMovement::_register_methods()
{
	register_method("_ready", &CarMovement::_ready);
	register_method("_process", &CarMovement::_process);
	register_method("Movement", &CarMovement::Movement);

	register_property("movementSpeed", &CarMovement::movementSpeed, 0.0f);
	register_property("borderLeft", &CarMovement::borderLeft, 0.0f);
	register_property("borderRight", &CarMovement::borderRight, 0.0f);
}

void CarMovement::_init()
{
	crashed = false;
}

void CarMovement::_ready()
{
}

void CarMovement::_process(float delta)
{
	if (!crashed)
	Movement(delta);
}

CarMovement::CarMovement()
{
}

CarMovement::~CarMovement()
{
}

void CarMovement::Movement(float delta)
{
	float movementDirection = 0;

	Input& inputSingleton = *Input::get_singleton();

	if (inputSingleton.is_action_pressed("ui_right")) {
		movementDirection += 1;
	}
	if (inputSingleton.is_action_pressed("ui_left")) {
		movementDirection -= 1;
	}

	Vector2 currentPos = get_position();
	set_position(Vector2(Math::clamp<float>(currentPos.x + movementDirection * movementSpeed * delta, borderLeft, borderRight), currentPos.y));
}

void CarMovement::CrashCar()
{
	Godot::print("Chrased!");
	crashed = true;
}
