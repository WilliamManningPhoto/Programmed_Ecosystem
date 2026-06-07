# Ecosystem Simulator

A Python-based predator-prey ecosystem simulator that models interactions between grass, rabbits, and foxes on a 2D grid.

The simulation demonstrates population dynamics, resource competition, reproduction, predation, and extinction events. Population data is recorded over time and visualized using Matplotlib.

## Features

* Grid-based ecosystem simulation
* Terrain generation
* Grass growth and spreading
* Rabbit foraging behavior
* Fox hunting behavior with escape mechanics
* Energy-based survival system
* Reproduction with configurable cooldowns
* Population tracking over time
* Automatic graph generation

## Species

### Grass

* Spreads into adjacent empty cells
* Serves as the food source for rabbits

### Rabbits

* Search for nearby grass
* Gain energy by eating grass
* Lose energy each timestep
* Reproduce when energy requirements are met
* Die when energy reaches zero

### Foxes

* Search for nearby rabbits
* Gain energy by successfully hunting rabbits
* Hunting includes a chance for prey to escape
* Lose energy each timestep
* Reproduce when energy requirements are met
* Die when energy reaches zero

## Requirements

* Python 3.x
* Matplotlib

Install dependencies:

```bash
pip install matplotlib
```

You will be prompted to enter the world size:

```text
Enter the size of the world: (35 is for the best!)
```

The simulation will run for a fixed number of timesteps and display a graph showing population changes over time.

## Example Population Graph
<img width="1000" height="600" alt="Picture of simulation" src="https://github.com/user-attachments/assets/02297751-a120-4423-b313-2218d98b1b1a" />




This allows you to observe predator-prey cycles, ecosystem stability, and extinction events. ( It will crash from unstable ecosystem :) )

## Simulation Mechanics

### Reproduction

Animals reproduce when:

* Their energy exceeds a species-specific threshold
* Their reproduction cooldown has expired
* An adjacent cell is available

After reproduction:

* Energy is reduced
* A cooldown is applied

## License

This project is open source and available under the MIT License.
