//
// Created by shubhra on 21/10/23.
//

#include "Engine.hpp"

void Engine::draw() {

    m_Window.clear(Color::Black);
//    m_Window.setView(m_MainView);

    for (auto tile = m_Tiles.begin(); tile != m_Tiles.end(); tile++)
    {
        tile->draw(m_Window);
    }

    Vector2i mousePos = Mouse::getPosition();
    const Vector2i wPos = m_Window.mapCoordsToPixel(Vector2f (mousePos.x, mousePos.y), m_MainView);
    const Vector2f pixPos = m_Window.mapPixelToCoords(Vector2i (Mouse::getPosition().x, Mouse::getPosition().y));
    Vector2f pos =  pixPos;

    CircleShape cir;
    cir.setRadius(20.f);
    cir.setPosition(pos.x, pos.y);

    RectangleShape outLineRect;

    for (auto tile = m_Tiles.begin(); tile != m_Tiles.end(); tile++)
    {
        if (tile->contains(Vector2f (pos.x, pos.y)))
        {
            outLineRect.setPosition(tile->top, tile->left);
            outLineRect.setSize(Vector2f (tile->width, tile->height));
            outLineRect.setFillColor(Color::Blue);
            outLineRect.setOutlineColor(Color::Red);
            outLineRect.setOutlineThickness(1);
            m_Window.draw(outLineRect);
            break;
        }
    }

    m_Window.draw(cir);

    m_Window.display();

}