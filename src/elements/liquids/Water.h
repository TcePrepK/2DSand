//
// Created by Shrimp on 1/4/2022.
//

#ifndef INC_2DSAND_WATER_H
#define INC_2DSAND_WATER_H


#include "Liquid.h"

class Water : public Liquid {
public:
    Water() : Liquid(2, generateColor()) {}

    static Vector3D generateColor() {
        float r = RandomNumberGenerator::randomFloat(0, 1) / 2;
        float red = lerp(0.1f, 0.15f, r);
        float green = lerp(0.3f, 0.35f, r);
        float blue = lerp(0.7f, 0.8f, r);
        return {red, green, blue};
    }

    // Vector2D simulateWater(s32 x, s32 y, s32 id)
    // {
    //     s32 dir = randomVal(0, 1) ? 1 : -1;
    //     Vector2D pos = {x, y};
    //     Vector2D B = {x, y + 1};
    //     Vector2D L = {x + dir, y};
    //     Vector2D R = {x - dir, y};
    //     Vector2D BL = {x + dir, y + 1};
    //     Vector2D BR = {x - dir, y + 1};
    //     if (isMoveFree(B, id))
    //     {
    //         return B;
    //     }
    //     else if (isMoveFree(BL, id))
    //     {
    //         return BL;
    //     }
    //     else if (isMoveFree(BR, id))
    //     {
    //         return BR;
    //     }
    //     else if (isMoveFree(L, id))
    //     {
    //         return L;
    //     }
    //     else if (isMoveFree(R, id))
    //     {
    //         return R;
    //     }

    //     return pos;
    // }

    // Vector2D update(s32 x, s32 y)
    // {
    //     s32 id = mat_id_water;
    //     s32 fallRate = 1;   // 5
    //     s32 spreadRate = 1; // 50

    //     s32 currentFall = 0;
    //     s32 currentSpread = 0;

    //     Vector2D pos = {x, y};
    //     if (isSurrounded(x, y, id))
    //         return {x, y}; // It can't move

    //     for (s32 j = 1; j <= fallRate; j++)
    //     {
    //         Vector2D B = {x, y + j};
    //         if (!isAir(B))
    //             break;
    //         currentFall = j;
    //     }

    //     if (currentFall == fallRate)
    //     {
    //         Vector2D g = {x, y + fallRate};
    //         swapData(pos, g);
    //         return g;
    //     }

    //     Vector2D currentP = {x, y + currentFall};
    //     s32 currentLoop = 0;
    //     while (currentLoop++ < spreadRate + fallRate)
    //     {
    //         Vector2D nextP = simulateWater(currentP.x, currentP.y, id);
    //         currentSpread = nextP.x - x;
    //         currentFall = nextP.y - y;

    //         if ((nextP.x == currentP.x && nextP.y == currentP.y) || abs(currentSpread) > spreadRate || currentFall > fallRate)
    //         {
    //             swapData(pos, currentP);
    //             return currentP;
    //         }
    //         currentP = nextP;
    //     }

    //     Vector2D lastPos = {x + currentSpread, y + currentFall};
    //     swapData(pos, lastPos);
    //     return lastPos;
    // }
};


#endif //INC_2DSAND_WATER_H
