
#include "Block.h"

Block::Block()
{
    // Initialisation par défaut du bloc
    // Vous pouvez ajouter du code ici pour initialiser le bloc avec une texture par défaut, etc.
}

Block::Block(const sf::Texture& texture, const sf::Vector2f& position)
    : texture(texture)
{
    shape.setSize(sf::Vector2f(50, 50)); // Ajustez la taille en conséquence
    shape.setTexture(&texture);
    shape.setPosition(position);
}

void Block::setPosition(const sf::Vector2f& position)
{
    shape.setPosition(position);
}

sf::Vector2f Block::getPosition() const
{
    return shape.getPosition();
}

sf::FloatRect Block::getGlobalBounds() const
{
    return shape.getGlobalBounds();
}

void Block::draw(sf::RenderWindow& window) const
{
    window.draw(shape);
}
