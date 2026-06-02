#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include "TetrisModel.h"

class TetrisRenderer {
public:
    TetrisRenderer(sf::RenderWindow& window, TetrisModel& model);
    ~TetrisRenderer(); // удалить все new-объекты

    void render();
    void updateAnimation(float deltaTime);

    // Для InputController: границы кнопок
    sf::FloatRect getPauseButtonBounds() const;
    sf::FloatRect getRestartButtonBounds() const;

private:
    sf::RenderWindow& window;
    TetrisModel& model;

    // Шрифт (общий)
    sf::Font* font;

    // Кнопки
    sf::RectangleShape* pauseButton;
    sf::Text* pauseButtonText;
    sf::RectangleShape* restartButton;
    sf::Text* restartButtonText;

    // Текстовые поля
    sf::Text* scoreText;
    sf::Text* timeText;
    sf::Text* gameOverText;
    sf::Text* pauseOverlayText;

    // Таблица рекордов (вектор текстов)
    std::vector<sf::Text*> scoreEntries;

    // Анимация мигающих строк
    struct BlinkingRow {
        int rowIndex;
        float remainingTime;
    };
    std::vector<BlinkingRow> blinkingRows;
    const float BLINK_DURATION = 0.3f;

    // Цвета блоков (сопоставление int из поля -> sf::Color)
    std::map<int, sf::Color> colorMap;

    // Вспомогательные методы
    void initColors();
    void initButtons();
    void updateTexts();          // обновить содержимое sf::Text (счёт, время)
    void drawField();            // рисует блоки поля
    void drawCurrentPiece();
    void drawNextPiece();
    void drawScoreTable();
    void drawPauseOverlay();
    void drawGameOverOverlay();

    sf::Color getCellColor(int value) const;
};