
// Player.h
#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
    Player();

    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBounds() const;

    void move(const sf::Vector2f& offset);

    void draw(sf::RenderWindow& window) const;

private:
    sf::RectangleShape shape;
    sf::Texture texture;
};


 