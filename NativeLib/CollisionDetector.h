#pragma once
#include "Common.h"
#include <Area2D.hpp>
#include <KinematicBody2D.hpp>

namespace godot {

    class CollisionDetector : public Node2D {
        GODOT_CLASS(CollisionDetector, Node2D);

    private:
        Area2D* area;

    public:
        static void _register_methods();
        void _init();
        void _ready();
        void _on_area_entered(Area2D* area);
        void _on_area_exited(Area2D* area);
    };

}