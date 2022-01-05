//
// Created by Shrimp on 1/3/2022.
//

#include "Chunk.h"
#include "../utils/GlobalVariables.h"

void Chunk::updateChanges() {
    for (int i = 0; i < changes.size(); i++) {
        auto change = changes[i];
        std::shared_ptr<Chunk> toC = std::get<0>(change);
        Vector2D to = std::get<2>(change);
        if (toC->getPixel((int) to.x, (int) to.y) != nullptr) {
            changes[i] = changes.back();
            changes.pop_back();
            i--;
        }
    }

    while (!changes.empty()) {
//        int r = GlobalVariables.randomNumberGenerator.randomInt(0, (int) changes.size());
        int r = 0;
        auto &change = changes[r];

        std::shared_ptr<Chunk> toC = std::get<0>(change);
        Vector2D from = std::get<1>(change);
        Vector2D to = std::get<2>(change);

        toC->setPixel((int) to.x, (int) to.y, getPixel((int) from.x, (int) from.y));
        setPixel((int) from.x, (int) from.y, nullptr);

        changes[r] = changes.back();
        changes.pop_back();
    }
}

Vector2D Chunk::getIndex(int x, int y) const {
    return {tileX + x, tileY + y};
}

Vector2D Chunk::getWorldIndex(int x, int y) const {
    return {x - tileX, y - tileY};
}

std::shared_ptr<Element> Chunk::getPixel(unsigned int x, unsigned int y) const {
    return grid[x + y * width];
}

void Chunk::movePixel(const std::shared_ptr<Chunk> &toC, Vector2D from, Vector2D to) {
    changes.emplace_back(toC, from, to);
}

void Chunk::setPixel(const int x, const int y, const std::shared_ptr<Element> &element) {
    std::shared_ptr<Element> dest = getPixel(x, y);

    grid[x + y * width] = element;

    if (element != nullptr && dest == nullptr) {
        filledPixelAmount++;
    } else if (dest != nullptr && element == nullptr) {
        filledPixelAmount--;
    }
}
