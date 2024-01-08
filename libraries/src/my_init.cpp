#include "my_init.h"

//constants
const int WIDTH = 800;
const int HEIGHT = 600;

MOGL::MOGL(){ 
}

GLFWwindow* MOGL::init(){
    //init opengl version 3.3
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //create window
    void* win = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL", NULL, NULL);
    //GLFWwindow* win = glfwCreateWindow(WIDTH, HEIGHT, "Project", NULL, NULL);
    if(win == NULL){
        std::cout << "can't make window" << std::endl;
        glfwTerminate();
        return nullptr;
    }
    glfwMakeContextCurrent((GLFWwindow*)win); 
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return nullptr;
    }
    return (GLFWwindow*)win;
}