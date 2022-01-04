cmake_minimum_required(VERSION 3.21)

project(2DSand CXX C)
set(CMAKE_CXX_STANDARD 14)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_executable(2DSand
        Main.cpp
        src/utils/GlobalVariables.cpp src/utils/Vector2D.cpp
        src/utils/Vector3D.cpp src/core/TextureManager.cpp
        src/display/DisplayManager.cpp src/elements/Element.cpp
        src/elements/ElementRegistry.cpp src/core/ShaderProgram.cpp
        src/display/DisplayShader.cpp src/display/DisplayRenderer.cpp
        src/utils/Rectangle.cpp src/world/World.cpp
        src/world/Chunk.cpp src/elements/liquids/Water.h src/elements/liquids/Liquid.h)

add_subdirectory(depends/GLFW)
target_link_libraries(2DSand glfw)

include_directories(depends/glad/include)
add_library(glad STATIC depends/glad/src/glad.c)
target_link_libraries(2DSand glad)

find_package(OpenGL REQUIRED)
target_link_libraries(2DSand OpenGL::GL)