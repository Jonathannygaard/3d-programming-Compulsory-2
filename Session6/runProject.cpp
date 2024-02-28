#include "runProject.h"

void runProject::initRunningProject()
{
    //initializing window and tick
    init.initWindow();
    render.initTick(&init);
}

void runProject::runningProject()
{
    //Running tick
    render.ticking();

    //Terminating glfw
    glfwTerminate();
}
