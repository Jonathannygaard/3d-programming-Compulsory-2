#pragma once
#include "includes.h"
#include "Window.h"
#include "vertex.h"
#include "shader.h"
#include "Mesh.h"
#include "Camera.h"

class Render
{
public:
    Window *WindowInit;
    shader TheShader;
    Mesh mesh;
    Camera camera;

    float rotation = 0.0f;
    float deltaTime = 0.0f;
    
    void initTick(Window* initptr);
    void processInput(GLFWwindow *window);
    void ticking();
    
};
