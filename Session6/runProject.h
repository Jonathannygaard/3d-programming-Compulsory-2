#pragma once
#include "Window.h"
#include "includes.h"
#include "Render.h"

class runProject
{
public:
    Window init;
    Render render;
    Mesh mesh;
    shader shader;

    void initRunningProject();

    void runningProject();
};
