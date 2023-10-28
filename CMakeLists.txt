cmake_minimum_required(VERSION 3.20)
project(TileMapDragable)

set(CMAKE_CXX_STANDARD 17)

add_executable(TileMapDragable main.cpp
        Engine/Engine.cpp
        Engine/Engine.hpp
        Engine/Input.cpp
        Engine/Update.cpp
        Engine/Draw.cpp
        Engine/Tile.cpp
        Engine/Tile.hpp
        Engine/Tilemap.cpp
        Engine/Tilemap.hpp)

target_link_libraries(
        TileMapDragable
        sfml-window
        sfml-system
        sfml-graphics
        sfml-audio

)