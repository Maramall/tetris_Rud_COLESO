#pragma once
#include "Piece.h"
#include "ScoreManager.h"
#include <vector>

class TetrisModel {
public:
    TetrisModel();
    ~TetrisModel();

    void reset();
    void togglePause();

    bool moveLeft();
    bool moveRight();
    bool moveDown();   // шаг вниз, возвращает false если фигура зафиксировалась
    void hardDrop();
    bool rotateClockwise();
    bool rotateCounterClockwise();

    void updateGameTime(float deltaSeconds);
    void updateFallTimer(float deltaSeconds);

    // Геттеры для графики (читаем поля)
    const std::vector<std::vector<int>>& getField() const { return field; }
    Piece* getCurrentPiece() const { return currentPiece; }
    Piece* getNextPiece() const { return nextPiece; }
    int getPieceX() const { return pieceX; }
    int getPieceY() const { return pieceY; }
    int getScore() const { return score; }
    float getGameTimeSeconds() const { return gameTime; }
    bool isPaused() const { return paused; }
    bool isGameOver() const { return gameOver; }
    const std::vector<int>& getLastClearedRows() const { return lastClearedRows; }
    void clearLastClearedRows() { lastClearedRows.clear(); }

    ScoreManager& getScoreManager() { return scoreManager; }

private:
    // Поле 10x20, значения: 0 пусто, иначе цвет (1..7) – можно хранить int
    std::vector<std::vector<int>> field;

    Piece* currentPiece;  // владеет, delete в деструкторе
    Piece* nextPiece;
    int pieceX, pieceY;

    int score;
    float gameTime;          // секунды игры
    float fallAccumulator;   // накопленное время для падения
    float fallInterval;      // текущий интервал (0.5 сек и меньше)

    bool paused;
    bool gameOver;

    std::vector<int> lastClearedRows; // строки, удалённые в последний раз

    ScoreManager scoreManager;

    // Приватные методы
    void spawnNewPiece();
    void fixCurrentPiece();
    int deleteFullLines();
    void applyScoreForLines(int linesCleared);
    void updateFallInterval();
    bool checkCollision(const Piece& piece, int x, int y) const;
};