
#include "simulation.h"
#include "environment.h"

Simulation::Simulation(Environment& env) : env(env){

    update_loop();
    print_map(); 
};


void Simulation::update_loop(){
    env.grow_grass();

};

void Simulation::print_map(){

};