#include "Shader.h"

static GLuint shaderProgram;

Shader::Shader(std::string path, int type){
    //get the type of shader
    GLuint sType = types[type];
    //get the shader code
    std::string shaderSource = loadShader(path);
    const GLchar* src = shaderSource.c_str();
    id = glCreateShader(sType);
    glShaderSource(id, 1, &src, NULL);
    glCompileShader(id);
    //check if successful
    int success;
    char infoLog[512];
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(id, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" <<
        infoLog << std::endl;
    }
    //add to list of shaders
    shaders.push_back(id);
}

//read shader from shader file
std::string Shader::loadShader(std::string shader){
    std::string shaderSrc;
    std::string line;
    std::ifstream in(shader);
    if(!in.is_open())
        throw(errno);
    while(getline(in, line)){
        shaderSrc += line + '\n';
    }
    std::cout << "loaded shader " << shader << "." << std::endl;
    return shaderSrc;
}

GLuint Shader::linkShaders(){
    shaderProgram = glCreateProgram();
    std::cout << "linking " << shaders.size() << " shaders." << std::endl;
    for(unsigned int id : shaders){
        glAttachShader(shaderProgram, id);
    }
    glLinkProgram(shaderProgram);
    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" <<
        infoLog << std::endl;
    }
    glUseProgram(shaderProgram);
    for(unsigned int id : shaders){
         glDeleteShader(id);
    }
    return shaderProgram;
}

unsigned int Shader::getId(){
    return id;
}