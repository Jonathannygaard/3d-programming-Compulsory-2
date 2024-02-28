#include "shader.h"
#include "includes.h"

std::string shader::readFile(const std::string& filename)
{
    std::ifstream file(filename);
    std::stringstream filestream;
    filestream << file.rdbuf();
    file.close();
    return filestream.str();
}

void shader::ReadShader()
{
    GLuint vertexshader;
    vertexshader = glCreateShader(GL_VERTEX_SHADER);

    //Read the vertex shader from the file
    std::string vertexShaderSourceString = readFile("Vertexshadersource.vert");
    const char* vertexShaderSource = vertexShaderSourceString.c_str();

    glShaderSource(vertexshader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexshader);

    int  success;
    char infoLog[512];
    glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(vertexshader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    GLuint fragmentshader;
    fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);

    //Read the fragment shader from the file    
    std::string fragmentshadersourcestring = readFile("Fragmentshadersource.frag");
    const char* fragmentshadersource = fragmentshadersourcestring.c_str();
    
    glShaderSource(fragmentshader, 1, &fragmentshadersource, NULL);
    glCompileShader(fragmentshader);

    int  successfrag;
    char infoLogfrag[512];
    glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &successfrag);

    if(!successfrag)
    {
        glGetShaderInfoLog(fragmentshader, 512, NULL, infoLogfrag);
        std::cout << "ERROR::SHADER::frag::COMPILATION_FAILED\n" << infoLogfrag << std::endl;
    }
    
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram,vertexshader );
    glAttachShader(shaderProgram,fragmentshader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    }

    glUseProgram(shaderProgram);

    glDeleteShader(vertexshader);
    glDeleteShader(fragmentshader);
}
