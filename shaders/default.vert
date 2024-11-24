#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 myColor;

uniform mat4 model;
uniform mat4 camMatrix;
uniform float dT;

void main(){
    float x = aPos.x;
    float y = aPos.y;
    float z = aPos.z;
    float wH = (sin((dT+x+z)) + cos(dT+z) + sin(.5*dT+3*x))/5.0;
    gl_Position = camMatrix * vec4(x, wH, z, 1.0);
    myColor = aColor;
}
