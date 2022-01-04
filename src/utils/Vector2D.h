//
// Created by Shrimp on 12/30/2021.
//

#ifndef INC_2DSAND_VECTOR2D_H
#define INC_2DSAND_VECTOR2D_H


#include <cmath>

class Vector2D {
public:
    float x;
    float y;

    Vector2D() : x(0), y(0) {}

    Vector2D(float x, float y) : x(x), y(y) {}

    Vector2D(int x, int y) : x((float) x), y((float) y) {}

    Vector2D operator+(const Vector2D &vec) const {
        return {x + vec.x, y + vec.y};
    }

    Vector2D operator-(const Vector2D &vec) const {
        return {x - vec.x, y - vec.y};
    }

    Vector2D operator*(const Vector2D &vec) const {
        return {x * vec.x, y * vec.y};
    }

    Vector2D operator/(const Vector2D &vec) const {
        return {x / vec.x, y / vec.y};
    }

    Vector2D operator*(const float &num) const {
        return {x * num, y * num};
    }

    Vector2D operator/(const float &num) const {
        return {x / num, y / num};
    }

    float dot(const Vector2D &vec) const;

    Vector2D normalize() const;
};


#endif //INC_2DSAND_VECTOR2D_H
