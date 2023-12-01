
#include "Game.h"
const int window_width = 800;
const int window_height = 600;
const int initial_lives = 3;

Game::Game() : window(sf::VideoMode(window_width, window_height), "Dungeon Crawler"),
player ("player.png", sf::Vector2f(23 * TILE_SIZE_PX, 23 * TILE_SIZE_PX)),
key_texture(), door_texture(), block_texture(), trap_texture(),
key (sf::Vector2f(21 * TILE_SIZE_PX, 7 * TILE_SIZE_PX), &key_texture),
door (sf::Vector2f(8 * TILE_SIZE_PX, 8 * TILE_SIZE_PX), &door_texture),
block (sf::Vector2f(20 * TILE_SIZE_PX, 9 * TILE_SIZE_PX), &block_texture),
trap (sf::Vector2f(20 * TILE_SIZE_PX, 9 * TILE_SIZE_PX), &trap_texture)
{
    // Charger les textures ici
    if (!key_texture.loadFromFile("clee.png") ||
        !door_texture.loadFromFile("door.png") ||
        !block_texture.loadFromFile("mur.png") ||
        !trap_texture.loadFromFile("traps.png") ||
        !victory_texture.loadFromFile("victory.png") ||
        !defeat_texture.loadFromFile("defeat.png"))
    {
        std::cout << "Erreur de chargement des textures." << std::endl;
        // Gérer l'erreur de chargement des textures ici
    }

    // Initialiser d'autres éléments du jeu ici
    // ...
}

void Game::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        player.processEvent(event, tilemap, view);
    }
}

void Game::update()
{
    // Mise à jour de l'état du jeu ici
    // ...

    player.update(tilemap, view);

    // Check if the player is on a key tile
    if (player.getGlobalBounds().intersects(key.getGlobalBounds()))
    {
        door.setPosition(sf::Vector2f(10 * TILE_SIZE_PX, 1 * TILE_SIZE_PX));
        player.setHasKey(true);
    }

    // Check if the player is on a door tile and has the key
    if (player.hasKey() && player.getGlobalBounds().intersects(door.getGlobalBounds()))
    {
        // Afficher la victoire
        sf::Sprite victorySprite(victory_texture); 
        window.draw(victorySprite);
        window.display();
        sf::sleep(sf::seconds(2));
        window.close();
    }

    // Check player is on a block tile
    if (player.getGlobalBounds().intersects(block.getGlobalBounds()))
    {
        // Le joueur a marché sur un bloc qui enlève une vie
        player.removeLife();
        player.setPosition(player.getInitialPosition());

        if (player.getRemainingLives() <= 0)
        {
            // Game over
            std::cout << "Défaite, vous n'avez plus de vies." << std::endl;
            window.close();
        }
    }

    view.setCenter(player.getPosition());
    window.setView(view);
}

void Game::render()
{
    window.clear();

    sf::RectangleShape background(sf::Vector2f(TILEMAP_WIDTH * TILE_SIZE_PX, TILEMAP_HEIGHT * TILE_SIZE_PX));
    background.setFillColor(sf::Color(30, 30, 30));
    window.draw(background);

    window.draw(player);
    window.draw(key);
    window.draw(door);

    // Dessiner les blocs solides
    tilemap.drawSolidBlocks(window);

    window.draw(block);
    window.draw(trap);

    window.display();
}