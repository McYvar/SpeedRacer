#include "ScreenText.h"

int ScreenText::totalScore = 0;

void ScreenText::_register_methods()
{
	register_method("_process", &ScreenText::_process);
	register_method("_ready", &ScreenText::_ready);
}

void ScreenText::_init()
{
	totalScore = 0;
}

void ScreenText::_ready()
{
	youLose = cast_to<RichTextLabel>(get_node("Lose"));
	youLose->set_text("");
	score = cast_to<RichTextLabel>(get_node("Score"));
}

void ScreenText::_process(float delta)
{
	if (CarMovement::crashed) {
		youLose->set_text("You lost!\nFinal score: " + String::num(totalScore));
	}
	else {
		score->set_text("Score: " + String::num(totalScore));
	}
}

void ScreenText::addOneToScore()
{
	totalScore++;
}
