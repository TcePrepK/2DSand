//
// Created by Shrimp on 1/3/2022.
//

#include <algorithm>
#include "World.h"

void World::prepareUpdate() {
    for (const std::shared_ptr<Chunk> &chunk: chunkList) {
        if (chunk->filledPixelAmount != 0) continue;

        std::pair<int, int> location = getChunkLocation(chunk->chunkX, chunk->chunkY);
        // chunks.erase(location);
        // chunkList.erase(chunkList.begin() + i);
        // i--;

        // delete chunk;
    }
}

void World::update() {
//    prepareUpdate();
    for (const std::shared_ptr<Chunk> &chunk: chunkList) {
        for (int offX = 0; offX < Chunk::width; offX++) {
            for (int offY = 0; offY < Chunk::height; offY++) {
                std::shared_ptr<Element> e = chunk->getPixel(offX, offY);
                if (e == nullptr) continue;

                Vector2D pos = chunk->getIndex(offX, offY);
                Vector2D newPos = e->update((int) pos.x, (int) pos.y);
                if (newPos.x == pos.x && newPos.y == pos.y) continue;

                auto toChunk = getChunk((int) newPos.x, (int) newPos.y);
                if (toChunk == nullptr) continue;
                if (toChunk != chunk) awakeChunk(toChunk);

                Vector2D from = {offX, offY};
                Vector2D to = newPos - Vector2D(toChunk->tileX, toChunk->tileY);

                chunk->movePixel(toChunk, from, to);
            }
        }
    }

    for (const std::shared_ptr<Chunk> &chunk: chunkList) {
        chunk->updateChanges();
    }
}

bool World::inBounds(int x, int y) {
    return !(x < 0 || y < 0 || x > 7 || y > 7);
}

bool World::inBounds(std::pair<int, int> location) {
    return true;
//    return !(location.first < 0 || location.second < 0 || location.first > 7 || location.second > 7);
}

void World::awakeChunkDirect(const std::shared_ptr<Chunk> &chunk) {
    chunkList.push_back(chunk);
}

void World::awakeChunk(const std::shared_ptr<Chunk> &chunk) {
    if (std::find(chunkList.begin(), chunkList.end(), chunk) != chunkList.end()) return;
    awakeChunkDirect(chunk);
}

std::pair<int, int> World::getChunkLocation(int x, int y) {
    return {std::floor((float) x / Chunk::width), std::floor((float) y / Chunk::height)};
}

std::shared_ptr<Chunk> World::createChunk(std::pair<int, int> location) {
    std::shared_ptr<Chunk> chunk = std::make_shared<Chunk>(location.first, location.second);
    chunks.insert({location, chunk});
    awakeChunkDirect(chunk);
    return chunk;
}

std::shared_ptr<Chunk> World::getChunkDirect(std::pair<int, int> location) {
    if (chunks.find(location) == chunks.end()) {
        return nullptr;
    }

    return chunks.at(location);
}

std::shared_ptr<Chunk> World::getChunkDirect(int x, int y) {
    std::pair<int, int> location = getChunkLocation(x, y);
    return getChunkDirect(location);
}

std::shared_ptr<Chunk> World::getChunk(std::pair<int, int> location) {
    if (!inBounds(location)) return nullptr;
    std::shared_ptr<Chunk> chunk = getChunkDirect(location);
    return chunk == nullptr ? createChunk(location) : chunk;
}

std::shared_ptr<Chunk> World::getChunk(int x, int y) {
    std::pair<int, int> location = getChunkLocation(x, y);
    return getChunk(location);
}

std::shared_ptr<Element> World::getElement(int x, int y) {
    std::pair<int, int> location = getChunkLocation(x, y);
    std::shared_ptr<Chunk> chunk = getChunk(location);
    Vector2D pos = chunk->getWorldIndex(x, y);
    return chunk->getPixel((int) pos.x, (int) pos.y);
}

std::shared_ptr<Element> World::getElementDirect(int x, int y) {
    std::pair<int, int> location = getChunkLocation(x, y);
    std::shared_ptr<Chunk> chunk = getChunkDirect(location);
    if (chunk == nullptr) return nullptr;
    Vector2D pos = chunk->getWorldIndex(x, y);

    return chunk->getPixel((unsigned int) pos.x, (unsigned int) pos.y);
}

void World::setElement(int x, int y, const std::shared_ptr<Element> &element) {
    std::pair<int, int> location = getChunkLocation(x, y);
    std::shared_ptr<Chunk> chunk = getChunk(location);
    if (chunk == nullptr) return;
    awakeChunk(chunk);
    Vector2D pos = chunk->getWorldIndex(x, y);
    chunk->setPixel((int) pos.x, (int) pos.y, element);

    const unsigned int idx = 4 * (x + screenWidth * y);
    if (element == nullptr) {
        worldBuffer[idx + 4] = 0;
        worldBuffer[idx + 1] = 0;
        worldBuffer[idx + 2] = 0;
        worldBuffer[idx + 3] = 1;

        return;
    }

    const Vector3D color = element->getColor();
    worldBuffer[idx + 4] = color.x;
    worldBuffer[idx + 1] = color.y;
    worldBuffer[idx + 2] = color.z;
    worldBuffer[idx + 3] = 1;
}
