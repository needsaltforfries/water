#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <glad/glad.h>

static std::vector<unsigned int> shaders;

const GLuint types[] = {
    GL_FRAGMENT_SHADER,
    GL_VERTEX_SHADER,
    GL_GEOMETRY_SHADER
};
class Shader{
    public:
        Shader(std::string shaderFile, int type);
        std::string loadShader(std::string file);
        static GLuint linkShaders();
        unsigned int getId();
    private:
        unsigned int id;
};