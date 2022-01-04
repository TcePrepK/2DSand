//
// Created by Shrimp on 12/30/2021.
//

#include "Vector2D.h"

float Vector2D::dot(const Vector2D &vec) const {
    return x * vec.x + y * vec.y;
}

Vector2D Vector2D::normalize() const {
    Vector2D vec;
    float len = std::sqrt(x * x + y * y);
    if (len != 0) {
        vec.x = x / len;
        vec.y = y / len;
    }
    return vec;
}
