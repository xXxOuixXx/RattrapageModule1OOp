
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Tilemap.h"

class Game
{
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();

    const int window_width = 800;
    const int window_height = 600;

    sf::RenderWindow window;

    // Loading textures
    sf::Texture key_texture;
    sf::Texture door_texture;
    sf::Texture block_texture;
    sf::Texture trap_texture;
    sf::Texture victory_texture;
    sf::Texture defeat_texture;

    // Initialization of the player and game elements
    Player player;
    sf::RectangleShape key;
    sf::RectangleShape door;
    sf::RectangleShape block;
    sf::RectangleShape trap;

    // Initialization of the view
    sf::View view;

    // Initialization of the Tilemap
    Tilemap tilemap;

    
    bool editor_mode = false;

    // Variables for editor modes
    bool trap_mode = false;
    bool door_mode = false;
    bool key_mode = false;
    bool remove_mode = false;
};

