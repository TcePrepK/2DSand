//
// Created by Shrimp on 1/3/2022.
//

#ifndef INC_2DSAND_WORLD_H
#define INC_2DSAND_WORLD_H


#include <unordered_map>
#include <vector>
#include <memory>
#include "Chunk.h"
#include "../utils/Pair_Hash.h"
#include "../elements/Element.h"

class World {
public:
    std::unordered_map<std::pair<int, int>, std::shared_ptr<Chunk>, pair_hash> chunks;
    std::vector<std::shared_ptr<Chunk>> chunkList;

    unsigned int screenWidth;
    unsigned int screenHeight;
    float *worldBuffer;

    World(const unsigned int width, const unsigned int height) : screenWidth(width), screenHeight(height) {
        worldBuffer = new float[screenWidth * screenHeight * 4];
    }

    void prepareUpdate();

    void update();

    // HELPERS

    static bool inBounds(int x, int y);

    static bool inBounds(std::pair<int, int> location);

    void awakeChunkDirect(const std::shared_ptr<Chunk> &chunk);

    void awakeChunk(const std::shared_ptr<Chunk> &chunk);

    static std::pair<int, int> getChunkLocation(int x, int y);

    std::shared_ptr<Chunk> createChunk(std::pair<int, int> location);

    std::shared_ptr<Chunk> getChunkDirect(std::pair<int, int> location);

    std::shared_ptr<Chunk> getChunkDirect(int x, int y);

    std::shared_ptr<Chunk> getChunk(std::pair<int, int> location);

    std::shared_ptr<Chunk> getChunk(int x, int y);

    std::shared_ptr<Element> getElement(int x, int y);

    std::shared_ptr<Element> getElementDirect(int x, int y);

    void setElement(int x, int y, const std::shared_ptr<Element> &element);
};


#endif //INC_2DSAND_WORLD_H
