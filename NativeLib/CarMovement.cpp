#include "CarMovement.h"

void CarMovement::_register_methods()
{
	register_method("_ready", &CarMovement::_ready);
	register_method("_process", &CarMovement::_process);

	register_property("movementSpeed", &CarMovement::movementSpeed, 0.0f);
}

void CarMovement::_init()
{
}

void CarMovement::_ready()
{
}

void CarMovement::_process(float delta)
{
	float movementDirection = 0;
	
	Input& intutSingleton = *Input::get_singleton();

	if (intutSingleton.is_action_pressed("ui_right")) {
		movementDirection += 1;
	}
	if (intutSingleton.is_action_pressed("ui_left")) {
		movementDirection -= 1;
	}

	set_position(get_position() + Vector2(movementDirection * delta * movementSpeed, -1 * delta));
}
