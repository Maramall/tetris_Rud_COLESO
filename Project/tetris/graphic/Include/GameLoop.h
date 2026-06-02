#pragma once
#include <SFML/Graphics.hpp>
#include "TetrisModel.h"
#include "TetrisRenderer.h"
#include "InputController.h"

class GameLoop {
public:
    GameLoop();
    ~GameLoop();
    void run();

private:
    sf::RenderWindow* window;
    TetrisModel* model;
    TetrisRenderer* renderer;
    InputController* controller;
    sf::Clock deltaClock;

    void processEvents();
    void update(float deltaTime);
    void render();
};