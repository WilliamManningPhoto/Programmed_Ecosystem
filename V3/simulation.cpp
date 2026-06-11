
#include "simulation.h"
#include "environment.h"
#include "entities.h"

Simulation::Simulation(Environment& env) : env(env){

    update_loop();
    print_map(); 
};


void Simulation::update_loop(){
    env.grow_grass();
    for (auto& hare : env.hares) {
        hare->move(env);
    }
};

void Simulation::print_map(){

};