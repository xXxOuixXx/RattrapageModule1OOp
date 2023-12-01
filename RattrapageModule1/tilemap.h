
#pragma once

#include <SFML/Graphics.hpp> 
#define TILEMAP_WIDTH 30
#define TILEMAP_HEIGHT 26
#define TILE_SIZE_PX 50

class Tilemap
{
public:
    char cells[TILEMAP_WIDTH * TILEMAP_HEIGHT] = { 0 };

    bool InBounds(sf::Vector2i coords);
    void Save();
    void Load();
    sf::Vector2i PosToCoords(sf::Vector2f world_position);
    bool TileAt(sf::Vector2i tile_coord);
    bool IsSolid(sf::Vector2i tile_coord);
    bool IsTrap(sf::Vector2i tile_coord);
    bool IsDoor(sf::Vector2i tile_coord);
    bool IsKey(sf::Vector2i tile_coord);
    void drawSolidBlocks(sf::RenderWindow& window);
};
