//
// Created by shubhra on 21/10/23.
//

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Tile : public Rect<float>::Rect {
    RectangleShape m_Shape;
public:
    Tile();
    Tile(int x, int y, int width, int height, const Color &color);

    void draw(RenderWindow &window);
};
