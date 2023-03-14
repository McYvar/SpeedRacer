#pragma once
#include "Common.h"
#include <Sprite.hpp>
#include <Input.hpp>

class CarMovement : public Sprite
{
	GODOT_CLASS(CarMovement, Sprite);

	float movementSpeed = 0;

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _process(float delta);
};

