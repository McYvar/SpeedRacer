#pragma once
#include "Common.h"
#include <Control.hpp>
#include <RichTextLabel.hpp>
#include "CarMovement.h"

class ScreenText : public Control
{
	GODOT_CLASS(ScreenText, Control);

private:
	RichTextLabel* score;
	RichTextLabel* youLose;
	static int totalScore;

public:
	static void _register_methods();
	void _init();
	void _ready();
	void _process(float delta);
	static void addOneToScore();
};

