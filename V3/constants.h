#pragma once

// All simulation constants in one place easier to tweak and tune behaviour without

// Display of map
const int CELL = 20; // Pixel size of each grid cell
const int MAP_HEIGHT = 800; // Window height in pixels
const int MAP_WIDTH = 1500; // Window width in pixels
const int GRID_SIZE = 100; // Number of cells along each axis

// Timing
const float TIME_INTERVAL = 0.001; // 1000 simulation tick per second
const int SIMULATION_DAYS = 50; // Total days per run; each day is 24 ticks

// Spawn rates of entities ( as fraction of grid)
const float ROCK_MIN = 0.001;
const float ROCK_MAX = 0.005; // Rocks: 0.1% - 0.5% of grid

const float HARE_MIN = 0.05;
const float HARE_MAX = 0.15; // Hares: 5% -15% of grid

const float FOX_MIN = 0.001;
const float FOX_MAX = 0.003; // Foxes: 0.1% - 0.3% of grid

const float TREE_MIN = 0.01;
const float TREE_MAX = 0.02; // Trees: 1% - 2% of grid
