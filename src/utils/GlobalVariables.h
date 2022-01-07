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
    }

    bool gameIsRunning = true;
    int currentFrame = 0;

    unsigned int currentMatID = 1;
// particle_shower shower;

    std::shared_ptr<ElementRegistry> elementRegistry;
    std::shared_ptr<DisplayManager> displayManager;
    std::shared_ptr<DisplayRenderer> displayRenderer;

    Vector2D oldMouse;
    Vector2D mouse;
    bool holdingLeft = false;
};

extern GlobalVariables_ GlobalVariables;


#endif //INC_2DSAND_GLOBALVARIABLES_H
