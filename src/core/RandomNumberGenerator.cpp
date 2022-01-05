//
// Created by Shrimp on 1/5/2022.
//

#include "RandomNumberGenerator.h"

int RandomNumberGenerator::randomInt(int lower, int upper) {
    std::uniform_real_distribution<double> dist(lower, upper + 1);
    return (int) dist(rng);
}

float RandomNumberGenerator::randomFloat(int lower, int upper) {
    std::uniform_real_distribution<double> dist(lower, upper + 1);
    return (float) dist(rng);
}
