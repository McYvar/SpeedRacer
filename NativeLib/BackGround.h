#pragma once
#include "Common.h"
#include "Forces.h"
#include <Node2D.hpp>

class BackGround : public Node2D
{
	GODOT_CLASS(BackGround, Node2D);

	float respawnHeight;
	float despawnHeight;

private:
	Forces myForces;

public:
	static void _register_methods();
	void _init();
	void _process(float delta);
	void _ready();
	BackGround();
	~BackGround();
};
