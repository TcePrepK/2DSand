//
// Created by Shrimp on 1/1/2022.
//

#include <iostream>
#include <filesystem>
#include <fstream>
#include <cstring>
#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(const char *vertexFile, const char *fragmentFile) {
    std::cout << "Creating a shader!" << std::endl;

    vertexShaderID = loadShader(vertexFile, GL_VERTEX_SHADER);
    fragmentShaderID = loadShader(fragmentFile, GL_FRAGMENT_SHADER);

    programID = glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    glLinkProgram(programID);
    glValidateProgram(programID);
    getAllUniformLocations();
}

void ShaderProgram::start() const {
    glUseProgram(programID);
}

void ShaderProgram::stop() {
    glUseProgram(0);
}

void ShaderProgram::cleanUp() const {
    stop();
    glDetachShader(programID, vertexShaderID);
    glDetachShader(programID, fragmentShaderID);
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
    glDeleteProgram(programID);
}

unsigned int ShaderProgram::loadShader(const char *filePath, const unsigned int type) {
    std::string start = "../";
    std::string strFilePath(filePath);
    std::string fixedFilePath = start + strFilePath;

    const std::string shaderSourceStr = shaderReader(fixedFilePath);
    const char *shaderSource = shaderSourceStr.c_str();

    const unsigned int shaderID = glCreateShader(type);
    glShaderSource(shaderID, 1, &shaderSource, nullptr);
    glCompileShader(shaderID);

    int result;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int logLength;
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logLength);

        char *infoLog = nullptr;
        glGetShaderInfoLog(shaderID, logLength, nullptr, infoLog);
        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment") << " Shader!"
                  << std::endl;
        std::cout << infoLog << std::endl;

        glDeleteShader(shaderID);
        return 0;
    }

    return shaderID;
}

std::string ShaderProgram::shaderReader(const std::string &filePath) {
    std::string content;
    std::ifstream fileStream(filePath, std::ios::in);

    if (!fileStream.is_open()) {
        std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
        return "";
    }

    std::string line;
    while (!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}

int ShaderProgram::getUniformLocation(const char *uniformName) const {
    return glGetUniformLocation(programID, uniformName);
}