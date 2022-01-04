//
// Created by Shrimp on 1/1/2022.
//

#ifndef INC_2DSAND_SHADERPROGRAM_H
#define INC_2DSAND_SHADERPROGRAM_H

#include <string>
#include "glad/glad.h"
#include "../utils/Vector2D.h"
#include "../utils/Vector3D.h"

class ShaderProgram {
private:
    unsigned int programID;

    unsigned int vertexShaderID;
    unsigned int fragmentShaderID;

public:
    ShaderProgram(const char *vertexFile, const char *fragmentFile);

    void start() const;

    static void stop();

    void cleanUp() const;

private:
    static unsigned int loadShader(const char *filePath, unsigned int type);

    static std::string shaderReader(const std::string &filePath);

protected:
    virtual void getAllUniformLocations() {};

    int getUniformLocation(const char *uniformName) const;

    static void loadFloat(const int location, const float value) {
        glUniform1f(location, value);
    }

    static void loadInt(const int location, const int value) {
        glUniform1i(location, value);
    }

    static void load2DVector(const int location, const Vector2D vector) {
        glUniform2f(location, vector.x, vector.y);
    }

    static void load3DVector(const int location, const Vector3D vector) {
        glUniform3f(location, vector.x, vector.y, vector.z);
    }

//    static void load4DVector(const int location, const Vector4D vector) {
//        glUniform4f(location, vector.x, vector.y, vector.z, vector.w);
//    }

    static void load4DVector(const int location, const Vector3D vector) {
        glUniform4f(location, vector.x, vector.y, vector.z, 1);
    }

    static void loadBoolean(const int location, const bool value) {
        float toLoad = 0;
        if (value) {
            toLoad = 1;
        }
        glUniform1f(location, toLoad);
    }

//    static void loadMatrix(const int location, const matrix) {
//        const float buffer[16] = {};
//        matrix.get(buffer);
//        glUniformMatrix4fv(location, false, buffer);
//    }
};


#endif //INC_2DSAND_SHADERPROGRAM_H
