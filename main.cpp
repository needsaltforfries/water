#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <cmath>
#include "libraries/src/my_init.h"
#include "libraries/src/vertices.h"
#include "libraries/src/VBO.h"
#include "libraries/src/VAO.h"
#include "libraries/src/EBO.h"
#include "libraries/src/Shader.h"
#include "libraries/src/texture.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);

glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f); 

float deltaTime = 0.0f;
float lastFrame = 0.0f;

bool displayWF = false;

void processInput(GLFWwindow* window);
int main(){
    //do init
    MOGL mogl;
    GLFWwindow* win = mogl.init();

    if(win == nullptr)
        return -1;

    //vertices
    float* plane = getVertices();
    VBO vbo;
    vbo.Bind(plane, vertSize());

    Shader vert("shaders/default.vert", 1);
    //Shader geom("shaders/default.geom", 2);
    Shader frag("shaders/default.frag", 0);
    GLuint sp = Shader::linkShaders();

    //Texture t("zzk.jpg");
    //t.Bind();
    
    VAO vao;
    vao.Bind(vertSize(), 5, 3, sizeof(float));

    EBO ebo;
    ebo.Bind();

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    glm::mat4 view = glm::mat4(1.0f);
    //view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f));
        
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), 800.0f/600.0f, 0.1f, 100.0f);

    int modelLoc = glGetUniformLocation(sp, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    int viewLoc = glGetUniformLocation(sp, "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    int projLoc = glGetUniformLocation(sp, "projection");
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
    glEnable(GL_DEPTH_TEST);
                    
    //main loop
    while(!glfwWindowShouldClose(win)){
        //process input
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        processInput(win);

        //do rendering
        glClearColor(0.9f, 0.5f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        //update color
        float dT = glfwGetTime();
        float val = (sin(dT)/4.0f) + 0.7f;

        
        makeWave(dT);

        //const float radius = 5.0f;
        //float camX = sin(glfwGetTime()) * radius;
        //float camZ = cos(glfwGetTime()) * radius;
        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

        //make a transform and send it to the shader
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(1.0, 0.0, 0.0));
        // trans = glm::rotate(trans, glm::radians(3 * dT * 25.0f), glm::vec3(0.0, 1.0, 0.0));
        // trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
        // trans = glm::translate(trans, glm::vec3(0.0f, 0.0f, 0.0f));

        unsigned int transformLoc = glGetUniformLocation(sp, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

        //vertex position
        unsigned int waveHeight = glGetUniformLocation(sp, "waveHeight");
        glUniform4f(waveHeight, 1.0, val, 1.0, 1.0);

        //frag color
        int VCL = glGetUniformLocation(sp, "delta");
        glUniform4f(VCL, 0.0f, 0.0, 1.0, 1.0f);
        glUseProgram(sp);
        
        
        vbo.Bind(plane, vertSize());
        //vao.Bind(vertSize(), 5, 3, sizeof(float));
        //ebo.Bind();
        //vao.Draw(vertSize());
        ebo.Draw();
        //refresh window
        glfwSwapBuffers(win);
        glfwPollEvents();

    }
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window){
    float cameraSpeed = deltaTime * 2.5f;
    //WASD to move
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS){
        if(displayWF)
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        else
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        displayWF = !displayWF;
    }
}