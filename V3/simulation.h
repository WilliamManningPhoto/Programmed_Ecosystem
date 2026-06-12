#pragma once

#include "entities.h"
#include "environment.h"

// Owns the simulation lifecycle
class Simulation{
    public:
        int step; // Current tick count since simulation started
        bool running;

        Environment& env; // Reference to the world this simulation operates on
        Simulation(Environment& env); // Constructor binds simulation to an existing environment

        void update_loop(); // Advance the simulation by one tick: move animals, grow plants, handle deaths
};