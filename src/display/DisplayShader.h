//
// Created by Shrimp on 1/1/2022.
//

#ifndef INC_2DSAND_DISPLAYSHADER_H
#define INC_2DSAND_DISPLAYSHADER_H


#include "../core/ShaderProgram.h"

class DisplayShader : public ShaderProgram {
private:
    int location_resolution{};

public:
    DisplayShader() : ShaderProgram("res/shaders/displayVertexShader.glsl",
                                    "res/shaders/displayFragmentShader.glsl") {};

    void getAllUniformLocations() override {
        location_resolution = getUniformLocation("resolution");
    };

    void loadResolution() const {
        load2DVector(location_resolution, {512, 512});
    }
};


#endif //INC_2DSAND_DISPLAYSHADER_H
