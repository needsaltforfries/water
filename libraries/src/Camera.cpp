#include "Camera.h"

Camera::Camera(int width, int height, glm::vec3 position){
    Camera::width = width;
    Camera::height = height;
    this->pos = position;
}

void Camera::updateMatrix(float FOVdeg, float near, float far){
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);
    //look in direction and get view-projection
    view = glm::lookAt(pos, pos + orientation, Up);
    projection = glm::perspective(glm::radians(FOVdeg), (float)width/height, near, far);
    //updates matrix
    camMatrix = projection*view;
}

void Camera::Matrix(Shader& shader, const char* uniform){
    //export cam matrix
    glUniformMatrix4fv(glGetUniformLocation(shader.id, uniform), 1, 
        GL_FALSE, glm::value_ptr(camMatrix));
}

void Camera::Inputs(GLFWwindow* window, float dT){
    //WASD to move
    speed = dT * 2.5f;
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        pos += speed * orientation;
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        pos -= speed * glm::normalize(glm::cross(orientation, Up));
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        pos -= speed * orientation;
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        pos += speed * glm::normalize(glm::cross(orientation, Up));
}