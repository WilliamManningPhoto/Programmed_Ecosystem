#include <iostream>

#include "simulation.h"
#include "environment.h"
#include "entities.h"

// Bind simulation to the provided environment, start at tick 0 with simulation running
Simulation::Simulation(Environment& env) : env(env), step(0), running(true){};

void Simulation::update_loop(){

    // Spread grass into adjacent empty tiles each tick
    env.grow_grass();

    // Advance every hare: move, eat, reproduce, age
    for (auto& hare : env.hares) {
        hare->move(env);
    }

    step++;

    // Stop the simulation once the total number of ticks has been reached (days * 24 ticks/day)
    if (step >= SIMULATION_DAYS * 24) {
        running = false;
    }
    std::cout << "Step: " << step << std::endl;
};
