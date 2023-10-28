//
// Created by shubhra on 21/10/23.
//

#include "Engine.hpp"

using namespace  std;

Engine::Engine() {
    Vector2f resolution;
    VideoMode mode = VideoMode::getDesktopMode();
    resolution.x = mode.width;
    resolution.y = mode.height;

    m_Window.create(VideoMode(resolution.x, resolution.y),
                    "Game Window",
                    Style::Fullscreen);

    m_MainView.reset(FloatRect(0.0f, 0.0f, resolution.x, resolution.y ));
//    m_MainView.setCenter(Vector2f(0.f, 0.f));

    // const char * MAP[20] = {
    //         "b", "r", "b", "r", "b",
    //         "r", "r", "b", "r","b",
    //         "r","b","b", "r", "b",
    //         "r","b", "r","r","b"
    // };

    Color clr;
    clr = Color::Green;
    int pos;

    for (int row = 0; row <100; row++)
    {
        for (int col = 0; col < 100; col++ )
        {

//            pos = 4 * col + row;
//            const char *posCol = MAP[pos];
//            if (posCol == "r")
//            {
//                clr = Color::Red;
//            }
//            else if (posCol == "b")
//            {
//                clr = Color::Blue;
//            }

            Tile tile = Tile(row * m_TileSize, col * m_TileSize, m_TileSize, m_TileSize, clr);
            m_Tiles.push_back(tile);
        }
    }


    

}

void Engine::run() {

    Clock clock;

    while (m_Window.isOpen())
    {
        Time dt = clock.restart();

        m_GameTimeTotal += dt;
        float dtAsSceconds = dt.asSeconds();

        input();
        update(dtAsSceconds);
        draw();
    }

}

