
#include "Tilemap.h"

bool Tilemap::IsSolid(sf::Vector2i tile_coord)
{
    if (InBounds(tile_coord))
    {
        return cells[tile_coord.y * TILEMAP_WIDTH + tile_coord.x] == 1;
    }
    return false;
}

bool Tilemap::IsTrap(sf::Vector2i tile_coord)
{
    if (InBounds(tile_coord))
    {
        return cells[tile_coord.y * TILEMAP_WIDTH + tile_coord.x] == 2;
    }
    return false;
}

bool Tilemap::IsDoor(sf::Vector2i tile_coord)
{
    if (InBounds(tile_coord))
    {
        return cells[tile_coord.y * TILEMAP_WIDTH + tile_coord.x] == 3;
    }
    return false;
}

bool Tilemap::IsKey(sf::Vector2i tile_coord)
{
    if (InBounds(tile_coord))
    {
        return cells[tile_coord.y * TILEMAP_WIDTH + tile_coord.x] == 4;
    }
    return false;
}

sf::Vector2i Tilemap::PosToCoords(sf::Vector2f world_position)
{
    return sf::Vector2i(static_cast<int>(world_position.x / TILE_SIZE_PX), static_cast<int>(world_position.y / TILE_SIZE_PX));
}

bool Tilemap::InBounds(sf::Vector2i coords)
{
    return coords.x >= 0 && coords.x < TILEMAP_WIDTH && coords.y >= 0 && coords.y < TILEMAP_HEIGHT;
}

void Tilemap::Save()
{
    FILE* f = fopen("level.data", "wb");
    if (f)
    {
        fwrite(cells, sizeof(cells), 1, f);
        fclose(f);
        std::cout << "Tilemap saved successfully." << std::endl;
    }
    else
    {
        std::cout << "Error saving tilemap." << std::endl;
    }
}

void Tilemap::Load()
{
    FILE* f = nullptr;
    if (fopen_s(&f, "level.data", "rb") == 0)
    {
        fread(cells, sizeof(cells), 1, f);
        fclose(f);
        std::cout << "Tilemap loaded successfully." << std::endl;
    }
    else
    {
        std::cout << "The file level.data does not exist. A new tilemap will be created." << std::endl;
    }
}

void Tilemap::drawSolidBlocks(sf::RenderWindow& window)
{
    for (int i = 0; i < TILEMAP_WIDTH; ++i)
    {
        for (int j = 0; j < TILEMAP_HEIGHT; ++j)
        {
            if (cells[j * TILEMAP_WIDTH + i])
            {
                sf::RectangleShape solid_block(sf::Vector2f(TILE_SIZE_PX, TILE_SIZE_PX));
                solid_block.setPosition(sf::Vector2f(i * TILE_SIZE_PX, j * TILE_SIZE_PX));
                // Dessiner le bloc solide
                window.draw(solid_block);
            }
        }
    }
}
 