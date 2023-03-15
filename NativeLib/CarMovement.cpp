#include "CarMovement.h"

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
}

void CarMovement::_ready()
{
}

void CarMovement::_process(float delta)
{
	Movement(delta);
}

void CarMovement::Movement(float delta)
{
	float movementDirection = 0;

	Input& intutSingleton = *Input::get_singleton();

	if (intutSingleton.is_action_pressed("ui_right")) {
		movementDirection += 1;
	}
	if (intutSingleton.is_action_pressed("ui_left")) {
		movementDirection -= 1;
	}

	Vector2 currentPos = get_position();
	set_position(Vector2(Math::clamp<float>(currentPos.x + movementDirection * movementSpeed * delta, borderLeft, borderRight), currentPos.y));
}
