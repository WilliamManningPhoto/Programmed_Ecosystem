#pragma once

#include "entities.h"
#include "environment.h"

class Simulation{
    public:
        Environment& env;
        Simulation(Environment& env);

    void update_loop();

    void print_map();
};