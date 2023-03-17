#pragma once
#include "Common.h"
#include <Sprite.hpp>
#include <Input.hpp>
#include "Forces.h"

class CarMovement : public Node2D
{
	GODOT_CLASS(CarMovement, Node2D);

	float movementSpeed = 0;
	float borderLeft = 0;
	float borderRight = 0;
	float friction = 0;
	float maxSpeed = 0;

private:
	Forces myForce;

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _process(float delta);
	CarMovement();
	~CarMovement();
	void Movement(float delta);
	static void CrashCar();
	static bool crashed;
	float GetMagnitude(Vector2 vector2);
};

