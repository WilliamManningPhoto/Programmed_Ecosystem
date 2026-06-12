#pragma once

#include <vector>

#include "entities.h"
#include "constants.h"

// Owns the world state: the grid, all entity lists, and the logic to populate and update them
class Environment{
    public:
        // 2D grid of raw pointers, each cell holds one entity or nullptr if empty
        Entity* grid[GRID_SIZE][GRID_SIZE];

        // Per-type lists for fast iteration (avoids scanning the whole grid each tick)
        std::vector<Hare*> hares;
        std::vector<Fox*> foxes;
        std::vector<Grass*> grass;
        std::vector<Tree*> trees;
        std::vector<Rock*> rocks;

        Environment(); // Initialises grid to nullptr and calls terrain_generation

    void terrain_generation();

    void obstacle_placement();

    void plant_placement();

    void animal_placement();

    void entity_removal();

    void grow_grass();
};
