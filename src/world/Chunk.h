//
// Created by Shrimp on 1/3/2022.
//

#ifndef INC_2DSAND_CHUNK_H
#define INC_2DSAND_CHUNK_H


#include <vector>
#include <tuple>
#include <memory>
#include "../elements/Element.h"
#include "../utils/Vector2D.h"
#include "../utils/Maths.h"

class Chunk {
public:
    static const unsigned int width = 32;
    static const unsigned int height = 32;

    int chunkX, chunkY, tileX, tileY;
    int filledPixelAmount = 0;

    std::shared_ptr<Element> *grid;
    std::vector<std::tuple<std::shared_ptr<Chunk>, Vector2D, Vector2D>> changes;

    Chunk(int x, int y) : chunkX(x), chunkY(y), tileX(x * (int) width), tileY(y * (int) height) {
        grid = new std::shared_ptr<Element>[width * height]{};
    }

    ~Chunk() {
        delete[] grid;
    }

    void updateChanges();

    // HELPERS

    Vector2D getIndex(int x, int y) const;

    Vector2D getWorldIndex(int x, int y) const;

    std::shared_ptr<Element> getPixel(unsigned int x, unsigned int y) const;

    void movePixel(const std::shared_ptr<Chunk> &toC, Vector2D from, Vector2D to);

    void setPixel(int x, int y, const std::shared_ptr<Element> &element);
};


#endif //INC_2DSAND_CHUNK_H
