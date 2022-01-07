//
// Created by Shrimp on 12/31/2021.
//

#include <iostream>
#include "DisplayManager.h"

DisplayManager::DisplayManager() {
    std::cout << "Creating Display Manager!" << std::endl;

    init();
}

void DisplayManager::init() {
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW!" << std::endl;
        return;
    }

    window = glfwCreateWindow(WIDTH, HEIGHT, "Game",
                              nullptr,
                              nullptr);
    if (!window) {
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize Glad!" << std::endl;
        return;
    }

    if (!gladLoadGL()) {
        std::cout << "Failed to initialize Glad!" << std::endl;
        return;
    }
}

void DisplayManager::updateDisplay() {
    glfwSwapBuffers(window);
    glfwPollEvents();

    double time = glfwGetTime();
    FPS = 1 / (time - lastTime);
    lastTime = time;
}

void DisplayManager::cleanUp() {
    glfwTerminate();
}

GLFWwindow *DisplayManager::getWindow() const {
    return window;
}

double DisplayManager::getFPS() const {
    return FPS;
}
