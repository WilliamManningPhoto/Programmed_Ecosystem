// Define the Environment constructor so its initialised
// Definitions for all Environment functions

#include <iostream>
#include <cstdlib> 
#include <cmath>
#include <algorithm>

#include "environment.h"
#include "constants.h"

// Initialise every grid cell to empty, then populate the world
Environment::Environment(){
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            grid[y][x] = nullptr; // Empty cell — no entity present
        }
    }

    terrain_generation();
}

 // Runs placement in order so each stage can rely on the previous one
void Environment::terrain_generation(){
    obstacle_placement();
    plant_placement();
    animal_placement();
}

 // Scatter circular rock clusters across the grid
void Environment::obstacle_placement(){
    int num_clusters = ROCK_MIN * GRID_SIZE * GRID_SIZE + rand() % (int)((ROCK_MAX - ROCK_MIN) * GRID_SIZE * GRID_SIZE);
    for (int i = 0; i < num_clusters; i++){
        int cx = rand() % GRID_SIZE; // Random cluster centre
        int cy = rand() % GRID_SIZE;
        int radius = 3 + rand() % 6; //Each cluster is 3–8 cells in radius
        
        for (int y = cy - radius; y < cy + radius; y++){
            for (int x = cx - radius; x < cx + radius; x++){
                if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE){
                    float dist = sqrt((x-cx)*(x-cx) + (y-cy)*(y-cy));

                    //Use distance check to make clusters circular rather than square
                    if (dist < radius && grid[y][x] == nullptr){
                        Rock* r = new Rock(x, y);
                        rocks.push_back(r);
                        grid[y][x] = r;
                    }
                }
            }
        }
    }
}

 // Fill all empty tiles with grass, then replace a random subset with trees
void Environment::plant_placement(){
    int tree_amount = TREE_MIN * GRID_SIZE * GRID_SIZE + rand() % (int)((TREE_MAX - TREE_MIN) * GRID_SIZE * GRID_SIZE);

    //Grass fills every tile not already occupied by a rock
    for (int y = 0; y < GRID_SIZE; y++){
        for (int x = 0; x < GRID_SIZE; x++){
            if (grid[y][x] == nullptr){
                Grass* g = new Grass(x, y);
                grass.push_back(g);
                grid[y][x] = g;
            }
        }
    }

    //Place trees on randomly chosen grass tiles, removing the grass underneath
    for (int i = 0; i < tree_amount; i++){
        Grass* g = grass[rand() % grass.size()];
        int x = g->x;
        int y = g->y;

        Tree* t = new Tree(x, y);
        trees.push_back(t);
        grid[y][x] = t;

        grass.erase(std::find(grass.begin(), grass.end(), g)); // Erasure of grass under tree
    }
}

// Spawn hares and foxes on randomly chosen grass tile
// Animals placed directly on grass
void Environment::animal_placement(){
    int hare_amount = HARE_MIN * GRID_SIZE * GRID_SIZE + rand() % (int)((HARE_MAX - HARE_MIN) * GRID_SIZE * GRID_SIZE);
    int fox_amount = FOX_MIN * GRID_SIZE * GRID_SIZE + rand() % (int)((FOX_MAX - FOX_MIN) * GRID_SIZE * GRID_SIZE);

    for (int i = 0; i < hare_amount; i++){
        Grass* g = grass[rand() % grass.size()];
        int x = g->x;
        int y = g->y;

        Hare* h = new Hare(x, y);
        hares.push_back(h);
        h->standing_on = g;
        grid[y][x] = h; // Overwrites grass pointer on the grid
    }
    for (int i = 0; i < fox_amount; i++){
        Grass* g = grass[rand() % grass.size()];
        int x = g->x;
        int y = g->y;

        Fox* f = new Fox(x, y);
        foxes.push_back(f);
        f->standing_on = g;
        grid[y][x] = f;
    }
}

// If entity dies remove from game
void Environment::entity_removal(Hare* hare){
    if (grid[hare->y][hare->x] == hare) {
        grid[hare->y][hare->x] = hare->standing_on;
    }
    hares.erase(std::find(hares.begin(), hares.end(), hare));
    delete hare;
}

// Growth of grass
void Environment::grow_grass(){

}
