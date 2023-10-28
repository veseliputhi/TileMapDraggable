//
// Created by shubhra on 21/10/23.
//

#include "Engine.hpp"
#include <iostream>


void Engine::input() {

    Event event;
    while (m_Window.pollEvent(event))
    {

        switch (event.type) {
            case Event::KeyPressed:
                switch (event.key.code) {
                    case Keyboard::Escape:
                        std::cout << "Clossing...." << std::endl;
                        m_Window.close();
                        break;
                }
                break;

            case Event::MouseButtonPressed:
                switch (event.mouseButton.button) {
                    case 0:
                        mb_dragging = true;
                        m_OldMovementPos = m_Window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                        break;
                }
                break;

            case Event::MouseButtonReleased:
                switch (event.mouseButton.button) {
                    case 0:
                        mb_dragging = false;
                        break;
                }
                break;

            case Event::MouseMoved:
                if (!mb_dragging)
                    break;

                const Vector2f newPos = m_Window.mapPixelToCoords(Vector2i(event.mouseMove.x, event.mouseMove.y));
                m_Movement = m_OldMovementPos - newPos;
                m_MainView.setCenter(m_MainView.getCenter() + m_Movement);
                m_Window.setView(m_MainView);
                m_OldMovementPos = m_Window.mapPixelToCoords(Vector2i(event.mouseMove.x, event.mouseMove.y));
                break;
        }

    }

}