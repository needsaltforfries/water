#version 330 core

out vec4 FragColor;
in vec3 myColor;

uniform vec3 objCol;
uniform vec3 lightCol;
uniform vec3 camPos;

void main(){
    FragColor = vec4(objCol*lightCol, 1.0f);
}