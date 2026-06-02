#pragma once
#include "Piece.h"
#include <vector>

struct RotationResult {
    bool success;
    int newX;
    int newY;
    std::vector<std::vector<int>> newShape;
};

class RotationSystem {
public:
    static RotationResult tryRotate(
        const std::vector<std::vector<int>>& field, // 10x20, 0=пусто, иначе цвет?
        const Piece& piece,
        int pieceX, int pieceY,
        bool clockwise
    );

private:
    static bool collides(const std::vector<std::vector<int>>& field,
        const std::vector<std::vector<int>>& shape,
        int x, int y);
    static std::vector<std::pair<int, int>> getOffsets(int pieceType, int fromRot, int toRot);
};