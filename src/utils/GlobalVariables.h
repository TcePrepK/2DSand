//
// Created by Shrimp on 12/30/2021.
//

#ifndef INC_2DSAND_GLOBALVARIABLES_H
#define INC_2DSAND_GLOBALVARIABLES_H


#include <memory>
#include "Vector2D.h"
#include "../display/DisplayManager.h"
#include "../display/DisplayRenderer.h"
#include "../world/World.h"
#include "../elements/ElementRegistry.h"
#include "../core/RandomNumberGenerator.h"

struct GlobalVariables_ {
public:
    void init() {
        elementRegistry = std::make_shared<ElementRegistry>();
        elementRegistry->RegisterElements();

        displayManager = std::make_shared<DisplayManager>();
        displayRenderer = std::make_shared<DisplayRenderer>();

        const unsigned int screenWidth = DisplayManager::WIDTH;
        const unsigned int screenHeight = DisplayManager::HEIGHT;
        world = std::make_shared<World>(screenWidth, screenHeight);
    }

    bool gameIsRunning = true;
    int currentFrame = 0;

    unsigned int currentMatID = 1;
// particle_shower shower;

    std::shared_ptr<ElementRegistry> elementRegistry;
    std::shared_ptr<DisplayManager> displayManager;
    std::shared_ptr<DisplayRenderer> displayRenderer;
    std::shared_ptr<World> world;

    Vector2D oldMouse;
    Vector2D mouse;
    bool holdingLeft = false;
};

extern GlobalVariables_ GlobalVariables;


#endif //INC_2DSAND_GLOBALVARIABLES_H
