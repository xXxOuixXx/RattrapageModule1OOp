
#pragma once

#include <SFML/Graphics.hpp>

class Block
{
public:
    Block();
    Block(const sf::Texture& texture, const sf::Vector2f& position);

    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBounds() const;
    void draw(sf::RenderWindow& window) const;

private:
    sf::RectangleShape shape;
    sf::Texture texture;
};
