#pragma once
#include "includes.h"

class Window
{
public:
    GLFWwindow* window;
    void initWindow();
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};
