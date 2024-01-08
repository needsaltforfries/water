#pragma once

#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

class MOGL{
    public:
        MOGL();
        GLFWwindow* init();
};