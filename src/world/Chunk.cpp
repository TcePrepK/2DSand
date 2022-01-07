//
// Created by Shrimp on 1/3/2022.
//

#include "World.h"

void Chunk::updateChanges() {
    for (int i = 0; i < changes.size(); i++) {
        auto change = changes[i];
        std::shared_ptr<Chunk> toC = std::get<0>(change);
        Vector2D to = std::get<2>(change);
        if (toC->getElement((int) to.x, (int) to.y) != nullptr) {
            changes[i] = changes.back();
            changes.pop_back();
            i--;
        }
    }

    while (!changes.empty()) {
        int r = RandomNumberGenerator::randomInt(0, (int) changes.size() - 1);
        auto &change = changes.at(r);

        std::shared_ptr<Chunk> toC = std::get<0>(change);
        Vector2D from = std::get<1>(change);
        Vector2D to = std::get<2>(change);

        toC->setElement((int) to.x, (int) to.y, getElement((int) from.x, (int) from.y));
        setElement((int) from.x, (int) from.y, nullptr);

        changes[r] = changes.back();
        changes.pop_back();
    }
}

Vector2D Chunk::getChunkToWorldIndex(int x, int y) const {
    return {x + tileX, y + tileY};
}

Vector2D Chunk::getWorldToChunkIndex(int x, int y) const {
    return {x - tileX, y - tileY};
}

std::shared_ptr<Element> Chunk::getElement(unsigned int x, unsigned int y) const {
    return grid[x + y * width];
}

void Chunk::moveElement(const std::shared_ptr<Chunk> &toC, Vector2D from, Vector2D to) {
    changes.emplace_back(toC, from, to);
}

void Chunk::setElement(int x, int y, const std::shared_ptr<Element> &element) {
    std::shared_ptr<Element> dest = getElement(x, y);

    grid[x + y * width] = element;
    if (element != nullptr && dest == nullptr) {
        filledPixelAmount++;
    } else if (dest != nullptr && element == nullptr) {
        filledPixelAmount--;
    }

    Vector2D pos = getChunkToWorldIndex(x, y);
    if (element == nullptr) {
        World::colorizeGrid((int) pos.x, (int) pos.y, {0, 0, 0});
    } else {
        World::colorizeGrid((int) pos.x, (int) pos.y, element->getColor());
    }
}
