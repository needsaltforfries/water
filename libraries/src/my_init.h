#pragma once

#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <cmath>

#include "vertices.h"
#include "VBO.h"
#include "VAO.h"
#include "EBO.h"
#include "Shader.h"
#include "texture.h"
#include "Light.h"
#include "Camera.h"
class MOGL{
    public:
        MOGL();
        GLFWwindow* init();
};