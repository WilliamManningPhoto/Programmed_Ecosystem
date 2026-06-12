// Definitions for all entity constructors
// Each class passes shared data up the inheritance chain

#include <algorithm> // Utilising std::max

#include "entities.h"
#include "environment.h"

// Base entity constructor, sets position for all entities on the grid
Entity::Entity(int x, int y){
    this->x = x;
    this->y = y;
}

// Rock constructor setup to pass to Entity
Rock::Rock(int x, int y) : Entity(x, y){

}

// Animal constructor, passes position up to Entity then sets animal specific values
Animal::Animal(int x, int y, int energy, int eating_cooldown, int reproduction_cooldown) : Entity(x, y){
    this->energy = energy;
    this->eating_cooldown = eating_cooldown;
    this->reproduction_cooldown = reproduction_cooldown;
    this->standing_on = nullptr;
}

// Hare passes position and its fixed stats up to Animal
Hare::Hare(int x, int y) : Animal(x, y, 25, 2, 2) {

}

// Hare movement
void Hare::move(Environment& env){
    energy -= 1; // Burn energy each tick
    eating_cooldown = std::max(0, eating_cooldown - 1); // Count down, floor at 0
    reproduction_cooldown = std::max(0, reproduction_cooldown - 1);

    // Pick a random cardinal direction
    int directions[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int dir = rand() % 4;
    int dx = directions[dir][0];
    int dy = directions[dir][1];

    int new_x = x + dx;
    int new_y = y + dy;

    // Only move if the target tile is in bounds and is empty or grass (hares don't displace other entities)
    if (new_x >= 0 && new_x < GRID_SIZE && new_y >= 0 && new_y < GRID_SIZE){
        if (env.grid[new_y][new_x] == nullptr || dynamic_cast<Grass*>(env.grid[new_y][new_x])){

            env.grid[y][x] = standing_on;
            x = new_x;
            y = new_y;
            standing_on = env.grid[new_y][new_x];
            env.grid[new_y][new_x] = this;

        }
    }

    if (dynamic_cast<Grass*>(standing_on) != nullptr){
        if (eating_cooldown == 0){
            
            Grass* eaten = dynamic_cast<Grass*>(standing_on);
            for (auto& h : env.hares) {
                if (h->standing_on == eaten) {
                    h->standing_on = nullptr;
                }
            }

            energy += 15;
            env.grass.erase(std::find(env.grass.begin(), env.grass.end(), dynamic_cast<Grass*>(standing_on)));
            delete dynamic_cast<Grass*>(standing_on);
            standing_on = nullptr;
            eating_cooldown = 2;
        }
    }

}

// FOX passes position and its fixed stats up to Animal
Fox::Fox(int x, int y) : Animal(x, y, 50, 6, 36) {

}

void Fox::move(Environment& env){

}

// Plant constructor, passes position up to Entity then sets plant specific values
Plant::Plant(int x, int y, int reproduction_cooldown) : Entity(x, y){
    this->reproduction_cooldown = reproduction_cooldown;
}

// Grass passes position and its reproduction rate up to Plant
Grass::Grass(int x, int y) : Plant(x, y, 1){

}

void Grass::plant_reproduction(){

}

// Tree passes position and its reproduction rate up to Plant
Tree::Tree(int x, int y) : Plant(x, y, 1){

}

void Tree::plant_reproduction(){

}