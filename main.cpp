#include "libraries/src/my_init.h"

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

Light light;

void processInput(GLFWwindow* window);
int main(){
    //init
    MOGL mogl;
    GLFWwindow* win = mogl.init();
    //do not pass go
    if(win == nullptr)
        return -1;
    glEnable(GL_DEPTH_TEST);

    //vertices
    std::vector<float> plane = getVertices();
    std::vector<unsigned int> inds = getIndices();
    VBO vbo;
    vbo.Bind(plane.data(), vertSize());
    VAO vao;
    vao.Bind(vertSize(), 3, 0, sizeof(float));
    EBO ebo(inds);
    ebo.Bind();
    // vbo.Unbind();
    // vao.Unbind();
    // ebo.Unbind();

    //shaders
    Shader defaultShader("shaders/default.vert", "shaders/default.frag");
    defaultShader.Activate();
    //model
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    unsigned int modelLoc = glGetUniformLocation(defaultShader.id, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    //camera
    Camera cam = Camera(WIDTH, HEIGHT, glm::vec3(0.0f, 0.5f, 2.0f));

    //set up lighting
    // glm::vec3 lightDir = normalize(light.direction);
    float steppy = (float)getStepSize();
    steppy = 0.05f;
    unsigned int stepLoc = glGetUniformLocation(defaultShader.id, "step");
    glUniform1f(stepLoc, steppy);
    
    //main loop
    while(!glfwWindowShouldClose(win)){
        //do rendering
        glClearColor(0.1f, 0.63f, 0.81f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //calculate deltaTime
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        //process input
        processInput(win);
        cam.Inputs(win, deltaTime);
        cam.updateMatrix(45.0f, 0.1f, 100.0f);
        
        glUniform3f(glGetUniformLocation(defaultShader.id, "camPos"),
            cam.pos.x, cam.pos.y, cam.pos.z);
        cam.Matrix(defaultShader, "camMatrix");
        
        //send deltaTime so that GPU shader can calculate wave position
        unsigned int dT = glGetUniformLocation(defaultShader.id, "dT");
        glUniform1f(dT, currentFrame);
        
        vao.Bind(vertSize(), 5, 3, sizeof(float));
        ebo.Draw();
        defaultShader.Activate();

        //refresh window
        glfwSwapBuffers(win);
        glfwPollEvents();

    }
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if(glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    if(glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}