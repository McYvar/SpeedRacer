#include "CollisionDetector.h"

void CollisionDetector::_register_methods() {
    register_method("_ready", &CollisionDetector::_ready);
    register_method("_on_area_entered", &CollisionDetector::_on_area_entered);
    register_method("_on_area_exited", &CollisionDetector::_on_area_exited);
}

void CollisionDetector::_init() {
}

void CollisionDetector::_ready() {
    area = cast_to<Area2D>(get_node("Area2D"));
    if (area != NULL) {
        Godot::print("Area was found!");
        area->connect("area_entered", this, "_on_area_entered");
        area->connect("area_exited", this, "_on_area_exited");
    }
    else Godot::print("Area wasn't found!");

}


void CollisionDetector::_on_area_entered(Area2D* area) {
    // Collision detected, do something
    Godot::print("Collision detected!");
    CarMovement::CrashCar();
}

void CollisionDetector::_on_area_exited(Area2D* area) {
}
