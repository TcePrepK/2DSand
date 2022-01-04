//
// Created by Shrimp on 12/30/2021.
//

#include "Vector3D.h"

float Vector3D::dot(const Vector3D &vec) const {
    return x * vec.x + y * vec.y + z * vec.z;
}

Vector3D Vector3D::cross(const Vector3D &vec) const {
    return {y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x};
}

Vector3D Vector3D::normalize() const {
    Vector3D vec;
    float len = std::sqrt(x * x + y * y + z * z);
    if (len != 0) {
        vec.x = x / len;
        vec.y = y / len;
        vec.z = z / len;
    }
    return vec;
}
