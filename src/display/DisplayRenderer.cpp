//
// Created by Shrimp on 1/2/2022.
//

#include "DisplayRenderer.h"

void DisplayRenderer::render(const unsigned int image) {
    displayShader->start();

    displayShader->loadResolution();
    glBindTexture(GL_TEXTURE_2D, image);

    glBegin(GL_QUAD_STRIP);
    glVertex2f(1, 1);
    glVertex2f(-1, 1);
    glVertex2f(1, -1);
    glVertex2f(-1, -1);
    glEnd();

    DisplayShader::stop();
}

DisplayRenderer::DisplayRenderer() {
    displayShader = std::make_unique<DisplayShader>();
}
