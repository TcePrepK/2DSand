//
// Created by Shrimp on 12/30/2021.
//

#ifndef INC_2DSAND_MATHS_H
#define INC_2DSAND_MATHS_H


#include <cstdlib>

static float lerp(float v0, float v1, float t) {
    return (1.f - t) * v0 + t * v1;
}

static float clamp(float val, float min, float max) {
    if (val < min)
        return min;
    if (val > max)
        return max;
    return val;
}

static int randomVal(int lower, int upper) {
    if (upper < lower) {
        int tmp = lower;
        lower = upper;
        upper = tmp;
    }

    return rand() % (upper - lower + 1) + lower;
}


#endif //INC_2DSAND_MATHS_H
