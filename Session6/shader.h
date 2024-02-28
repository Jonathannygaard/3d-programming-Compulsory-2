#pragma once
#include "Mesh.h"
#include "vertex.h"
#include "Window.h"

class shader
{
public:
    GLuint shaderProgram;
    
    std::string readFile(const std::string& filename);
    void ReadShader();
};
