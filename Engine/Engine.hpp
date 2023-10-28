#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.hpp"

using namespace  sf;
using namespace std;

class Engine{
public:

    RenderWindow m_Window;
    bool m_Playing = false;
    Time m_GameTimeTotal;

    vector<Tile> m_Tiles;
    const int m_TileSize = 32;

    View m_MainView;
    Vector2f m_OldMovementPos = Vector2f (0, 0);
    Vector2f m_Movement = Vector2f(0, 0);
    bool  mb_dragging = false;

    void input();
    void update(float dt);
    void draw();

public:
    Engine();
    void run();
};

