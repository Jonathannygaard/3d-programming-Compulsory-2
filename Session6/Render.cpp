#include "render.h"
#include "glm/gtc/type_ptr.hpp"

void Render::initTick(Window* initptr)
{
    WindowInit = initptr;
    TheShader.ReadShader();
    House.creatignVertices(glm::vec3(0,0,0), "House");
    House.initMesh(&TheShader);
    Ground.creatignVertices(glm::vec3(0,0,0 ), "Ground");
    Ground.initMesh(&TheShader);
    camera.initCamera(&TheShader);
}

void Render::processInput(GLFWwindow* window)
{
    if(glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if(glfwGetKey(window,GLFW_KEY_W) == GLFW_PRESS)
        camera.updatePos(glm::vec3(0.f, 0.f, -5.f*deltaTime));
    if(glfwGetKey(window,GLFW_KEY_S) == GLFW_PRESS)
        camera.updatePos(glm::vec3(0.f, 0.f, 5.f*deltaTime));
    if(glfwGetKey(window,GLFW_KEY_A) == GLFW_PRESS)
        camera.updatePos(glm::vec3(-5.f*deltaTime, 0.f, 0.f));
    if(glfwGetKey(window,GLFW_KEY_D) == GLFW_PRESS)
        camera.updatePos(glm::vec3(5.f*deltaTime, 0.f, 0.f));
}
void Render::ticking()
{
    float firstFrame = 0.0f;
    glEnable(GL_DEPTH_TEST);
    while(!glfwWindowShouldClose(WindowInit->window))
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - firstFrame;
        firstFrame = currentFrame;
        //input
        processInput(WindowInit->window);

        rotation += 0.01f;
        House.bRotate = false;
        
        //Camera
        camera.view = camera.getView();
        camera.projection = camera.getProjection(800, 600);
        House.model = House.getModelMatrix(rotation);
        Ground.model = Ground.getModelMatrix(0);
        glUniformMatrix4fv(House.modelLoc, 1, GL_FALSE, glm::value_ptr(House.model));
        glUniformMatrix4fv(Ground.modelLoc, 1, GL_FALSE, glm::value_ptr(Ground.model));
        glUniformMatrix4fv(camera.viewLoc, 1, GL_FALSE, glm::value_ptr(camera.view));
        glUniformMatrix4fv(camera.projectionLoc, 1, GL_FALSE, glm::value_ptr(camera.projection));
        

        //rendering commands
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

        glUseProgram(TheShader.shaderProgram);
        House.drawMesh(&TheShader);
        Ground.drawMesh(&TheShader);

        //check and call events and swap the buffers
        glfwSwapBuffers(WindowInit->window);
        glfwPollEvents();
    }
}
