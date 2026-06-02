#pragma once
#include <SFML/Graphics.hpp>
#include "TetrisModel.h"
#include "TetrisRenderer.h"

class InputController {
public:
    InputController(TetrisModel& model, TetrisRenderer& renderer);

    void processEvent(const sf::Event& event);
    void processRepeatedKeys(float deltaTime);

private:
    TetrisModel& model;
    TetrisRenderer& renderer;

    // Для повторяющегося нажатия ↓
    sf::Clock downRepeatClock;
    bool downPressed;
    float downRepeatInterval; // 0.05f

    void handleKeyPress(sf::Keyboard::Key key);
    void handleMouseClick(const sf::Vector2i& mousePos);
};