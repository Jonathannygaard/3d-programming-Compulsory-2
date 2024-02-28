#include "Mesh.h"
#include <windows.h>
#include "shader.h"
#include "glm/gtx/transform.hpp"

void Mesh::creatignVertices(glm::vec3 setposition, std::string name)
{
    position = setposition;
    if(name == "House")
    {
        vertices.emplace_back(-0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f); //Front Top Left 0
        vertices.emplace_back(0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f); //Front Top Right 1
        vertices.emplace_back(0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f); //Front Bottom Right 2
        vertices.emplace_back(-0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f); //Front Bottom Left 3
        vertices.emplace_back(-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f); //Back Top Left 4
        vertices.emplace_back(0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f); //Back Top Right 5
        vertices.emplace_back(0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f);//Back Bottom Right 6
        vertices.emplace_back(-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f);//Back Bottom Left 7
        //Front Side
        indices.emplace_back(0);
        indices.emplace_back(2);
        indices.emplace_back(1);
    
        indices.emplace_back(2);
        indices.emplace_back(0);
        indices.emplace_back(3);

        //Right Side
        indices.emplace_back(1);
        indices.emplace_back(2);
        indices.emplace_back(6);

        indices.emplace_back(6);
        indices.emplace_back(5);
        indices.emplace_back(1);

        //Left Side
        indices.emplace_back(0);
        indices.emplace_back(7);
        indices.emplace_back(4);

        indices.emplace_back(7);
        indices.emplace_back(0);
        indices.emplace_back(3);

        //Back Side
        indices.emplace_back(4);
        indices.emplace_back(6);
        indices.emplace_back(5);

        indices.emplace_back(6);
        indices.emplace_back(4);
        indices.emplace_back(7);

        //Bottom Side
        indices.emplace_back(3);
        indices.emplace_back(6);
        indices.emplace_back(2);

        indices.emplace_back(6);
        indices.emplace_back(3);
        indices.emplace_back(7);

        //Top Side
        indices.emplace_back(0);
        indices.emplace_back(5);
        indices.emplace_back(4);

        indices.emplace_back(5);
        indices.emplace_back(0);
        indices.emplace_back(1);
    }
    if(name == "Ground")
    {
        vertices.emplace_back(10.f,0.f,10.f, 0.0f, 1.0f, 0.0f);
        vertices.emplace_back(10.f,0.f,-10.f, 0.0f, 1.0f, 0.0f);
        vertices.emplace_back(-10.f,0.f,-10.f, 0.0f, 1.0f, 0.0f);
        vertices.emplace_back(-10.f,0.f,10.f, 0.0f, 1.0f, 0.0f);

        indices.emplace_back(3);
        indices.emplace_back(2);
        indices.emplace_back(1);

        indices.emplace_back(1);
        indices.emplace_back(0);
        indices.emplace_back(3);
        
    }
}

void Mesh::drawMesh(shader* shader)
{
    glBindVertexArray(VAO);

    glDrawElements(GL_TRIANGLES,indices.size(), GL_UNSIGNED_INT, 0);
}

void Mesh::initMesh(shader* Shader)
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
   
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertex), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 1);
    glBindVertexArray(1);

    modelLoc = glGetUniformLocation(Shader->shaderProgram, "model");
}

glm::mat4 Mesh::getModelMatrix(float rotation)
{
    if(bRotate == true)
    {
        return glm::rotate( glm::translate(glm::mat4(1.f), glm::vec3(0.0f, 0.0f, 0.0f)),
            glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f)) *
                glm::rotate( glm::mat4(1.f),glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));
    }
    return glm::translate(glm::mat4(1.f),glm::vec3(0.0f,0.0f, 0.0f));

}
