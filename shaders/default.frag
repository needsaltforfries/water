#version 330 core

out vec4 FragColor;
in vec4 myColor;
in vec3 pos;
in vec3 norm;

uniform vec3 camPos;
uniform mat4 camMatrix;

void main(){
    vec3 amb = vec3(0.1, 0.1, 0.2);
    vec3 objCol = vec3(0.3, 0.3, 0.8);
    vec3 lightCol = vec3(0.63, 0.69, 0.83);
    vec3 lightPos = vec3(100.0, 100.0, 0.0);
    
    vec3 normal = normalize(norm);
    vec3 lightDir = (camMatrix*vec4(normalize(lightPos - pos),1.0)).xyz;

    //diff
    float d = max(dot(normal, lightDir), 0.0);
    vec3 diff = d*lightCol;

    //spec
    vec3 viewDir = normalize(camPos - pos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float shininess = 32.0;
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    vec3 specular = spec * lightCol; 

    vec3 col = vec3(amb + diff + specular);

    FragColor = vec4(col, 1.0);
}