#pragma once
#include <array>

struct Kick {
    int x;
    int y;
};

struct RotationKick {
    std::array<Kick, 4> counterClockwise;
    std::array<Kick, 4> clockwise;
};

using ShapeKicks = std::array<RotationKick, 4>;

using SingleGrid = std::array<std::array<int, 4>, 4>;

struct ShapeGrid {
    int offsetX;
    int offsetY;
    int width;
    int height;
    SingleGrid grid;
};

enum ShapeType {
    I = 1,
    J,
    L,
    O,
    S,
    T,
    Z,
};

struct Shape {
    ShapeType type;
    ShapeKicks kicks;
    std::array<ShapeGrid, 4> grids;
};

constexpr ShapeKicks kicksJLOSTZ { {
    {
        { { { -1, 0 }, { -1, -1 }, { 0, 2 }, { -1, 2 } } },
        { { { 1, 0 }, { 1, -1 }, { 0, 2 }, { 1, 2 } } },
    },
    {
        { { { 1, 0 }, { 1, 1 }, { 0, -2 }, { 1, -2 } } },
        { { { 1, 0 }, { 1, 1 }, { 0, -2 }, { 1, -2 } } },
    },
    {
        { { { 1, 0 }, { 1, -1 }, { 0, 2 }, { 1, 2 } } },
        { { { -1, 0 }, { -1, -1 }, { 0, 2 }, { -1, 2 } } },
    },
    {
        { { { -1, 0 }, { -1, 1 }, { 0, -2 }, { -1, -2 } } },
        { { { -1, 0 }, { -1, 1 }, { 0, -2 }, { -1, -2 } } },
    },
} };

constexpr ShapeKicks kicksI { {
    {
        { { { -2, 0 }, { 1, 0 }, { -2, 1 }, { 1, -2 } } },
        { { { -1, 0 }, { 2, 0 }, { -1, -2 }, { 2, 1 } } },
    },
    {
        { { { -1, 0 }, { 2, 0 }, { -1, -2 }, { 2, 1 } } },
        { { { 2, 0 }, { -1, 0 }, { 2, -1 }, { -1, 2 } } },
    },
    {
        { { { 2, 0 }, { -1, 0 }, { 2, -1 }, { -1, 2 } } },
        { { { 1, 0 }, { -2, 0 }, { 1, 2 }, { -2, -1 } } },
    },
    {
        { { { 1, 0 }, { -2, 0 }, { 1, 2 }, { -2, -1 } } },
        { { { -2, 0 }, { 1, 0 }, { -2, 1 }, { 1, -2 } } },
    },
} };

constexpr Shape shapeI {
    I,
    kicksI,
    { {
        { 0, 1, 4, 1, { { { { 0, 0, 0, 0 } }, { { I, I, I, I } }, { { 0, 0, 0, 0 } }, { { 0, 0, 0, 0 } } } } },
        { 2, 0, 1, 4, { { { { 0, 0, I, 0 } }, { { 0, 0, I, 0 } }, { { 0, 0, I, 0 } }, { { 0, 0, I, 0 } } } } },
        { 0, 2, 4, 1, { { { { 0, 0, 0, 0 } }, { { 0, 0, 0, 0 } }, { { I, I, I, I } }, { { 0, 0, 0, 0 } } } } },
        { 1, 0, 1, 4, { { { { 0, I, 0, 0 } }, { { 0, I, 0, 0 } }, { { 0, I, 0, 0 } }, { { 0, I, 0, 0 } } } } },
    } },
};

constexpr Shape shapeJ {
    J,
    kicksJLOSTZ,
    { {
        { 0, 0, 3, 2, { { { { J, 0, 0, 0 } }, { { J, J, J, 0 } }, { { 0, 0, 0, 0 } }, { { 0, 0, 0, 0 } } } } },
        { 1, 0, 2, 3, { { { { 0, J, J, 0 } }, { { 0, J, 0, 0 } }, { { 0, J, 0, 0 } }, { { 0, 0, 0, 0 } } } } },
        { 0, 1, 3, 2, { { { { 0, 0, 0, 0 } }, { { J, J, J, 0 } }, { { 0, 0, J, 0 } }, { { 0, 0, 0, 0 } } } } },
        { 0, 0, 2, 3, { { { { 0, J, 0, 0 } }, { { 0, J, 0, 0 } }, { { J, J, 0, 0 } }, { { 0, 0, 0, 0 } } } } },
    } },
};

