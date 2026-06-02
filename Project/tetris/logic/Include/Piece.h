#pragma once
#include <vector>

class Piece {
public:
    Piece(int type);  // type: 0..6

    std::vector<std::vector<int>> getShape() const;
    std::vector<std::vector<int>> getRotatedClockwise() const;
    std::vector<std::vector<int>> getRotatedCounterClockwise() const;

    int getRed() const;
    int getGreen() const;
    int getBlue() const;
    int getType() const { return type; }

private:
    int type;
    int r, g, b;

    static std::vector<std::vector<int>> rotateMatrix(const std::vector<std::vector<int>>& shape, bool clockwise);
};