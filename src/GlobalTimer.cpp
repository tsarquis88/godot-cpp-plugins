#include "GlobalTimer.hpp"

using namespace godot;

void GlobalTimer::_register_methods() 
{
    register_method("start_timeout", &GlobalTimer::start_timeout);
    register_method("add_timeout", &GlobalTimer::add_timeout);
    register_method("stop_timeout", &GlobalTimer::stop_timeout);
    register_method("delete_timeout", &GlobalTimer::delete_timeout);
}

GlobalTimer::GlobalTimer() {}

GlobalTimer::~GlobalTimer() {}

void GlobalTimer::_init() {}

Timer* GlobalTimer::add_timeout(Object* target_node, godot::String method, float timeout, bool autostart, bool oneshot)
{
    Timer *timer;

    if(target_node == NULL)
    {
        std::cout << "[ ERR ] GlobalTimer.add_timeout(): target_node is null" << std::endl;
    }
    else if(!target_node->has_method(method))
    {
        std::wcout << "[ ERR ] GlobalTimer.add_timeout(): target_node doesn't have any " << method.unicode_str() << " method" << std::endl;
    }
    else if(timeout <= 0)
    {
        std::cout << "[ ERR ] GlobalTimer.add_timeout(): timeout is less or equal than zero" << std::endl;
    }
    else
    {
        timer = Timer::_new();
        timer->set_one_shot(oneshot);
        timer->set_wait_time(timeout);
        timer->connect("timeout", target_node, method);
        timer->set_autostart(autostart);
        add_child(timer);
    }

	return timer;
}

void GlobalTimer::start_timeout(Timer *timer)
{
    if(timer == NULL)
    {
        std::cout << "[ ERR ] GlobalTimer.start_timeout(): timer is null" << std::endl;
    }
    else
    {
        timer->start();
    }
}

void GlobalTimer::stop_timeout(Timer *timer)
{
    if(timer == NULL)
    {
        std::cout << "[ ERR ] GlobalTimer.stop_timeout(): timer is null" << std::endl;
    }
    else
    {
        timer->stop();
    }
}

void GlobalTimer::delete_timeout(Timer *timer)
{
    if(timer == NULL)
    {
        std::cout << "[ ERR ] GlobalTimer.delete_timeout(): timer is null" << std::endl;
    }
    else
    {
        remove_child(timer);
        timer->queue_free();
    }
}