constexpr Shape shapeL {
    L,
    kicksJLOSTZ,
    { {
        { 0, 0, 3, 2, { { { { 0, 0, L, 0 } }, { { L, L, L, 0 } }, { { 0, 0, 0, 0 } }, { { 0, 0, 0, 0 } } } } },
        { 1, 0, 2, 3, { { { { 0, L, 0, 0 } }, { { 0, L, 0, 0 } }, { { 0, L, L, 0 } }, { { 0, 0, 0, 0 } } } } },
        { 0, 1, 3, 2, { { { { 0, 0, 0, 0 } }, { { L, L, L, 0 } }, { { L, 0, 0, 0 } }, { { 0, 0, 0, 0 } } } } },
        { 0, 0, 2, 3, { { { { L, L, 0, 0 } }, { { 0, L, 0, 0 } }, { { 0, L, 0, 0 } }, { { 0, 0, 0, 0 } } } } },
    } },
};

constexpr Shape shapeO {
    O,
    kicksJLOSTZ,
    { {
        { 0, 0, 2, 2, { { { { O, O, 0, 0 } }, { { O, O, 0, 0 } }, { { 0, 0, 0, 0 } }, { { 0, 0, 0, 0 } } } } },
        { 0, 0, 2, 2, { { { { O, O, 0, 0 } }, { { O, O, 0, 0 } }, { { 0, 0, 0, 0 } }, { { 0, 0, 0, 0 } } } } },
        { 0, 0, 2, 2, { { { { O, O, 0, 0 } }, { { O, O, 0, 0 } }, { { 0, 0, 0, 0 } }, { { 0, 0, 0, 0 } } } } },
        { 0, 0, 2, 2, { { { { O, O, 0, 0 } }, { { O, O, 0, 0 } }, { { 0, 0, 0, 0 } }, { { 0, 0, 0, 0 } } } } },
    } },
};

constexpr Shape shapeS {
    S,
    kicksJLOSTZ,
    { {
        { 0, 0, 3, 2, { { { { 0, S, S, 0 } }, { { S, S, 0, 0 } }, { { 0, 0, 0, 0 } }, { { 0, 0, 0, 0 } } } } },
        { 1, 0, 2, 3, { { { { 0, S, 0, 0 } }, { { 0, S, S, 0 } }, { { 0, 0, S, 0 } }, { { 0, 0, 0, 0 } } } } },
        { 0, 1, 3, 2, { { { { 0, 0, 0, 0 } }, { { 0, S, S, 0 } }, { { S, S, 0, 0 } }, { { 0, 0, 0, 0 } } } } },
        { 0, 0, 2, 3, { { { { S, 0, 0, 0 } }, { { S, S, 0, 0 } }, { { 0, S, 0, 0 } }, { { 0, 0, 0, 0 } } } } },
    } },
};

constexpr Shape shapeT {
    T,
    kicksJLOSTZ,
    { {
        { 0, 0, 3, 2, { { { { 0, T, 0, 0 } }, { { T, T, T, 0 } }, { { 0, 0, 0, 0 } }, { { 0, 0, 0, 0 } } } } },
        { 1, 0, 2, 3, { { { { 0, T, 0, 0 } }, { { 0, T, T, 0 } }, { { 0, T, 0, 0 } }, { { 0, 0, 0, 0 } } } } },
        { 0, 1, 3, 2, { { { { 0, 0, 0, 0 } }, { { T, T, T, 0 } }, { { 0, T, 0, 0 } }, { { 0, 0, 0, 0 } } } } },
        { 0, 0, 2, 3, { { { { 0, T, 0, 0 } }, { { T, T, 0, 0 } }, { { 0, T, 0, 0 } }, { { 0, 0, 0, 0 } } } } },
    } },
};

constexpr Shape shapeZ {
    Z,
    kicksJLOSTZ,
    { {
        { 0, 0, 3, 2, { { { { Z, Z, 0, 0 } }, { { 0, Z, Z, 0 } }, { { 0, 0, 0, 0 } }, { { 0, 0, 0, 0 } } } } },
        { 1, 0, 2, 3, { { { { 0, 0, Z, 0 } }, { { 0, Z, Z, 0 } }, { { 0, Z, 0, 0 } }, { { 0, 0, 0, 0 } } } } },
        { 0, 1, 3, 2, { { { { 0, 0, 0, 0 } }, { { Z, Z, 0, 0 } }, { { 0, Z, Z, 0 } }, { { 0, 0, 0, 0 } } } } },
        { 0, 0, 2, 3, { { { { 0, Z, 0, 0 } }, { { Z, Z, 0, 0 } }, { { Z, 0, 0, 0 } }, { { 0, 0, 0, 0 } } } } },
    } },
};
