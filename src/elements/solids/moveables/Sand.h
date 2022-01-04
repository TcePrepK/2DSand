//
// Created by Shrimp on 1/3/2022.
//

#ifndef INC_2DSAND_SAND_H
#define INC_2DSAND_SAND_H

#include "../Solid.h"

class Sand : public Solid {
public:
    Sand() : Solid(1, generateColor()) {}

    static Vector3D generateColor() {
        float r = (float) randomVal(0, 10) / 10.f;
        float red = lerp(0.8f, 1.f, r);
        float green = lerp(0.5f, 0.6f, r);
        float blue = lerp(0.2f, 0.25f, r);
        return {red, green, blue};
    }

    Vector2D update(int x, int y) override {
        return {x, y};
//        // Element *element = sandWorld.getPixel(x, y + 1);
//        if (world.getPixelDirect(x, y + 1) == nullptr)
//            return Vector2D(x, y + 1);
//        if (world.getPixelDirect(x + 1, y + 1) == nullptr)
//            return Vector2D(x + 1, y + 1);
//        if (world.getPixelDirect(x - 1, y + 1) == nullptr)
//            return Vector2D(x - 1, y + 1);
//
//        return Vector2D(x, y);
    }

    // Vector2D simulateSand(s32 x, s32 y, s32 id)
    // {
    //     s32 dir = randomVal(0, 1) ? 1 : -1;
    //     Vector2D pos = {x, y};
    //     Vector2D B = {x, y + 1};
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

    //     return pos;
    // }

    // Vector2D update(s32 x, s32 y)
    // {
    //     s32 id = mat_id_sand;
    //     if (isSurrounded(x, y, id))
    //         return {x, y}; // It can't move

    //     s32 fallRate = 4;   // 4
    //     s32 spreadRate = 5; // 5

    //     s32 currentFall = 0;
    //     s32 currentSpread = 0;

    //     Vector2D pos = {x, y};

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
    //         Vector2D nextP = simulateSand(currentP.x, currentP.y, id);
    //         currentSpread = nextP.x - x;
    //         currentFall = nextP.y - y;

    //         if ((nextP.x == currentP.x && nextP.y == currentP.y) || abs(currentSpread) > spreadRate || currentFall > fallRate)
    //         {
    //             swapData(pos, currentP);
    //             return currentP;
    //         }
    //         currentP = nextP;
    //     }

    //     Vector2D lastP = {x + currentSpread, y + currentFall};
    //     swapData(pos, lastP);
    //     return lastP;
    // }
};


#endif //INC_2DSAND_SAND_H
