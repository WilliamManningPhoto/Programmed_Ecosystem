// Declarations for all entities that exist on the grid
// Entity -> Animal -> Hare/Fox
// Entity -> Plant -> Grass/Tree

#pragma once

// Base class for everything that exists on the grid, holds position data
class Entity {
    public:
        int x, y;  // Position on the grid
        Entity(int x, int y);
        virtual ~Entity() {} // Cleanup for pointer based grid
};

// Base class for rocks
class Rock : public Entity{
    public:
        Rock(int x, int y);
};

// Base class for all animals, holds shared biological data
class Animal : public Entity{
    public:
        int energy; // Energy level, reaches 0 animal dies
        int eating_cooldown; // Steps before animal can eat again
        int reproduction_cooldown; // Steps before animal can reproduce again
        
        Animal(int x, int y, int energy, int eating_cooldown, int reproduction_cooldown);
        virtual void move() = 0; // Each animal defines its own movement
};

// Base class for all plants, holds shared plant data
class Plant : public Entity{
    public:
        int reproduction_cooldown; // Steps before plant can spread again
        Plant(int x, int y, int reproduction_cooldown);
        virtual void plant_reproduction() = 0; // Each plant defines its own spreading
};

// Hare, hunted by foxes, eats grass
class Hare : public Animal {
    public:
        Hare(int x, int y); // Constructor declariations
        void move() override;
};

// Fox, hunts hares
class Fox : public Animal {
    public:
        Fox(int x, int y);
        void move() override;
};

// Grass, eaten by hares, spreads to empty tiles
class Grass : public Plant{
    public:
        Grass(int x, int y);
        void plant_reproduction();
};

// Tree, acts as a moving obstacle, dies of old age
class Tree : public Plant{
    public:
        Tree(int x, int y);
        void plant_reproduction();
};