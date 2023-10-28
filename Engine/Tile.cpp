//
// Created by shubhra on 21/10/23.
//

#include "Tile.hpp"

Tile::Tile() : Rect()
{}

Tile::Tile(int x, int y, int width, int height, const sf::Color &color) :
    Rect(x, y, width, height), m_Shape(Vector2f (width, height))
{
    m_Shape.setPosition(x, y);
    m_Shape.setFillColor(color);
    m_Shape.setOutlineColor(Color::White);
    m_Shape.setOutlineThickness(1.0);
}

void Tile::draw(sf::RenderWindow &window)
{
    window.draw(m_Shape);
}
