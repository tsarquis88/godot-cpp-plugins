#ifndef GLOBALTIMER_H
#define GLOBALTIMER_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <Timer.hpp>

#include <iostream>

namespace godot {

class GlobalTimer : public Node2D {
    GODOT_CLASS(GlobalTimer, Node2D)

private:

public:
    static void _register_methods();

    GlobalTimer();
    ~GlobalTimer();

    void _init();
    Timer* add_timeout(Object*, godot::String, float, bool, bool);
    void start_timeout(Timer*);
    void stop_timeout(Timer*);
    void delete_timeout(Timer*);
};

}

#endif
