//
// Created by Shrimp on 12/31/2021.
//

#ifndef INC_2DSAND_DISPLAYMANAGER_H
#define INC_2DSAND_DISPLAYMANAGER_H


#include <memory>
#include "DisplayShader.h"
#include "GLFW/glfw3.h"

class DisplayManager {
private:
    GLFWwindow *window{};

    double lastTime{};
    double FPS{};
public:
    static const unsigned int WIDTH = 512;
    static const unsigned int HEIGHT = 512;

    std::unique_ptr<DisplayShader> displayShader;

    DisplayManager();

    void init();

    void updateDisplay();

    static void cleanUp();

    GLFWwindow *getWindow() const;

    double getFPS() const;
};


#endif //INC_2DSAND_DISPLAYMANAGER_H
