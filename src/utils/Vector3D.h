//
// Created by Shrimp on 12/30/2021.
//

#ifndef INC_2DSAND_VECTOR3D_H
#define INC_2DSAND_VECTOR3D_H


#include <cmath>

class Vector3D {
public:
    float x, y, z;

    Vector3D() : x(0), y(0), z(0) {}

    Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}

    Vector3D operator+(const Vector3D &vec) const {
        return {x + vec.x, y + vec.y, z + vec.z};
    }

    Vector3D operator-(const Vector3D &vec) const {
        return {x - vec.x, y - vec.y, z - vec.z};
    }

    Vector3D operator*(const Vector3D &vec) const {
        return {x * vec.x, y * vec.y, z * vec.z};
    }

    Vector3D operator/(const Vector3D &vec) const {
        return {x / vec.x, y / vec.y, z / vec.z};
    }

    Vector3D operator*(const float &num) const {
        return {x * num, y * num, z * num};
    }

    Vector3D operator/(const float &num) const {
        return {x / num, y / num, z / num};
    }

    float dot(const Vector3D &vec) const;

    Vector3D cross(const Vector3D &vec) const;

    Vector3D normalize() const;
};


#endif //INC_2DSAND_VECTOR3D_H
