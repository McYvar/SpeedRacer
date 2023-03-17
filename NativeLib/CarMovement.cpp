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
	register_property("friction", &CarMovement::friction, 0.0f);
	register_property("maxSpeed", &CarMovement::maxSpeed, 0.0f);
}

void CarMovement::_init()
{
	crashed = false;
}

void CarMovement::_ready()
{
	myForce.SetFriction(friction);
}

void CarMovement::_process(float delta)
{
	if (!crashed)
	Movement(delta);
}

CarMovement::CarMovement() : myForce(Forces(friction))
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
	myForce.AddForce(Vector2(movementDirection * movementSpeed, 0));
	myForce.Update(delta);
	
	if (get_position().x < borderLeft) {
		set_position(Vector2(borderLeft, get_position().y));
		myForce.Stop();
	}
	else if (get_position().x > borderRight) {
		set_position(Vector2(borderRight, get_position().y));
		myForce.Stop();
	}
	else {
		set_position(get_position() + myForce.forceVector);
	}


}

void CarMovement::CrashCar()
{
	Godot::print("Crashed!");
	crashed = true;
}

float CarMovement::GetMagnitude(Vector2 vector2)
{
	return Math::sqrt(vector2.x * vector2.x + vector2.y * vector2.y);
}
