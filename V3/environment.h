#include <vector>

#include "entities.h"

class Environment{
    public: // Public so other functions can access
        Entity* grid[100][100];

        // Vectors (lists)
        std::vector<Hare*> hares;
        std::vector<Fox*> foxes;
        std::vector<Grass*> grass;
        std::vector<Tree*> trees;
        std::vector<Rock*> rocks;

    void terrain_generation(

    );

    void obstacle_placement(

    );

    void plant_placement(

    );

    void animal_placement(
        
    );

    void entity_removal(

    );
};
