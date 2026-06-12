#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <string>

#include "environment.h"
#include "renderer.h"
#include "simulation.h"

int main() {
    srand(time(0)); // Seed random number generator with current time so each run produces different results
    
    Environment env; // Build the world: grid, rocks, plants, animals
    Simulation sim(env); // Attach simulation logic to the environment
    
    // Create the window at the fixed resolution the grid is designed for
    sf::RenderWindow window(sf::VideoMode(1500, 800), "Ecosystem_Simulator"); // Render the window with a 800 by 1500 pixel space

    // Clock used to control how often the simulation updates, independent of frame rate
    sf::Clock clock;

    while (window.isOpen()) {

        // Handle OS events (moving window, pressing X to close, etc.)
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); // X to close
        }

        // Rendering of window
        window.clear(sf::Color::Black);// Wipe last frame before drawing the new one
        draw_grid(window); // Draw the background grid lines
        draw_entities(window, env); // Draw all rocks, plants, and animals on top

        // Simulation running
        if (clock.getElapsedTime().asSeconds() >= TIME_INTERVAL) {
            clock.restart();
            if (sim.running) {
                sim.update_loop(); // Update current loop by 1 step
            }
}
        window.display(); // Push the finished frame to the screen
    }
}