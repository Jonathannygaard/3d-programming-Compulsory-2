#pragma once
#include "includes.h"
#include "shader.h"

class Camera
{
public:
    float cameraSpeed = 0.005f;
    
    glm::vec3 cameraPos = glm::vec3 (0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3 (0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3 (0.0f, 1.0f, 0.0f);

    int viewLoc;
    int projectionLoc;
    
    void initCamera(shader* Shader);

    glm::mat4 view;
    glm::mat4 projection;
    
    glm::mat4 getView();
    glm::mat4 getProjection(float width, float height);

    void updatePos(glm::vec3 newpos);
};
