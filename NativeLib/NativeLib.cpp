#include "Common.h"
#include "CarMovement.h"
#include "EnemyCars.h"
#include "CollisionDetector.h"
#include "EnemySpawner.h"


extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options * o)
{
    Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options * o)
{
    Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void* handle)
{
    Godot::nativescript_init(handle);

    register_class<CarMovement>();
    register_class<EnemyCars>();
    register_class<CollisionDetector>();
    register_class<EnemySpawner>();
}