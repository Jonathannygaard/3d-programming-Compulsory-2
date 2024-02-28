#pragma once
#include <vector>
#include "vertex.h"
#include "includes.h"
class shader;

class Mesh
{
public:
    std::vector<vertex> vertices;
    std::vector<unsigned int> indices;

    unsigned int VBO, VAO, EBO;

    int modelLoc;

    glm::mat4 model;

    void creatignVertices(glm::vec3 setposition);
    void drawMesh(shader* shader);
    void initMesh(shader* Shader);
    glm::mat4 getModelMatrix(float rotation);
    glm::vec3 position;
    
};
